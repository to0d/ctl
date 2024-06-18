
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/LazyBranchProbabilityInfo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    BranchProbabilityInfo &BPI = getAnalysis<LazyBranchProbabilityInfoPass>().getBPI();
    
    // 使用BPI来获取分支的概率信息，例如：
    for (BasicBlock &BB : F) {
      Instruction *TI = BB.getTerminator();
      if (TI->getNumSuccessors() > 1) {
        //BranchProbabilityInfo &BPIInfo = BPI.getBranchProbabilities(TI);
        for (unsigned i = 0; i < TI->getNumSuccessors(); ++i) {
          BasicBlock *Succ = TI->getSuccessor(i);
          BranchProbability Prob = BPI.getEdgeProbability(&BB, Succ);
          errs() << "Probability of branch from " << BB.getName() << " to " << Succ->getName() << " is " << Prob.getNumerator() << "/" << Prob.getDenominator() << "\n";
        }
      }
    }

    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<LazyBranchProbabilityInfoPass>();
    //AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

