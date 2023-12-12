
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "MyPass"

namespace {

  struct MyPass : public FunctionPass {
    static char ID; 
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {   
        AliasAnalysis* AA = &getAnalysis<AAResultsWrapperPass>().getAAResults();

        std::vector<Value*> all_values;
        for (BasicBlock &BB : F) {
            for (Instruction &I : BB) {
                if (isa<LoadInst>(&I) || isa<StoreInst>(&I)) {
                    for (Use &U : I.operands()) {
                      Value* Op = U.get();
                      all_values.push_back(Op);
                    }
                }
            }
        }
        
        int size = all_values.size();
        for(int i = 0; i < size - 1; ++i){
            Value* v1 = all_values[i];
            auto loc1 = MemoryLocation::getBeforeOrAfter(v1);
            for(int j = i+1; j < size; ++j){
                Value* v2 = all_values[j];
                if( v2 == v1 )
                    continue;                
                auto loc2 = MemoryLocation::getBeforeOrAfter(v2);
                if (AA->isMustAlias(loc1, loc2)) {
                  errs() << "alias: v1=" << *v1 << ", v2=" << *v2 << "\n";
                }
            }
        }
       
        return false;
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<AAResultsWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

