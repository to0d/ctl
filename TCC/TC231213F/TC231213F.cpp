
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
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

  void _process_value(int level, llvm::Value* value){
              
    if(isa<User>(value)){
      _process_user(level, dyn_cast<llvm::User>(value));
      return;
    }

    errs() << " value=" << *value << "\n";
    llvm_unreachable("unprocess value type!");
  }
  
  void _process_user(int level, llvm::User* user){
            
    Type* type = user->getType();
    
    errs() << " user: ";

    out_type(type->getTypeID());
        
    if( type->getTypeID() == llvm::Type::TypeID::IntegerTyID ){        
        llvm::ConstantInt* C = dyn_cast<ConstantInt>(user);
        if( C != NULL ){
            int val = C->getSExtValue();
            errs() << " (ConstantInt): " << val << "\n";
            return;
        }
    }
    
    llvm::Instruction* I = dyn_cast<Instruction>(user);
    if( I != NULL ){
        errs() << " (Instruction): " << *I << "\n";
        _process_instruction(level+1, I);
        return;
    }
    
    
    llvm::GlobalVariable* GV = dyn_cast<GlobalVariable>(user);
    if( GV != NULL ){
     
        std::string op_base = GV->getGlobalIdentifier();
        errs() << " (GlobalVariable): " << *GV << ", var=\"" << op_base << "\"\n";
        return;
    }
    
    errs() << " user=" << *user << " typid=" << type->getTypeID() << "\n";
    llvm_unreachable("unprocess opd type!");
  }

  void _process_instruction(int level, Instruction* I){
    
    out(level);
        
    unsigned int num_operands = I->getNumOperands();
    errs() <<"instruction: op_num=" << num_operands << ", I=" << *I;
    
    CallInst* CI = dyn_cast<CallInst>(I);
    if(CI){
        
        Function * func = CI->getCalledFunction();
        std::string mangled_name = (func->getName()).str();
        std::string func_name = demangle_func_name(mangled_name); 
        
        errs() <<", type=CallInst, func="<< func_name << "\n";

        for(unsigned int r = 0; r < num_operands - 1; r++){
            
          out(level + 1);          
        
          llvm::Value* opd = CI->getArgOperand(r);

          // every operand should be a User object
          llvm::User* user = dyn_cast<llvm::User>(opd);
          assert(user != NULL);          
         
          errs() << "operand " << r << ": ";
          _process_user(level+1, user);
        }
        
        return;
    }
    
    LoadInst* LI = dyn_cast<LoadInst>(I);
    if(LI){
        assert(num_operands == 1);    
        
        Value* val = LI->getPointerOperand();
        assert(val != NULL);
        
        Type* type = LI->getPointerOperandType();
        assert(type != NULL);
        
        errs() <<", type=LoadInst, getPointerOperandType()=" << *type << "\n" ;    

        out(level+1);
        
        errs() << "getPointerOperand(): ";
        _process_value(level+1, val);

        return;
    }
    
    AllocaInst* AI = dyn_cast<AllocaInst>(I);
    if(AI){
                
        PointerType* PT = AI->getType();
        Value* value = AI->getArraySize();

        errs() <<", type=AllocaInst, getType()=" << *PT << ", getArraySize()=" << *value << "\n";
        return;
    }
  
    errs() << "unprocess instruction: " << *I << "\n";
  }
  
  void out_type(llvm::Type::TypeID id){
     errs() << "typeId=" << id;
     switch(id){
        case llvm::Type::TypeID::IntegerTyID: errs() << "(int)"; break;
        case llvm::Type::TypeID::PointerTyID: errs() << "(ptr)"; break;
        default:  errs() << "(unknown)"; break;
     }
  }
  
  void out(int level){
    for(int i = 0; i < level; ++i)
        errs() <<"    ";
  } 

  bool runOnFunction(Function &F) override {
    errs() <<"Function: "<< F.getName() << '\n';
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        if(!isa<CallInst>(I)){
          continue;
        }
        _process_instruction(1, &I);
      }
    }

    return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

