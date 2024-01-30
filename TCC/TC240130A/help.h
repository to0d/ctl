#ifndef HPCC_MACRO_H
#define HPCC_MACRO_H

#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include <cxxabi.h>

using namespace llvm;

#define TRACE_SET_TRACE(xx) set_##xx##_trace
#define TRACE_GET_TRACE(xx) get_##xx##_trace

#define TRACE_SUB_MODULE_IMPL(xx) \
bool _##xx##_trace = false;\
void TRACE_SET_TRACE(xx)(bool trace){\
  _##xx##_trace = trace;\
}\
bool TRACE_GET_TRACE(xx)(){\
  return _##xx##_trace;\
}

#define TRACE_SUB_MODULE_DEF(xx) \
void TRACE_SET_TRACE(xx)(bool trace);\
bool TRACE_GET_TRACE(xx)();


#define HPCC_TO_STRING_DEF(XX)  \
std::string to_string(const XX&); \
std::string to_string(const XX*);

#define HPCC_TO_STRING_IMPL(XX, val) \
std::string to_string(const XX& val){ \
  return hpcc::to_string(&val); \
} \
std::string to_string(const XX* val)

#define HPC_TRACE1(x)  { errs() << "[debug] " << x << "\n"; }
#define HPC_TRACE2(x1, x2)  { errs() << "[debug] " << x1 << x2 << "\n"; }
#define HPC_TRACE3(x1, x2, x3)  { errs() << "[debug] " << x1 << x2 << x3 << "\n"; }
#define HPC_TRACE4(x1, x2, x3, x4)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << "\n"; }
#define HPC_TRACE5(x1, x2, x3, x4, x5)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << x5 << "\n"; }
#define HPC_TRACE6(x1, x2, x3, x4, x5, x6)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << x5 << x6 << "\n"; }
#define HPC_TRACE7(x1, x2, x3, x4, x5, x6, x7)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << "\n"; }
#define HPC_TRACE8(x1, x2, x3, x4, x5, x6, x7, x8)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << "\n"; }
#define HPC_TRACE9(x1, x2, x3, x4, x5, x6, x7, x8, x9)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << "\n"; }
#define HPC_TRACE10(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10)  { errs() << "[debug] " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << "\n"; }

namespace hpcc{

inline std::string get_value_name(llvm::Value* val) {
  std::string str;
  raw_string_ostream OS(str);
  val->printAsOperand(OS,false);
  return OS.str();
}

inline int get_llvm_ir_var_index(const std::string& name){
  std::string::size_type idx = name.find("%");
  if( idx == std::string::npos)
    return -1;

  std::string index_str = name.substr(idx+1, name.length());
  int num = std::stoi(index_str);
  return num;  
}

inline bool is_llvm_ir_var(const std::string& name){
  return get_llvm_ir_var_index(name) != -1;
}

static const std::string llvm_instrinsics_prefix= "llvm.";

inline bool is_llvm_instrinsics(const std::string& name){
  return name.length() > llvm_instrinsics_prefix.length() 
      && name.substr(0, llvm_instrinsics_prefix.length()).compare(llvm_instrinsics_prefix) == 0;
}

inline std::string demangle_func_name(const std::string& mangled_name) {
  int status;
  const char* str = mangled_name.c_str();
  char* demangled_name = abi::__cxa_demangle(str, nullptr, nullptr, &status);    
  if (status != 0 || demangled_name == NULL || strlen(demangled_name) == 0) {
    return mangled_name;
  }

  std::string result;
  const char* pos = strchr(demangled_name, '(');
  if( pos != NULL )
      result = std::string(demangled_name, 0, pos - demangled_name);
  else
      result = demangled_name;

  std::free(demangled_name);
  return result;
}

inline std::string get_inst_name(llvm::Instruction* inst){
  std::string str;
  raw_string_ostream OS(str);
  inst->print(OS,false);  
  return OS.str();
}

inline std::string to_string(int val){   
  return std::to_string(val);
}

inline const std::string& to_string(const std::string& val){   
  return val;
}

template <typename T>
inline std::string to_string(const std::vector<T>& vec){
  std::string out = "{";
  int i = 0, size = vec.size();;
  for(const T& val : vec){
    out += hpcc::to_string(val);
    if(++i != size)
      out += ",";
  }
  out += "}";
  return out;
}


}

#endif // HPCC_MACRO_H

