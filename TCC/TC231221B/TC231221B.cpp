
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

static int get_inst_loc(Instruction* I){
  if( I ){
      int line_number = -1;
      DILocation* LOC = I->getDebugLoc().get();
      if( LOC ){
        return LOC->getLine();
      }
  }
  return -1;
}

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


struct BlockInfo {
    BasicBlock  *block;
    int          beginLoc;
    int          endLoc;
};

static std::vector<BlockInfo> loadIfBlocks(Function* F, const std::string& ifVarName){

  std::vector<BlockInfo> blockInfos;

  for(BasicBlock& BB : *F){  
    for(Instruction& I : BB){                  
        // check if(simd_block)
        // example
        //    %5 = load i32, i32* @simd_block, align 4, !dbg !21
        //    %6 = icmp ne i32 %5, 0, !dbg !21
        //    br i1 %6, label %7, label %10, !dbg !23            
        if(I.getOpcode() == Instruction::Br){
          BranchInst* brInst = dyn_cast<BranchInst>(&I);

          if( brInst && brInst->isConditional()){
            Instruction* condInst = dyn_cast<Instruction>(brInst->getCondition());
            BasicBlock* succBlock =brInst->getSuccessor(0);
            if( succBlock && condInst) {
              ICmpInst* icmpInst = dyn_cast<ICmpInst>(condInst);                 
              if( icmpInst && ICmpInst::isEquality(icmpInst->getPredicate())){
                LoadInst* loadInst = dyn_cast<LoadInst>(icmpInst->getOperand(0));
                if( loadInst && isa<GlobalVariable>(loadInst->getOperand(0))){     
                  std::string globalVarName = dyn_cast<GlobalVariable>(loadInst->getOperand(0))->getGlobalIdentifier();
                  if( globalVarName == ifVarName){

                    BlockInfo BI;
                    BI.block = succBlock;
                    BI.beginLoc = get_inst_loc(brInst);
                    Instruction& lastInst = *(--succBlock->end());
                    BI.endLoc = get_inst_loc(&lastInst);
                    blockInfos.push_back(BI);
                  }
                }
              }                
            }
          }          
        }
    }    
  }
  
  return blockInfos;
}

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {   

    errs() << "Function: name=" << F.getName() << "\n";
    for(BlockInfo& BI : loadIfBlocks(&F, "simd_block")){ 
      errs() << get_block_name(BI.block) << ": begin=" << BI.beginLoc << ", end=" << BI.endLoc << "\n";     
    }
      
    return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

