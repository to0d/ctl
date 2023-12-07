#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/CycleAnalysis.h"

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
        CycleInfo *CI = &getAnalysis<CycleInfoWrapperPass>().getCycleInfo();

        for (Loop *L : *LI) {
            errs() << "Loop Depth: " << L->getLoopDepth() << "\n";
          
            for(auto bb = L->block_begin(); bb != L->block_end(); ++bb)
            {
                errs() << "\tCycleDepth: " << CI->getCycle(*bb)->getDepth() << "\n";
                
                for(BasicBlock::iterator i = (*bb)->begin(), e = (*bb)->end(); i != e; ++i)
                    errs() << "\tI: " << *i << "\n";           
            }
        }
      
        return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<LoopInfoWrapperPass>();
      AU.addRequired<CycleInfoWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char LoopPass::ID = 0;
static RegisterPass<LoopPass> X("myloop", "My Loop Pass");

