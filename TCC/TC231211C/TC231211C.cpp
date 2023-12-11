#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include <cxxabi.h>

using namespace llvm;

#define DEBUG_TYPE "MyPass"

std::string demangle_func_name(const std::string& mangled_name) {
    int status;
    const char* str = mangled_name.c_str();
    char* demangled_name = abi::__cxa_demangle(str, nullptr, nullptr, &status);
    std::string result;
    if (status == 0) {
        const char* pos = strchr(demangled_name, '(');
        if( pos != NULL )
            result = std::string(demangled_name, 0, pos - demangled_name);
        else
            result = demangled_name;
    }
    std::free(demangled_name);
    return result;
}

bool is_class_func(const std::string& func_name){
    return func_name.find("::") != std::string::npos;
}

namespace {

  struct MyPass : public FunctionPass {
    static char ID;
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {

        errs() <<"Function "<< F.getName() << '\n';
      
        for (auto& BB : F) {
          for(BasicBlock::iterator i = BB.begin(); i != BB.end(); ++i){
            
            auto I = i;
            //Instruction* i = &I;
            //
            //if(!isa<CallInst>(i))
            //    continue;
            if(!isa<CallInst>(I))
                continue;
            
            errs() << "\tcall Instruction:\t" << *I << "\n";
            
            CallInst* CI = dyn_cast<CallInst>(I);
            Function* func = CI->getCalledFunction();
            
            auto mangled_name = (func->getName()).str();
            auto func_name = demangle_func_name(mangled_name);
            
            if( !is_class_func(func_name) )
                continue;
            
            errs() << "\t\tfunc_name:\t" << func_name << "\n";
            
            unsigned int num_operands = I->getNumOperands();
            errs() << "\t\tnum_operands:\t" << num_operands << "\n";
            
            num_operands -= 1; // remove func_name

            for(unsigned int r = 0; r < num_operands; r++){
                
                errs() << "\t\toperands[" << r << "]: ";           
                Value* opd = CI->getArgOperand(r);

                {
                    std::string str;
                    raw_string_ostream OS(str);
                    opd->printAsOperand(OS,false);
                    errs() <<" str=" << OS.str();  
                }
                
                errs() <<", type=" << opd->getType()->getTypeID(); 
                
                
                
                
                errs() << "\n";
            }
          }
        }
          
        return false;
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("my_pass", "My Pass");

