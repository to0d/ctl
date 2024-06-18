#include "llvm/Pass.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/raw_ostream.h"


using namespace llvm;

#define DEBUG_TYPE "MyPass"

static int get_llvm_inst_dbg_loc(llvm::Instruction* I){
  if( I ){
      int line_number = -1;
      DILocation* LOC = I->getDebugLoc().get();
      if( LOC ){
        return LOC->getLine();
      }
  }
  return -1;
}

static bool is_llvm_intrinsic(const std::string& name){
  static const std::string llvm_instrinsics_prefix= "llvm.";
  return name.length() > llvm_instrinsics_prefix.length() 
      && name.substr(0, llvm_instrinsics_prefix.length()).compare(llvm_instrinsics_prefix) == 0;
}

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {   

      errs() << "Function: name=" << F.getName() << "\n";

      for(BasicBlock& BB : F){
        for(Instruction& I : BB){
          if(!isa<CallInst>(I)){
            continue;
          }

          CallInst* CI = dyn_cast<CallInst>(&I);
          std::string callFuncName = CI->getCalledFunction()->getName().str();
          if( is_llvm_intrinsic(callFuncName) )
            continue;

          int line_number = get_llvm_inst_dbg_loc(&I);
 
          errs() << "\tcall func=" << callFuncName << ", loc=" << line_number << "\n";
        }
      }

      return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

