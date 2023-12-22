
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Value.h"
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

static std::string get_value_name(Value* val) {
    std::string str;
    raw_string_ostream OS(str);
    val->printAsOperand(OS,false);
    return OS.str();
}

static std::pair<std::string, int> get_type_name(Type* type) {

  if( type == NULL )
    return std::pair<std::string, int>("", -1);

  switch (type->getTypeID())
  {
  case Type::DoubleTyID:
  case Type::IntegerTyID:
    {
      std::string str;
      raw_string_ostream OS(str);
      type->print(OS,false);  
      return std::pair<std::string, int>(OS.str(), 0);
    } 
  default:
    break;
  }

  PointerType* PT = dyn_cast<PointerType>(type);
  if( PT != NULL ){
    Type* ET = PT->getPointerElementType();
    auto rst = get_type_name(ET);
    return std::pair<std::string, int>(rst.first, rst.second+1);
  }

  StructType* ST = dyn_cast<StructType>(type);
  if( ST != NULL ){
     return std::pair<std::string, int>(ST->getName(), 0);
  }
 
  errs() << "type=" << *type << "\n";
  llvm_unreachable("unsupport type");
}

struct DbgDeclareVar {
    std::string varName;
    std::string typeName;
    int         typePtrLvl;
    std::string realName;
    int         declareLoc;
};

static std::vector<DbgDeclareVar> get_dbg_declare_var(Function* F){
    if( F == nullptr )
        return {};

    std::vector<DbgDeclareVar> decVars;
    
    for(BasicBlock& BB : *F){
        std::string blockName = get_block_name(&BB);      
        // errs() << "block: namne=" << blockName << "\n" ;        
        for(Instruction& I : BB){
          if(!isa<CallInst>(I)){
            continue;
          }
          
          CallInst* CI = dyn_cast<CallInst>(&I);
          std::string callFuncName = CI->getCalledFunction()->getName().str();
               
          if( callFuncName != "llvm.dbg.declare")
              continue;

          // errs() << "\tI: " << I << "\n" ; 
          
          unsigned int num_operands = I.getNumOperands();
          assert(num_operands > 2);
          // errs() << "\t\tnum_operands:\t" << num_operands << "\n";
          
          Value* varOpd = CI->getArgOperand(0);         
          if( varOpd == NULL)
            continue;
          
          MetadataAsValue* varMAV = dyn_cast<MetadataAsValue>(CI->getArgOperand(0));
          if( varMAV == NULL)
            continue;

          DbgDeclareVar DDV;

          ValueAsMetadata* varMD = dyn_cast<ValueAsMetadata>(varMAV->getMetadata());
          Value* varVal =  varMD->getValue();
          Type* varType =  varMD->getType();

          DDV.varName = get_value_name(varVal);

          auto vn = get_type_name(varType);
          DDV.typeName = vn.first; 
          DDV.typePtrLvl = vn.second;

          MetadataAsValue* nameMAV = dyn_cast<MetadataAsValue>(CI->getArgOperand(1));
          if( nameMAV == NULL )
            continue;          

          DILocalVariable* nameMD = dyn_cast<DILocalVariable>(nameMAV->getMetadata());
          if( nameMD == NULL )
            continue;

          DDV.realName = nameMD->getName().str();
          DDV.declareLoc = get_inst_loc(&I);

          decVars.push_back(DDV);
        }
    }
    
    return decVars;
}

 
struct MyPass : public FunctionPass {
  static char ID; 
  MyPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {   

    errs() << "Function: name=" << F.getName() << "\n";
    for(DbgDeclareVar DDV: get_dbg_declare_var(&F)){
      errs() << "\tvarName=" << DDV.varName   
             << ", typeName=" << DDV.typeName 
             << ", typePtrLvl=" << DDV.typePtrLvl 
             << ", realName=" << DDV.realName 
             << ", declareLoc=" << DDV.declareLoc << "\n";
    }    
    return false;
  }
};


char MyPass::ID = 0;
static RegisterPass<MyPass> X("mypass", "My Pass");

