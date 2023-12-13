
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"

#include <cxxabi.h>

using namespace llvm;

#define DEBUG_TYPE "MyPass"

std::string demangle_func_name(const std::string& mangled_name) {
    int status;
    const char* str = mangled_name.c_str();
    char* demangled_name = abi::__cxa_demangle(str, nullptr, nullptr, &status);
    std::string result;
    //printf("status=%d\n", status);
    if (status == 0) {
        const char* pos = strchr(demangled_name, '(');
        if( pos != NULL )
            result = std::string(demangled_name, 0, pos - demangled_name);
        else
            result = demangled_name;
    }
    else
      result = mangled_name;
    std::free(demangled_name);
    return result;
}

struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool process_load_instruction(llvm::Value* opd){
    
    llvm::Instruction* ins = dyn_cast<Instruction>(opd);
    if(ins && ins->getOpcode() == Instruction::Load){
      Value *base = dyn_cast<LoadInst>(ins)->getOperand(0);
      if (isa<GlobalVariable>(base)){
          std::string op_base = dyn_cast<GlobalVariable>(base)->getGlobalIdentifier();
          errs() << " " << op_base << "(global)";
          return true;
      }
    }

    return false;
  }

  bool runOnFunction(Function &F) override {
    errs() <<"Function: "<< F.getName() << '\n';
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        if(!isa<CallInst>(I)){
          continue;
        }

        CallInst* CI = dyn_cast<CallInst>(&I);

        Function * func = CI->getCalledFunction();
        std::string mangled_name = (func->getName()).str();
        std::string func_name = demangle_func_name(mangled_name);
        errs() <<"\tcall "<< func_name << ": ";

        unsigned int num_operands = I.getNumOperands() - 1;

        for(unsigned int r = 0; r < num_operands; r++){
        
          llvm::Value* opd = CI->getArgOperand(r);

          // every operand should be a User object
          llvm::User* user = dyn_cast<llvm::User>(opd);
          assert(user != NULL);

          Type* opd_type = opd->getType();

          bool process = false;
 

          switch (opd_type->getTypeID()){
          case llvm::Type::TypeID::HalfTyID:  
          case llvm::Type::TypeID::BFloatTyID:    
          case llvm::Type::TypeID::FloatTyID:     
          case llvm::Type::TypeID::DoubleTyID:    
          case llvm::Type::TypeID::X86_FP80TyID:  
          case llvm::Type::TypeID::FP128TyID:     
          case llvm::Type::TypeID::PPC_FP128TyID: 
          case llvm::Type::TypeID::VoidTyID:      
          case llvm::Type::TypeID::LabelTyID:     
          case llvm::Type::TypeID::MetadataTyID:  
          case llvm::Type::TypeID::X86_MMXTyID:   
          case llvm::Type::TypeID::X86_AMXTyID:   
          case llvm::Type::TypeID::TokenTyID: 
            break;

          case llvm::Type::TypeID::IntegerTyID: {
              llvm::ConstantInt* C = dyn_cast<ConstantInt>(user);
              if( C != NULL ){
                int val = C->getSExtValue();
                errs() << " " << val << "(ConstantInt)";
                process = true;
              }
 

             break;              
            }

          
          case llvm::Type::TypeID::FunctionTyID:      
          case llvm::Type::TypeID::PointerTyID:       
          case llvm::Type::TypeID::StructTyID:        
          case llvm::Type::TypeID::ArrayTyID:         
          case llvm::Type::TypeID::FixedVectorTyID:   
          case llvm::Type::TypeID::ScalableVectorTyID:
          default:
            break;
          }

          if( !process ){
            errs() << "\nopd type=" << opd_type->getTypeID() << "\n";
            llvm_unreachable("unprocess opd type!");
          }
        }
        errs() <<"\n";
      }
    }

    return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

