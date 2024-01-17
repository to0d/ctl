
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include <map>
#include <vector>

using namespace llvm;

#define DEBUG_TYPE "MyPass"

#define OLD_NAME "func"
#define NEW_NAME "func_wrap"

struct MyPass : public ModulePass {
  static char ID; 
  MyPass() : ModulePass(ID) {}

  
  bool runOnModule(Module &M) override {   

    for( Function& F : M.getFunctionList() ){

      errs() << "func=" << F.getName() << "\n";
      
      if( F.getName() == OLD_NAME){
        F.setName(NEW_NAME);
        errs() << "update\n" ;
      }
     
    }

    return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

