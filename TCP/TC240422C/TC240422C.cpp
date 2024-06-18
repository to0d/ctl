
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/LazyValueInfo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    LazyValueInfo &LVI = getAnalysis<LazyValueInfoWrapperPass>().getLVI();

    for (auto &BB : F) {
      for (auto &I : BB) {
        if (auto *Cmp = dyn_cast<CmpInst>(&I)) {
          if (Cmp->getPredicate() == CmpInst::ICMP_EQ) {
            if (auto *CI = dyn_cast<ConstantInt>(Cmp->getOperand(1))) {
              if (CI->isZero()) {
                errs() << *CI << "\n";
                if (auto *PN = dyn_cast<PHINode>(Cmp->getOperand(0))) {
                  errs() << *PN << "\n";
                  if (LVI.getPredicateAt(Cmp->getPredicate(), Cmp->getOperand(0), Cmp->getOperand(1), Cmp, true) == LazyValueInfo::Tristate::True) {
                    for (unsigned i = 0; i < PN->getNumIncomingValues(); ++i) {
                      if (auto *Incoming = dyn_cast<ConstantInt>(PN->getIncomingValue(i))) {
                        if (Incoming->isNegative()) {
                          return false;
                        }
                      }
                    }
                    PN->replaceAllUsesWith(ConstantInt::get(Type::getInt32Ty(F.getContext()), -1));
                    PN->eraseFromParent();
                    return true;
                  }
                }
              }
            }
          }
        }
      }
    }
    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesCFG();
    AU.addRequired<LazyValueInfoWrapperPass>();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

