
#include "llvm/Pass.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

static bool is_llvm_instrinsics(const std::string& func){
  // llvm.dbg.declare
  if( func == "llvm.dbg.declare" )
    return true;
  return false;
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
          if( is_llvm_instrinsics(callFuncName) )
            continue;

          int line_number = -1;
          DILocation* LOC = I.getDebugLoc().get();
          if( LOC ){
            line_number = LOC->getLine();
          }

          errs() << "\tcall func=" << callFuncName << ", loc=" << line_number << "\n";
        }
      }
      
      
      return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

