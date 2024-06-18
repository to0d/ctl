#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/MemorySSA.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

// LoopPass - The first implementation, without getAnalysisUsage.
struct MyPass : public FunctionPass {
  static char ID; // Pass identification, replacement for typeid
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {      
    MemorySSAWrapperPass *MSP = getAnalysisIfAvailable<MemorySSAWrapperPass>();
    if (!MSP) {
      errs() << "MemorySSAWrapperPass not found\n";
      return false;
    }

    MemorySSA &MSSA = MSP->getMSSA();
    for (auto &BB : F) {
      for (auto &I : BB) {
        MemoryAccess *MA = MSSA.getMemoryAccess(&I);
        if (MA) {              
          errs() << "I:" << I;

          MemoryUseOrDef *UD = dyn_cast<MemoryUseOrDef>(MA);
          std::string str;
          raw_string_ostream OS(str);
          UD->getDefiningAccess()->print(OS);
          errs() << "\tDA: " << OS.str() << "\n";
        }
      }
    }

    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<MemorySSAWrapperPass>();
    //AU.setPreservesAll();
  }
};



char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

