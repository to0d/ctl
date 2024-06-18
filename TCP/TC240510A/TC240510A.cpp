#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/Interval.h"
#include "llvm/Analysis/IntervalPartition.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

static std::string get_llvm_block_name(llvm::BasicBlock* BB){
  if( BB == nullptr )
      return "";
  
  if (!BB->getName().empty())
      return BB->getName().str();
  
  std::string Str;
  raw_string_ostream OS(Str);

  BB->printAsOperand(OS, false);
  return OS.str();
}

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    IntervalPartition &IP = getAnalysis<IntervalPartition>();

    for(auto I : IP.getIntervals()){
      errs() << "Interval: ";
      for (BasicBlock *BB : I->Nodes) {
        errs() << get_llvm_block_name(BB) << " ";
      }
      errs() << "\n";
    }

    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<IntervalPartition>();
    AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

