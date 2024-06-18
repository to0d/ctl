#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"

using namespace llvm;

#define DEBUG_TYPE "LoopPass"

namespace {
  // LoopPass - The first implementation, without getAnalysisUsage.
  struct LoopPass : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    LoopPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {      
      errs() <<"Function "<< F.getName() << '\n';
      LoopInfo *LI = &getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
      for (auto topLoop=LI->begin(); topLoop!=LI->end();topLoop++){ 
        Loop *L = *topLoop;
        unsigned int bb_count = L->getBlocks().size();
        
        ScalarEvolution *SE = &getAnalysis<ScalarEvolutionWrapperPass>().getSE();
        int TripCount = 0;
        BasicBlock *LatchBlock = L->getLoopLatch();
        if (LatchBlock) {
          TripCount = SE->getSmallConstantTripCount(L, LatchBlock);
        }

        errs() << bb_count << " Blocks, " << TripCount << "  trip\n";
             
      }
      return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<ScalarEvolutionWrapperPass>(); 
      AU.addRequired<LoopInfoWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char LoopPass::ID = 0;
static RegisterPass<LoopPass> X("myloop", "My Loop Pass");

