#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "llvm/Support/raw_ostream.h"


using namespace clang;

namespace {

// 自定义的PragmaVisitor类，用于访问AST并处理自定义的pragma指令
class PragmaVisitor : public RecursiveASTVisitor<PragmaVisitor> {
public:
  explicit PragmaVisitor(ASTContext *Context) : Context(Context) {}

  bool VisitFunctionDecl(FunctionDecl *FD) {
    // if (FD->hasAttr()) {
    //   llvm::outs() << "Found my_pragma in function " << FD->getName() << "\n";
    // }
    return true;
  }

  // 处理Pragma指令
  bool VisitPragmaDirective(MacroDirective *PD) {


    
     llvm::errs() << "test2\n" ;
    SourceLocation Loc = PD->getLocation();
    if (Loc.isValid()) {
      llvm::outs() << "Found custom pragma at ";
      Loc.print(llvm::outs(), Context->getSourceManager());
      llvm::outs() << "\n";
    }
    return true;
  }

private:
  ASTContext *Context;
};

// 自定义的ASTConsumer类，用于创建PragmaVisitor并遍历AST
class PragmaASTConsumer : public ASTConsumer {
public:
  explicit PragmaASTConsumer(ASTContext *Context) : Visitor(Context) {}

  // 遍历AST
  void HandleTranslationUnit(ASTContext &Context) override {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }

private:
  PragmaVisitor Visitor;
};

// 自定义的FrontendAction类，用于创建PragmaASTConsumer
class PragmaFrontendAction : public PluginASTAction {
protected:
  std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI,
                                                 llvm::StringRef) override {
                                                llvm::errs() << "test\n" ;
    return std::make_unique<PragmaASTConsumer>(&CI.getASTContext());
  }

  bool ParseArgs(const CompilerInstance &CI,
                 const std::vector<std::string> &args) override {
    return true;
  }
};

} // namespace

static FrontendPluginRegistry::Add<PragmaFrontendAction>
    X("myplugin", "Custom pragma plugin");

