
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/LazyBlockFrequencyInfo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    BlockFrequencyInfo &BFI = getAnalysis<LazyBlockFrequencyInfoPass>().getBFI();
    // 使用BFI来获取基本块的频率信息，例如：
    for (BasicBlock &BB : F) {
        BlockFrequency Freq = BFI.getBlockFreq(&BB);
        errs() << "Basic Block " << BB.getName() << " has frequency " << Freq.getFrequency() << "\n";
    }
    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<LazyBlockFrequencyInfoPass>();
    //AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

