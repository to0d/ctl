
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

namespace {

  struct MyPass : public FunctionPass {
    static char ID; 
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      BlockFrequencyInfo &BFI = getAnalysis<BlockFrequencyInfoWrapperPass>().getBFI();
      
      for (BasicBlock &BB : F) {
        errs() << "Basic Block: " << BB.getName() << "\n";
        errs() << "  Execution Count: " << BFI.getBlockFreq(&BB).getFrequency() << "\n";
      }
      return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<BlockFrequencyInfoWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

