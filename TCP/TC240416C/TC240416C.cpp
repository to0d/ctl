
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Support/raw_ostream.h"


using namespace llvm;

#define DEBUG_TYPE "MyPass"

static bool is_llvm_intrinsic(const std::string& name){
  static const std::string llvm_instrinsics_prefix= "llvm.";
  return name.length() > llvm_instrinsics_prefix.length() 
      && name.substr(0, llvm_instrinsics_prefix.length()).compare(llvm_instrinsics_prefix) == 0;
}

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
    DominatorTree DT = DominatorTree(F);
    print_node(0, DT.getRootNode());
    return false;
  }

  static void print_node(int level, const DomTreeNodeBase<BasicBlock> *node){
    for(int i = 0 ; i < level; ++i){
      errs() << "  ";
    }
    errs() << get_llvm_block_name(node->getBlock()) << ":";
    for(Instruction& I : *node->getBlock()){
      if(!isa<CallInst>(I)){
        continue;
      }

      CallInst* CI = dyn_cast<CallInst>(&I);
      std::string callFuncName = CI->getCalledFunction()->getName().str();
      if(is_llvm_intrinsic(callFuncName))
        continue;

      errs() << " " << callFuncName;
    }

    errs() << "\n";

    for (auto I = node->begin(), E = node->end(); I != E; ++I)
      print_node(level+1, *I);
    }
};

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

