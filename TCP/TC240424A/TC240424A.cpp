
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/StackSafetyAnalysis.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    const StackSafetyInfo &SSI = getAnalysis<StackSafetyInfoWrapperPass>().getResult();
    errs() << "Function " << F.getName() << "\n";
    std::string str;
    raw_string_ostream OS(str);
    SSI.print(OS);  
    errs() << OS.str();
    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<StackSafetyInfoWrapperPass>();
    //AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

