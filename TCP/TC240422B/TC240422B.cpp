#include "llvm/Transforms/Vectorize.h"
#include "llvm/Analysis/VectorUtils.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

int main() {
  LLVMContext Context;
  Module M("example", Context);
  IRBuilder<> Builder(Context);

  // 创建一个函数
  FunctionType *FTy = FunctionType::get(Type::getVoidTy(Context), false);
  Function *F = Function::Create(FTy, Function::ExternalLinkage, "foo", M);
  BasicBlock *BB = BasicBlock::Create(Context, "entry", F);
  Builder.SetInsertPoint(BB);

  // 向函数中添加一些向量化代码
  Value *A = Builder.CreateAlloca(VectorType::get(Type::getInt32Ty(Context), 4, true));
  Value *B = Builder.CreateAlloca(VectorType::get(Type::getInt32Ty(Context), 4, true));
  Value *C = Builder.CreateAlloca(VectorType::get(Type::getInt32Ty(Context), 4, true));
  Value *LoadA = Builder.CreateLoad(Type::getInt32Ty(Context), A, "loadA");
  Value *LoadB = Builder.CreateLoad(Type::getInt32Ty(Context), B, "loadB");
  Value *Sum = Builder.CreateAdd(LoadA, LoadB, "add");
  Builder.CreateStore(Sum, C);

  M.print(outs(), nullptr);

  // 创建 Pass 管理器
  legacy::PassManager PM;

  Pass* pass = createLoopVectorizePass();
  assert(pass && "null pass");

  PM.add(pass);

  // 运行 Pass
  PM.run(M);

  // 打印优化后的 IR
  M.print(outs(), nullptr);

  return 0;
}
