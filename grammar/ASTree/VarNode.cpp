#include "./VarNode.h"
#include "./OperatorNode.h"

AST::DefineVarNode::DefineVarNode() : RootNode(AST::ASTNodeType::def_var) {
    this->symbol_type = SMB::SymbolType::none;
}

AST::DefineVarNode::DefineVarNode(std::string content, std::string struct_name)
    : RootNode(content, AST::ASTNodeType::def_var) {
    this->symbol_type = SMB::SymbolType::struct_type;
    this->struct_name = struct_name;
}

AST::DefineVarNode::DefineVarNode(std::string content) : RootNode(content, AST::ASTNodeType::def_var) {
    this->symbol_type = SMB::SymbolType::none;
}

void AST::DefineVarNode::printInfo(int) {
    if (this->symbol_type == SMB::SymbolType::array) {
        std::cout << "array defination: " << this->content << "length: " << this->array_length;
    }
    else {
        std::cout << "variable defination: " << this->content;
    }
}

void AST::DefineVarNode::setAllSymbolType(std::string symbol_type) {
    SMB::SymbolType var_type;
    if (symbol_type == "int") {
        var_type = SMB::SymbolType::integer;
    }
    else if (symbol_type == "void") {
        var_type = SMB::SymbolType::void_type;
    }
    else if (symbol_type == "int ptr") {
        var_type = SMB::SymbolType::pointer;
    }
    else if (symbol_type == "struct") {
        var_type = SMB::SymbolType::struct_type;
    }
    else if (symbol_type == "array") {
        var_type = SMB::SymbolType::array;
    }
    if (this->symbol_type == SMB::SymbolType::none) {
        // std::cout<<var_type<<std::endl;
        this->symbol_type = var_type;
    }
    RootNode* peer = this->getPeerNode();
    if (!peer) return;
    if (peer->getASTNodeType() == AST::op) {
        OperatorNode* tmp = (OperatorNode*)peer;
        tmp->setAllSymbolType(symbol_type);
    }
    else if (peer->getASTNodeType() == AST::def_var) {
        DefineVarNode* tmp = (DefineVarNode*)peer;
        tmp->setAllSymbolType(symbol_type);
    }
}

void AST::DefineVarNode::setArrayLength(std::string length) {
    this->array_length = atoi(length.c_str());
}

AST::CallVarNode::CallVarNode() : RootNode(AST::ASTNodeType::call_var) {}

AST::CallVarNode::CallVarNode(std::string content) : RootNode(content, AST::ASTNodeType::call_var) {}

void AST::CallVarNode::printInfo(int) {
    std::cout << "variable: " << this->content;
}