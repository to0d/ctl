
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "hpcc_dfg_util.h"
#include "hpcc_dot_util.h"

using namespace llvm;
using namespace hpcc;

#define DEBUG_TYPE "MyPass"

cl::opt<std::string> dot_path ( "dot-path", cl::desc("Input source file"));

struct MyPass : public ModulePass {

	static char ID;
	MyPass() : ModulePass(ID) {}

  bool runOnModule(Module &M) override {

    for (Function& F : M) {
      if(DFGUtil::is_empty_function(&F))
        continue;
      
      DFGUtil DFG_Util(&F);
      DotUtil DOT_Util(&F, DFG_Util.get_node_list());

      // output dot
      std::string dot_name = dot_path + DOT_Util.get_graph_name() + ".dot";
      DOT_Util.output_dot(dot_name);
    }


    return false;
  }


};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "DFG Pass Analyse");

