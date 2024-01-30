
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "hpcc_dfg_util.h"


using namespace llvm;
using namespace hpcc;

#define DEBUG_TYPE "MyPass"

cl::opt<std::string> dot_path ( "dot-path", cl::desc("Input source file"));

struct MyPass : public ModulePass {

	static char ID;
	MyPass() : ModulePass(ID) {}

  bool runOnModule(Module &M) override {

    for (Function& F : M) {
      DFGUtil DFG_Util(&F);
      if(DFG_Util.is_empty_function())
        continue;
      // output dot
      std::string func_name = F.getName().str();
      func_name = demangle_func_name(func_name);
      std::string dot_name = dot_path + func_name + ".dot";
      DFG_Util.output_dot(dot_name);
    }


    return false;
  }


};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "DFG Pass Analyse");

