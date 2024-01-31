#ifndef HPCC_DOT_UTIL_H
#define HPCC_DOT_UTIL_H

#include "help.h"
#include "hpcc_dfg_util.h"
#include "llvm/IR/Instructions.h"


namespace hpcc{

class DotUtil{
public:
  DotUtil(Function* F, const std::vector<InstNode>& node_list);
  ~DotUtil();
  
  void output_dot(const std::string& path);
  std::string get_graph_name();

private:
  class DotUtilImpl* impl;
};

}//namespace hpcc

TRACE_SUB_MODULE_DEF(dot_util)

#endif // HPCC_DOT_UTIL_H

