
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/PhiValues.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    PhiValues &PV = getAnalysis<PhiValuesWrapperPass>().getResult();
    
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        if (PHINode *PN = dyn_cast<PHINode>(&I)) {
          errs() << "Phi Node: " << *PN << "\n";
          for (unsigned i = 0; i < PN->getNumIncomingValues(); ++i) {
            Value *IncomingValue = PN->getIncomingValue(i);
            BasicBlock *IncomingBlock = PN->getIncomingBlock(i);
            errs() << "  Incoming Value from Block " << IncomingBlock->getName() << ": " << *IncomingValue << "\n";
          } 

          llvm::PhiValues::ValueSet VS = PV.getValuesForPhi(PN);
          errs() << "ValueSet: ";
          for( Value* v : VS)
              errs() << " " << *v;
            errs() << "\n";
        }
      }
    }      

    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<PhiValuesWrapperPass>();
    //AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

