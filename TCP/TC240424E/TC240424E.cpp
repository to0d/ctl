#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Support/raw_ostream.h"

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
    DominatorTree &PDT = getAnalysis<DominatorTreeWrapperPass>().getDomTree();
    
    // 使用PDT来获取后支配树信息，例如：
    for (BasicBlock &BB : F) {
      DomTreeNode *Node = PDT.getNode(&BB);
      if (Node) {
        errs() << "Dominators of Basic Block " << get_llvm_block_name(&BB) << " are: ";
        for (DomTreeNode *Dominator : *Node) {
            BasicBlock *PostDominator = Dominator->getBlock();
            errs() << PostDominator->getName() << " ";
        }
        errs() << "\n";
      }
    }

    return false;
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<DominatorTreeWrapperPass>();
    //AU.setPreservesAll();
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

