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

static int DFG_INST_DEF[8][4] = {
  {0, -1, -1, 0}, // OTHER
  {0, -1, -1, 0}, // ARG
  {0,  0, -1, 0}, // LOAD
  {1,  0,  1, 0}, // STORE
  {0, -1, -1, 0}, // CALL
  {1,  0, -1, 0}, // RET
  {0, -1, -1, 1}, // ALLOCA
  {0,  0, -1, 0}, // CAST
};

#define is_void_return(n) (DFG_INST_DEF[(int)(n).type][0] == 1)
#define get_src1_index(n) (DFG_INST_DEF[(int)(n).type][1])
#define get_dst1_index(n) (DFG_INST_DEF[(int)(n).type][2])
#define is_ignore_type(n) (DFG_INST_DEF[(int)(n).type][3] == 1)
#define is_nolink_node(n) ((n).depend_indexs.empty() && (n).ref_count == 0)

static void _copy(const InstNode& A, InstNode& B){
    B.index     = A.index;
    B.inst      = A.inst;
    B.block     = A.block;
    B.name      = A.name;
    B.type      = A.type;
    B.ref_count = A.ref_count;
    B.depend_indexs.clear();
    std::copy(A.depend_indexs.begin(), A.depend_indexs.end(), std::back_inserter(B.depend_indexs));
}

static void _move(InstNode& A, InstNode& B){
    B.index     = A.index;
    B.inst      = A.inst;
    B.block     = A.block;
    B.name      = A.name;
    B.type      = A.type;
    B.ref_count = A.ref_count;
    B.depend_indexs = std::move(A.depend_indexs);
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
  case Instruction::Store     : return STORE; 
  case Instruction::Call      : return CALL;  
  case Instruction::Load      : return LOAD;
  case Instruction::Ret       : return RET;
  case Instruction::Alloca    : return ALLOCA;
  case Instruction::BitCast   :
  case Instruction::PtrToInt  : return CAST;
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
    node.name = get_value_name(arg);
    nodes.push_back(std::move(node));
  }
  return nodes;
}

static std::vector<InstNode> _build_inst_nodes(Function* F){
  std::vector<InstNode> nodes;
  for(BasicBlock& B : *F){  
    for(Instruction& I : B){
      if(isa<CallInst>(I)){
        CallInst* CI = dyn_cast<CallInst>(&I);
        std::string callFuncName = CI->getCalledFunction()->getName().str();
        if(is_llvm_instrinsics(callFuncName)){
          continue;
        }        
      }

      InstNode node;
      node.inst   = &I;
      node.block  = &B;
      node.type   = get_inst_type(&I);
      if (!is_void_return(node)) {
        node.name = get_value_name(&I);
      }
      else{
        node.name = "";
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

    // call inst
    if(node.type == CALL)
    {
      CallInst* CI = dyn_cast<CallInst>(node.inst);
      assert(CI);

      unsigned int num_operands = CI->getNumOperands() - 1;
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
        std::string dst_var = node.name;
        HPC_TRACE4("Update latest_index_map: var=", dst_var, ", index=", node.index);
        latest_index_map[dst_var] = node.index;
      }
    }
    // other inst
    else
    {
      if( !is_void_return(node)){
        HPC_TRACE4("Update latest_index_map: var=\"", node.name, "\", index=", node.index);
        latest_index_map[node.name] = node.index;
      }

      int src1_index = get_src1_index(node);
      HPC_TRACE2("src1_index=", src1_index);
      if(src1_index != -1){
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

      int dst1_index = get_dst1_index(node);
      HPC_TRACE2("dst1_index=", dst1_index);
      if(dst1_index != -1){
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
  int index = 0;

    HPC_TRACE1("Build argument nodes:");
    for(InstNode& node: _build_arg_nodes(F)){
      node.index  = index++;
      HPC_TRACE2("New arg node: ", hpcc::to_string(node));
      node_name_map[node.name] = node.index;
      node_list.push_back(std::move(node));
    }
    
    HPC_TRACE1("Build instruction nodes:");
    for(InstNode& node: _build_inst_nodes(F)){
      node.index  = index++;
      HPC_TRACE4("New inst node: ", hpcc::to_string(node), ", inst=", *(node.inst));
      if(!node.name.empty())
        node_name_map[node.name] = node.index;
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

  std::vector<std::string> dot_output_graph();

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

static std::string _dot_output_node_name(InstNode& node){
  char tmp[20] = {0};
  sprintf(tmp, "node_%04d", node.index);
  return std::string(tmp);
}

static std::string _dot_node_shape(InstNode& node){
  switch (node.type)
  {
    case ARG: return "ellipse";
    case RET: return "ellipse";
    default:  return "record";
  }
}

static std::string _dot_node_label(InstNode& node){
  std::string line = std::to_string(node.index) + ":";
  if(node.type != ARG){
    line += get_inst_name(node.inst);
  }
  else{
    line += " argument " + node.name;
  }
  return line;
}

static std::string _dot_node_color(InstNode& node){

  if(is_nolink_node(node) && !is_ignore_type(node))
    return "red";
  return "";
}

#define DOT_NODE_NAME_NOLINK "no_link"

static std::string _dot_output_node_nolinkhead(){
  std::string line = DOT_NODE_NAME_NOLINK;
  line += "[";
  line += "shape=ellipse";
  line += ", label=\"NO-LINK-NOTES\"";
  line += ", color=red";
  line += "]";
  return line;
}

static std::string _dot_output_node(InstNode& node){

  std::string line = _dot_output_node_name(node);
  line += "[";
  line += "shape=" + _dot_node_shape(node);
  line += ", label=\"" + _dot_node_label(node) +"\"";
  std::string color = _dot_node_color(node);
  if(color != ""){
    line += ", color=" + color;
  }
  line += "]";
  return line;
}

static std::string _dot_output_edge(const std::string& from_name, InstNode& to_node){
  auto to_name = _dot_output_node_name(to_node);
  std::string line = from_name;
  line += " -> ";
  line += to_name;
  return line;
}

std::vector<std::string> DFGUtilImpl::dot_output_graph(){
  std::vector<std::string> lines;
  
  // output digraph begin
  {
    std::string line = "digraph \"DFG for \'";
    line += F->getName().str(); // function name
    line += "\' function\" {";
    lines.push_back(line);
  }

  std::vector<int> nolink_indexs;
  
  // output nodes
  for(InstNode& node : node_list){
    if(is_nolink_node(node)){
      if(is_ignore_type(node)){
        continue;
      }
      nolink_indexs.push_back(node.index);
    }
    lines.push_back("\t"+_dot_output_node(node));    
  }

  // output no-link nodes
  if(!nolink_indexs.empty())
  {
    lines.push_back(_dot_output_node_nolinkhead());
    std::string from_name = DOT_NODE_NAME_NOLINK;
    for(int nolink_index: nolink_indexs){
      lines.push_back("\t"+_dot_output_edge(from_name, node_list[nolink_index]));
      from_name = _dot_output_node_name(node_list[nolink_index]);
    }
  }

  // output edge
  for(InstNode& node : node_list){
    auto from_name = _dot_output_node_name(node);   
    if(!node.depend_indexs.empty()){
      for(int to_index : node.depend_indexs){
        lines.push_back("\t"+_dot_output_edge(from_name, node_list[to_index]));
      }
    }
  }

  // output digraph end
  lines.push_back("}");
  return lines;
}

void DFGUtil::output_dot(const std::string& path)
{
  std::vector<std::string> lines =  impl->dot_output_graph();
  std::ofstream out_file(path);
  if (!out_file.is_open()) {
    llvm::report_fatal_error("unable to open file");
  }

  for(std::string& line : lines){
     out_file << line << "\n";
  }

  out_file.close(); 
}

bool DFGUtil::is_empty_function(){
  return impl->inst_index_map.empty();
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

  out += ", name=";
  out += N->name;

  out += ", ref=";
  out += std::to_string(N->ref_count);

  out += ", depend=";
  out += hpcc::to_string(N->depend_indexs);

  out += ")";

  return out;
}



}//namespace hpcc 