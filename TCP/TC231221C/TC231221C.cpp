
#include "llvm/Pass.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include <map>
#include <vector>

using namespace llvm;

#define DEBUG_TYPE "MyPass"

static std::string get_block_name(BasicBlock* BB){
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

    errs() << "Function: name=" << F.getName() << "\n";
    for(BasicBlock& BB : F){
        std::string blockName = get_block_name(&BB);      
        errs() << "block: namne=" << blockName << "\n" ;
    }
    
    return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

