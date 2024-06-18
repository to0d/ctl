
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    DependenceInfo &DI = getAnalysis<DependenceAnalysisWrapperPass>().getDI();
    
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        for (Instruction &J : BB) {
          if (&I == &J) 
            continue;
          if (DI.depends(&I, &J, true)) {
            errs() << "Instruction <" << I << "> depends on <" << J << ">\n";
          }
        }
      }
    }
    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<DependenceAnalysisWrapperPass>();
    //AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

