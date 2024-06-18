#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/DominanceFrontier.h"
#include "llvm/Analysis/PostDominators.h"

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
    DominanceFrontier &DF = getAnalysis<DominanceFrontierWrapperPass>().getDominanceFrontier();
    PostDominatorTree &PDT = getAnalysis<PostDominatorTreeWrapperPass>().getPostDomTree();

    for (BasicBlock &BB : F) {
      errs() << "Dominance Frontier for Basic Block: " << get_llvm_block_name(&BB) << "\n";
      DominanceFrontier::iterator DFIt = DF.find(&BB);
      if (DFIt != DF.end()) {
        for (BasicBlock *Succ : DFIt->second) {
          errs() << "  -> " << get_llvm_block_name(Succ) << "\n";
        }
      }
    }

    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<DominatorTreeWrapperPass>();
    AU.addRequired<PostDominatorTreeWrapperPass>();
    AU.addRequired<DominanceFrontierWrapperPass>();
    AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

