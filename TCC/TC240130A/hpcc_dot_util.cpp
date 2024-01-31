#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"
#include "help.h"
#include "hpcc_dot_util.h"
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace llvm;

namespace hpcc{

#define DOT_NODE_NAME_NOLINK "no_link"

enum DotStyle{
  NONE, DEP, CFG, NOLINK
};

#define is_nolink_node(n)  ((n).depend_indexs.empty() && (n).ref_count == 0)

class DotUtilImpl{
public:
  DotUtilImpl(Function* F, const std::vector<InstNode>& node_list);

  std::vector<std::string> output_graph();
  std::string output_node_line(const InstNode& node);
  std::string output_node_name(const InstNode& node);
  std::string output_node_shape(const InstNode& node);
  std::string output_node_label(const InstNode& node);
  std::string output_node_color(const InstNode& node);
  std::string output_node_name_nolinkhead();
  std::string output_edge(const std::string& from_name, const InstNode& to_node, DotStyle style);


  std::vector<InstNode> m_node_list;
  std::vector<std::string> m_node_name_list;
  std::string m_graph_name;
  int         m_node_size;
};

DotUtilImpl::DotUtilImpl(Function* F, const std::vector<InstNode>& node_list){
  m_graph_name = F->getName().str();
  std::copy(node_list.begin(), node_list.end(), std::back_inserter(m_node_list));

  m_node_size = node_list.size();
  m_node_name_list.resize(m_node_size);
}

std::vector<std::string> DotUtilImpl::output_graph(){
  std::vector<std::string> lines;
  
  // output digraph begin
  {
    std::string line = "digraph \"DFG for \'";
    line += m_graph_name; // function name
    line += "\' function\" {";
    lines.push_back(line);
  }


  std::vector<int> call_indexs;
  
  // output nodes
  for(const InstNode& node : m_node_list){
    if(is_nolink_node(node) && node.type != CALL){
      HPC_TRACE2("[Dot]: ignore node: ", hpcc::to_string(node));
      continue;
    }
    if(node.type == CALL)
      call_indexs.push_back(node.index);
    lines.push_back("\t"+output_node_line(node));    
  }

  // output edges
  for(const InstNode& node : m_node_list){
    auto from_name = output_node_name(node);   
    if(!node.depend_indexs.empty()){
      for(int to_index : node.depend_indexs){
        lines.push_back("\t"+output_edge(from_name, m_node_list[to_index], DEP));
      }
    }
  }

  // output call node dfg edges
  if(call_indexs.size() > 1){
    std::string from_name = ""; 
    for(int call_index : call_indexs){
      if(!from_name.empty()){
        lines.push_back("\t"+output_edge(from_name, m_node_list[call_index], CFG));
      }
      from_name = output_node_name(m_node_list[call_index]);
    }
  }

  // output digraph end
  lines.push_back("}");
  return lines;
}

std::string DotUtilImpl::output_node_name(const InstNode& node){
  std::string node_name = m_node_name_list[node.index];
  if(node_name.empty()){
    char tmp[20] = {0};
    sprintf(tmp, "node_%04d", node.index);
    node_name = std::string(tmp);
    m_node_name_list[node.index] = node_name;
  }
  return node_name;
}

std::string DotUtilImpl::output_node_shape(const InstNode& node){
  switch (node.type)
  {
    case ARG: return "ellipse";
    case RET: return "ellipse";
    default:  return "record";
  }
}

std::string DotUtilImpl::output_node_label(const InstNode& node){
  
  switch (node.type)
  {
  case ARG    : return node.var_name +": arg";
  case RET    : return "ret " + node.var_name;
  case ALLOCA : return node.var_name + ": " + node.inst_name;
  case STORE  : return "store("+get_value_name(node.inst->getOperand(0))
                           +","+get_value_name(node.inst->getOperand(1))+")";
  
  case CALL   :  {

    std::string line = "call ";

    CallInst* CI = dyn_cast<CallInst>(node.inst);
    assert(CI);

    std::string callFuncName = CI->getCalledFunction()->getName().str();
    callFuncName = demangle_func_name(callFuncName);
    line += callFuncName + "(";

    unsigned int num_operands = CI->getNumOperands() - 1;
    for(unsigned int r = 0; r < num_operands; r++){
      Value* opd = CI->getArgOperand(r);
      if(r != 0)
        line += ",";
      line += get_value_name(opd);
    }
    line += ")";

    if(node.var_name != ""){
      line = node.var_name + ": " + line;
    }
    return line;
  }  

  case LOAD: 
  case CAST:
  case MOP:
    {
      std::string line = node.var_name + ": " + node.inst_name + "(";
      int idx = 0;
      for(auto& opd : node.operand_list){
        if(idx++ != 0)
          line += ",";
        line += opd;
      }
      line += ")";

      return line;
    }

  // case OTHER  : 
  default: break;
  }

  return get_inst_name(node.inst);
}

std::string DotUtilImpl::output_node_color(const InstNode& node){
  if(is_nolink_node(node))
    return "red";
  return "";
}

std::string DotUtilImpl::output_node_name_nolinkhead(){
  std::string line = DOT_NODE_NAME_NOLINK;
  line += "[";
  line += "shape=ellipse";
  line += ", label=\"NO-LINK-NOTES\"";
  line += ", color=red";
  line += "]";
  return line;
}

std::string DotUtilImpl::output_node_line(const InstNode& node){

  std::string line = output_node_name(node);
  line += "[";
  line += "shape=" + output_node_shape(node);
  line += ", label=\"" + output_node_label(node) +"\"";
  std::string color = output_node_color(node);
  if(color != ""){
    line += ", color=" + color;
  }
  line += "]";
  return line;
}


std::string DotUtilImpl::output_edge(const std::string& from_name, const InstNode& to_node, DotStyle style){
  auto to_name = output_node_name(to_node);
  std::string line = from_name;
  line += " -> ";
  line += to_name;

  switch (style)
  {
  case CFG:
    line += " [color=red]";
    break;
  
  default:
    break;
  }

  return line;
}

DotUtil::DotUtil(Function* F, const std::vector<InstNode>& node_list){
  impl = new DotUtilImpl(F, node_list);
}

DotUtil::~DotUtil(){
  delete impl;
}

void DotUtil::output_dot(const std::string& path){

  std::vector<std::string> lines = impl->output_graph();
  std::ofstream out_file(path);
  if (!out_file.is_open()) {
    llvm::report_fatal_error("unable to open file");
  }

  for(std::string& line : lines){
     out_file << line << "\n";
  }

  out_file.close(); 
}

std::string DotUtil::get_graph_name(){
  return impl->m_graph_name;
}

}//namespace hpcc 