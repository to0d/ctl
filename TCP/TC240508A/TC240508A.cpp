#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"

using namespace llvm;

#define DEBUG_TYPE "MyLoopPass"

struct MyLoopPass : public LoopPass {
  static char ID; 
  MyLoopPass() : LoopPass(ID) {}

  bool runOnLoop(Loop *L, LPPassManager &LPM) override {
    // 获取循环信息
    errs() << "Processing loop: " << *L;

    unsigned int bb_count = L->getBlocks().size();

    // 获取标量进化分析信息
    ScalarEvolution &SE = getAnalysis<ScalarEvolutionWrapperPass>().getSE();
    int TripCount = 0;
    BasicBlock *LatchBlock = L->getLoopLatch();
    if (LatchBlock) {
      TripCount = SE.getSmallConstantTripCount(L, LatchBlock);
    }

    errs() << bb_count << " Blocks, " << TripCount << "  trip\n";

    // 在这里可以对循环进行分析和优化

    errs() << "\n";

    return false; // 返回 true 表示 Pass 对循环进行了修改
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<LoopInfoWrapperPass>();
    AU.addRequired<ScalarEvolutionWrapperPass>(); 
    AU.setPreservesCFG(); // 保留控制流图
  }
};


char MyLoopPass::ID = 0;
static RegisterPass<MyLoopPass> X("hello", "Hello MyLoopPass");

