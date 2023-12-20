
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/RegionInfo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

namespace {

  struct MyPass : public ModulePass {
    static char ID; 
    MyPass() : ModulePass(ID) {}
    
    bool runOnModule(Module &M) override {
        const DataLayout &DL = M.getDataLayout();
        
        // Get pointer size in bits
        unsigned PtrSize = DL.getPointerSizeInBits();
    
        errs() << "DataLayout::getPointerSizeInBits(): " << PtrSize << "\n";
        errs() << "Module::getSourceFileName(): " << M.getSourceFileName() << "\n";

        return false;
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

