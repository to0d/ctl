
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/RegionInfo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

namespace {

  struct MyPass : public FunctionPass {
    static char ID; 
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      RegionInfo &RI = getAnalysis<RegionInfoPass>().getRegionInfo();
      
      for (BasicBlock &BB : F) {
        Region* RG = RI.getRegionFor(&BB);
        errs() << "block: " << BB  << "\n";
        errs() << "depth: " << RG->getDepth() << "\n";
      }
      return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<RegionInfoPass>();
      //AU.setPreservesAll();
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

