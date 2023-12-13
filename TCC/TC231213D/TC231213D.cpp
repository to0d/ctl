
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/BasicAliasAnalysis.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

namespace {

  struct MyPass : public FunctionPass {
    static char ID; 
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      BasicAAResult &BAR = getAnalysis<BasicAAWrapperPass>().getResult();
      
      for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
          if (I.mayReadOrWriteMemory()) {
            MemoryLocation Loc = MemoryLocation::getBeforeOrAfter(&I);
            AliasResult Result = BAR.alias(Loc, AliasAnalysis::UnknownSize, Loc, AliasAnalysis::UnknownSize);
            
            errs() << "Instruction: " << I << "\n";
            errs() << "  Alias Result: " << Result << "\n";
          }
        }
      }
      return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<BasicAAWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

