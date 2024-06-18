#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Passes/PassBuilder.h>

using namespace llvm;

int main() {
  LLVMContext Context;
  Module M("example", Context);
  IRBuilder<> Builder(Context);

  // 创建一个函数
  FunctionType *FuncType = FunctionType::get(Type::getInt32Ty(Context), false);
  Function *Func = Function::Create(FuncType, Function::ExternalLinkage, "foo", M);

  // 创建基本块
  BasicBlock *BB = BasicBlock::Create(Context, "entry", Func);
  Builder.SetInsertPoint(BB);

  // 创建指令
  Value *A = Builder.CreateAlloca(Type::getInt32Ty(Context), nullptr, "a");
  Value *B = Builder.CreateAlloca(Type::getInt32Ty(Context), nullptr, "b");
  Value *C = Builder.CreateAlloca(Type::getInt32Ty(Context), nullptr, "c");

  Value *LoadA = Builder.CreateLoad(Type::getInt32Ty(Context), A, "loadA");
  Value *LoadB = Builder.CreateLoad(Type::getInt32Ty(Context), B, "loadB");
  Value *Add = Builder.CreateAdd(LoadA, LoadB, "add");
  Builder.CreateStore(Add, C);

  // 创建一个优化器
 // ModuleAnalysisManager FAM;
  //PassManager<Module> PM;

  // 创建一个 PassBuilder
  //PassBuilder PB;

  // 创建一个 MyPass 实例
  //InstructionCombiningPass CB;

  // 将 MyPass 加入到 PassManager 中
  //PB.registerModuleAnalyses(FAM);
  //LLVMAddInstructionCombiningPass(PM);
  //PM.addPass(createInstructionCombiningPass());

  // 运行 PassManager
  //PM.run(M, FAM);

  // 打印优化后的函数
  M.print(llvm::outs(), nullptr);

  return 0;
}