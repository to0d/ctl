#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/MemoryDependenceAnalysis.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

namespace {
  // LoopPass - The first implementation, without getAnalysisUsage.
  struct MyPass : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {   
          MemoryDependenceWrapperPass* MD = &getAnalysis<MemoryDependenceWrapperPass>();
          MemoryDependenceResults* MDR = &MD->getMemDep();
          for (Function::iterator BB = F.begin(), E = F.end(); BB != E; ++BB) {
            for (BasicBlock::iterator I = BB->begin(), IE = BB->end(); I != IE; ++I) {
                Instruction* inst = &*I;
                MemDepResult R = MDR->getDependency(inst);
                Instruction* DI = R.getInst();
                if( DI)
                {
                    errs() << "Instruction:\t" << *I << "\n";
                    errs() << "Depends on:\t" << *DI << "\n";
                }
            }
          }
        return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<MemoryDependenceWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

