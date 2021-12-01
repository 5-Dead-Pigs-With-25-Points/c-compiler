#include "./FuncNode.h"

#include "../symbol/SymbolType.h"
#include "./VarNode.h"

ASTREE::DefineFunctionNode::DefineFunctionNode() : RootNode(ASTREE::ASTNodeType::def_func) {
    this->arg_list = NULL;
}

ASTREE::DefineFunctionNode::DefineFunctionNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::def_func) {
    this->arg_list = NULL;
}

ASTREE::DefineFunctionNode::DefineFunctionNode(std::string content, RootNode* arg_list) : RootNode(content, ASTREE::ASTNodeType::def_func) {
    this->arg_list = arg_list;
}

void ASTREE::DefineFunctionNode::setReturnSymbolType(std::string symbol_type) {
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

void ASTREE::DefineFunctionNode::printInfo(int) {
    std::cout << "function definition: " << this->content;
    ASTREE::RootNode* args = this->arg_list;
    std::string str = ", args: ";
    while (args) {
        str += "(" + SMB::symbol_str[((DefineVarNode*)args)->getSymbolType()] + ")";
        str += args->getContent() + ", ";
        args = args->getPeerNode();
    }
    std::cout << str;
}

ASTREE::DefineFunctionNode::~DefineFunctionNode() {
    if (this->arg_list) {
        delete this->arg_list;
    }
}

ASTREE::CallFuncNode::CallFuncNode() : RootNode(ASTREE::ASTNodeType::call_func) {
    this->arg_list = NULL;
}

ASTREE::CallFuncNode::CallFuncNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::call_func) {
    this->arg_list = NULL;
}

void ASTREE::CallFuncNode::printInfo(int) {
    std::cout << "call function: " << this->content;
    ASTREE::RootNode* args = this->arg_list;
    std::string str = ", args: ";
    while (args) {
        str += args->getContent() + ", ";
        args = args->getPeerNode();
    }
    std::cout << str;
}

ASTREE::CallFuncNode::~CallFuncNode() {
    if (this->arg_list) {
        delete arg_list;
    }
}
