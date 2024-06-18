//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"

using namespace llvm;

#define DEBUG_TYPE "LoopPass"

namespace {
  // LoopPass - The first implementation, without getAnalysisUsage.
  struct LoopPass : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    LoopPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {      
      errs() <<"Function "<< F.getName() << '\n';
      
      LoopInfo *LI = &getAnalysis<LoopInfoWrapperPass>().getLoopInfo();

      for(Loop *L : *LI)
        countBlocksInLoop(L, 0);
      
      return false;
    }

    // We don't modify the program, so we preserve all analyses.
    void countBlocksInLoop(Loop* L, unsigned level) {
      unsigned num_Blocks = 0;      
      Loop::block_iterator bb;

      for(bb = L->block_begin(); bb != L->block_end(); ++bb){ 
        num_Blocks ++;
      }

      errs() << "Loop Level "<< level << ": "<< num_Blocks << " Blocks\n";

      std::vector<Loop*> subLoops = L->getSubLoops();
      for(auto child: subLoops)
        countBlocksInLoop(child, level+1);          
    }

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<LoopInfoWrapperPass>();
      //AU.setPreservesAll();
    }
  };
}

char LoopPass::ID = 0;
static RegisterPass<LoopPass> X("myloop", "My Loop Pass");

