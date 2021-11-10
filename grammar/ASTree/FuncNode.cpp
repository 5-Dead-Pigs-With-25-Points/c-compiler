#include "./FuncNode.h"

#include "./SymbolType.h"
#include "./VarNode.h"

AST::DefineFuncNode::DefineFuncNode() : RootNode(AST::ASTNodeType::def_func) {
    this->arg_list = NULL;
}

AST::DefineFuncNode::DefineFuncNode(std::string content) : RootNode(content, AST::ASTNodeType::def_func) {
    this->arg_list = NULL;
}

AST::DefineFuncNode::DefineFuncNode(std::string content, RootNode* arg_list) : RootNode(content, AST::ASTNodeType::def_func) {
    this->arg_list = arg_list;
}

void AST::DefineFuncNode::setReturnSymbolType(std::string symbol_type) {
    if (symbol_type == "int") {
        this->return_symbol_type = SMB::integer;
    }
    else if (symbol_type == "void") {
        this->return_symbol_type = SMB::void_type;
    }
    else if (symbol_type == "int ptr") {
        this->return_symbol_type = SMB::pointer;
    }
}

void AST::DefineFuncNode::printInfo(int) {
    std::cout << "function defination: " << this->content;
    AST::RootNode* args = this->arg_list;
    std::string str = ", args: ";
    while (args) {
        str += "(" + SMB::symbol_str[((DefineVarNode*)args)->getSymbolType()] + ")";
        str += args->getContent() + ", ";
        args = args->getPeerNode();
    }
    std::cout << str;
}

AST::DefineFuncNode::~DefineFuncNode() {
    if (this->arg_list) {
        delete this->arg_list;
    }
}

AST::CallFuncNode::CallFuncNode() : RootNode(AST::ASTNodeType::call_func) {
    this->arg_list = NULL;
}

AST::CallFuncNode::CallFuncNode(std::string content) : RootNode(content, AST::ASTNodeType::call_func) {
    this->arg_list = NULL;
}

void AST::CallFuncNode::printInfo(int) {
    std::cout << "call function: " << this->content;
    AST::RootNode* args = this->arg_list;
    std::string str = ", args: ";
    while (args) {
        str += args->getContent() + ", ";
        args = args->getPeerNode();
    }
    std::cout << str;
}

AST::CallFuncNode::~CallFuncNode() {
    if (this->arg_list) {
        delete arg_list;
    }
}