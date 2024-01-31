#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"
#include "help.h"
#include "hpcc_dfg_util.h"
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace llvm;

namespace hpcc{

static int DFG_INST_DEF[10][5] = {
  {0, -1, -1, 0, 0}, // OTHER
  {0, -1, -1, 0, 0}, // ARG
  {0,  0, -1, 0, 0}, // LOAD
  {1,  0,  1, 0, 0}, // STORE
  {0, -1, -1, 0, 0}, // CALL
  {1,  0, -1, 0, 0}, // RET
  {0, -1, -1, 1, 0}, // ALLOCA
  {0,  0, -1, 0, 0}, // CAST
  {0, -2,  0, 0, 0}, // MOP
  {0,  0,  0, 0, 0}, // IGNORE
};

#define is_void_return(n)  (DFG_INST_DEF[(int)(n).type][0] == 1)
#define get_src1_index(n)  (DFG_INST_DEF[(int)(n).type][1])
#define has_multi_input(n) (DFG_INST_DEF[(int)(n).type][1] == -2)
#define get_dst1_index(n)  (DFG_INST_DEF[(int)(n).type][2])
#define is_ignore_type(n)  (DFG_INST_DEF[(int)(n).type][3] == 1)

static void _copy(const InstNode& A, InstNode& B){
    B.index       = A.index;
    B.inst        = A.inst;
    B.block       = A.block;
    B.var_name    = A.var_name;
    B.inst_name   = A.inst_name;
    B.type        = A.type;
    B.ref_count   = A.ref_count;
    B.depend_indexs.clear();
    std::copy(A.depend_indexs.begin(), A.depend_indexs.end(), std::back_inserter(B.depend_indexs));
    std::copy(A.operand_list.begin(), A.operand_list.end(), std::back_inserter(B.operand_list));
}

static void _move(InstNode& A, InstNode& B){
    B.index       = A.index;
    B.inst        = A.inst;
    B.block       = A.block;
    B.var_name    = A.var_name;
    B.inst_name   = A.inst_name;
    B.type        = A.type;
    B.ref_count   = A.ref_count;
    B.depend_indexs = std::move(A.depend_indexs);
    B.operand_list = std::move(A.operand_list);
}

InstNode::InstNode(){
  index     = -1;
  inst      = NULL;
  block     = NULL;
  type      = OTHER;
  ref_count = 0;
}

InstNode::InstNode(const InstNode& N){
  _copy(N, *this);
}

InstNode::InstNode(InstNode && N){
  _move(N, *this);
}

InstNode& InstNode::operator=(const InstNode& N){
  _copy(N, *this);
  return *this;
}

InstNode& InstNode::operator=(InstNode&& N){
  _move(N, *this);
  return *this;
}

static NodeType get_inst_type(Instruction* I){
  assert(I);
  switch (I->getOpcode())
  {
  case Instruction::Store         : return STORE; 
  case Instruction::Call          : return CALL;  
  case Instruction::Load          : return LOAD;
  case Instruction::Ret           : return RET;
  case Instruction::Alloca        : return ALLOCA;
  case Instruction::BitCast       :
  case Instruction::PtrToInt      : return CAST;
  case Instruction::Add           :
  case Instruction::SDiv          :
  case Instruction::Mul           :
  case Instruction::ExtractValue  :
  case Instruction::GetElementPtr : return MOP;
  case Instruction::Br            : return IGNORE;
  default: break;
  }
  return OTHER;
}

static std::vector<InstNode> _build_arg_nodes(Function* F){
  std::vector<InstNode> nodes;
  int arg_size = F->arg_size();
  for(int i = 0; i < arg_size; ++i){
    Argument* arg = F->getArg(i);
    InstNode node;
    node.inst   = NULL;
    node.block  = NULL;
    node.type   = ARG;
    node.var_name = get_value_name(arg);
    node.inst_name = "argument";
    nodes.push_back(std::move(node));
  }
  return nodes;
}

static std::vector<InstNode> _build_inst_nodes(Function* F){
  std::vector<InstNode> nodes;
  for(BasicBlock& B : *F){  
    for(Instruction& I : B){
      NodeType type = get_inst_type(&I);
      if(type == IGNORE)
        continue;

      CallInst* CI = NULL; 
      if(isa<CallInst>(I)){
        CI = dyn_cast<CallInst>(&I);
        std::string callFuncName = CI->getCalledFunction()->getName().str();
        if(is_llvm_instrinsics(callFuncName)){
          continue;
        }        
      }

      InstNode node;
      node.inst   = &I;
      node.block  = &B;
      node.type   = type;
      node.inst_name = I.getOpcodeName();
      if (is_void_return(node) || (CI != NULL && CI->getType()->isVoidTy()) ) {
        node.var_name = "";
      }
      else{
        node.var_name = get_value_name(&I);
      }

      nodes.push_back(std::move(node));
    }
  }
  return nodes;
}

static void _build_depend_indexs(std::vector<InstNode>& nodes){
 
  std::map<std::string, int> latest_index_map;
  BasicBlock* last_block = NULL;

#define LATEST_NODE(var) \
  (latest_index_map.count((var)) == 0 ? \
      NULL : &(nodes[latest_index_map[(var)]]))

#define LINK_NODE(from_node, to_node)\
  if( (from_node) != NULL && (to_node != NULL)) {\
    HPC_TRACE4("LINK_NODE: from=", hpcc::to_string(from_node), ", to=",hpcc::to_string(to_node));\
    (to_node)->depend_indexs.push_back((from_node)->index);\
    (from_node)->ref_count++;\
  }

  for(InstNode& node : nodes){
    HPC_TRACE2("Scan node: ",hpcc::to_string(node));
    // @TODO how about if/loop?
    // if(last_block != node.block){
    //   HPC_TRACE1("New Block:");
    //   latest_index_map.clear();
    // }
    // last_block = node.block;

    unsigned int num_operands = node.inst == NULL ? 0 : node.inst->getNumOperands();
    if(node.type == RET && num_operands == 0){
      continue;
    }

    for(unsigned int r = 0; r < num_operands; r++){
      Value* opd = node.inst->getOperand(r);
      std::string opd_var = get_value_name(opd);
      node.operand_list.push_back(opd_var);
    }

    // call inst
    if(node.type == CALL)
    {
      CallInst* CI = dyn_cast<CallInst>(node.inst);
      assert(CI);

      num_operands--;
      for(unsigned int r = 0; r < num_operands; r++){
        Value* opd = CI->getArgOperand(r);
        std::string opd_var = get_value_name(opd);
        if(is_llvm_ir_var(opd_var)){
          InstNode* src_node = LATEST_NODE(opd_var);
          LINK_NODE(src_node, &node);
        }
      }

      // have return value
      if(!CI->getType()->isVoidTy())
      {
        std::string dst_var = node.var_name;
        HPC_TRACE4("Update latest_index_map: var=", dst_var, ", index=", node.index);
        latest_index_map[dst_var] = node.index;
      }
    }
    // other inst
    else
    {
      if( !is_void_return(node)){
        HPC_TRACE4("Update latest_index_map: var=\"", node.var_name, "\", index=", node.index);
        latest_index_map[node.var_name] = node.index;
      }

      if(has_multi_input(node)){
        for(unsigned int r = 0; r < num_operands; r++){
          Value* opd = node.inst->getOperand(r);
          std::string opd_var = get_value_name(opd);
          if(is_llvm_ir_var(opd_var)){
            InstNode* src_node = LATEST_NODE(opd_var);
            LINK_NODE(src_node, &node);
          }
        }
      }
      else {
        
        int src1_index = get_src1_index(node);
        HPC_TRACE2("src1_index=", src1_index);
        if(src1_index  >=0 && src1_index < num_operands){
          Value* src_val = node.inst->getOperand(src1_index);
          std::string src_var = get_value_name(src_val);
          // HPC_TRACE3("src_var=\"", src_var,"\"");
          if(is_llvm_ir_var(src_var)){
            InstNode* src_node = LATEST_NODE(src_var);
            // if(src_node != NULL)
            // {
            //   HPC_TRACE2("src_node=", src_node->index);
            // }
            // else
            //   {
            //     errs() << "not found\n";
            //     for(auto& it : latest_index_map)
            //        errs() << it.first << " " << it.second << "\n";
            //   }
            LINK_NODE(src_node, &node);
          }
        }
      }   

      int dst1_index = get_dst1_index(node);
      HPC_TRACE2("dst1_index=", dst1_index);
      if(dst1_index != -1 && dst1_index < num_operands){
        Value* dst_val = node.inst->getOperand(dst1_index);
        std::string dst_var = get_value_name(dst_val);
        HPC_TRACE4("Update latest_index_map: var=", dst_var, ", index=", node.index);
        latest_index_map[dst_var] = node.index;
      }
    } 
  }
}

class DFGUtilImpl{
  friend class DFGUtil;

  std::vector<InstNode>         node_list;
  std::map<std::string, int>    node_name_map;
  std::map<Instruction*, int>   inst_index_map;

  void scan_inst(){
    HPC_TRACE3("************** scan inst: ", F->getName().str() , "**************");
    int index = 0;    
    HPC_TRACE1("Build argument nodes:");
    for(InstNode& node: _build_arg_nodes(F)){
      node.index  = index++;
      HPC_TRACE2("New arg node: ", hpcc::to_string(node));
      node_name_map[node.var_name] = node.index;
      node_list.push_back(std::move(node));
    }
    
    HPC_TRACE1("Build instruction nodes:");
    for(InstNode& node: _build_inst_nodes(F)){
      node.index  = index++;
      HPC_TRACE4("New inst node: ", hpcc::to_string(node), ", inst=", *(node.inst));
      if(!node.var_name.empty())
        node_name_map[node.var_name] = node.index;
      inst_index_map[node.inst] = node.index;
      node_list.push_back(std::move(node));
    }

    HPC_TRACE1("Build depend_indexs:");
    _build_depend_indexs(node_list);

    HPC_TRACE1("Print all nodes:");
    for(InstNode& node : node_list){
      HPC_TRACE1(hpcc::to_string(node));
    }
  }

  std::vector<std::string> list_all_vars(){
    std::vector<std::string> vars;
    std::for_each(node_name_map.begin(), node_name_map.end(), [&vars](auto it){vars.push_back(it.first);});
    std::sort(vars.begin(), vars.end());
    return vars;
  }

private:
  Function* F;
};

DFGUtil::DFGUtil(Function* F){
  impl = new DFGUtilImpl();
  impl->F = F;
  impl->scan_inst();
}

DFGUtil::~DFGUtil(){
  delete impl;
}

std::vector<std::string> DFGUtil::list_all_vars(){
  return impl->list_all_vars();
}

bool DFGUtil::is_empty_function(Function* F){
  if(!F)
    return true;
  for(BasicBlock& B : *F){  
    for(Instruction& I : B){
      return false;
    }
  }
  return true;
}


const std::vector<InstNode>& DFGUtil::get_node_list(){
  return impl->node_list;
}

std::string to_string(NodeType type){
  switch (type)
  {
  case OTHER  : return "OTHER";
  case ARG    : return "ARG";
  case LOAD   : return "LOAD";
  case STORE  : return "STORE";
  case CALL   : return "CALL";     
  case RET    : return "RET";
  case ALLOCA : return "ALLOCA";
  case CAST   : return "CAST";
  case MOP    : return "MOP";
  default:      return "BAD";
  }
}

HPCC_TO_STRING_IMPL(InstNode, N){
  if( !N )
    return "Node(null)";

  std::string out = "Node(";

  out += "index=";
  out += hpcc::to_string(N->index);

  out += ", type=";
  out += hpcc::to_string(N->type);

  out += ", var_name=";
  out += N->var_name;

  out += ", inst_name=";
  out += N->inst_name;

  out += ", operand=";
  out += hpcc::to_string(N->operand_list);

  out += ", ref=";
  out += std::to_string(N->ref_count);

  out += ", depend=";
  out += hpcc::to_string(N->depend_indexs);

  out += ")";

  return out;
}



}//namespace hpcc 