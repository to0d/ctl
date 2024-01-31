#ifndef HPCC_DFG_UTIL_H
#define HPCC_DFG_UTIL_H

#include "help.h"
#include "llvm/IR/Instructions.h"

namespace hpcc{

enum NodeType{OTHER = 0, ARG, LOAD, STORE, CALL, RET, ALLOCA, CAST, MOP, IGNORE};

struct InstNode
{
  int                       index;
  llvm::Instruction*        inst;
  llvm::BasicBlock*         block;
  std::string               var_name;
  std::string               inst_name;
  std::string               call_name;
  NodeType                  type;
  std::vector<int>          depend_indexs;
  std::vector<std::string>  operand_list;
  int                       ref_count;

  InstNode();
  InstNode(const InstNode& N);
  InstNode(InstNode&& N);

  InstNode& operator=(const InstNode &N);
  InstNode& operator=(InstNode &&N);
};

HPCC_TO_STRING_DEF(InstNode);

class DFGUtilImpl;
class DFGUtil{
public:
  DFGUtil(llvm::Function* F);
  ~DFGUtil();
  std::vector<std::string> list_all_vars();
  const std::vector<InstNode>& get_node_list();
  void output_dot(const std::string& path);
  static bool is_empty_function(llvm::Function* F);

private:
  class DFGUtilImpl* impl;
};

}//namespace hpcc

TRACE_SUB_MODULE_DEF(dfg_util)

#endif // HPCC_DFG_UTIL_H

