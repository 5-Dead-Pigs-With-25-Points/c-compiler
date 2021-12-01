#include "./VarNode.h"
#include "./OperatorNode.h"

ASTREE::DefineVarNode::DefineVarNode() : RootNode(ASTREE::ASTNodeType::def_var) {
    this->symbol_type = SMB::SymbolType::none;
}

ASTREE::DefineVarNode::DefineVarNode(std::string content, std::string struct_name)
    : RootNode(content, ASTREE::ASTNodeType::def_var) {
    this->symbol_type = SMB::SymbolType::struct_type;
    this->struct_name = struct_name;
}

ASTREE::DefineVarNode::DefineVarNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::def_var) {
    this->symbol_type = SMB::SymbolType::none;
}

void ASTREE::DefineVarNode::printInfo(int) {
    if (this->symbol_type == SMB::SymbolType::array) {
        std::cout << "array definition: " << this->content << " length: " << this->array_length;
    }
    else {
        std::cout << "variable definition: " << this->content;
    }
}

void ASTREE::DefineVarNode::setAllSymbolType(std::string symbol_type) {
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
    if (peer->getASTNodeType() == ASTREE::op) {
        OperatorNode* tmp = (OperatorNode*)peer;
        tmp->setAllSymbolType(symbol_type);
    }
    else if (peer->getASTNodeType() == ASTREE::def_var) {
        DefineVarNode* tmp = (DefineVarNode*)peer;
        tmp->setAllSymbolType(symbol_type);
    }
}

void ASTREE::DefineVarNode::setArrayLength(std::string length) {
    this->array_length = atoi(length.c_str());
}

ASTREE::CallVarNode::CallVarNode() : RootNode(ASTREE::ASTNodeType::call_var) {}

ASTREE::CallVarNode::CallVarNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::call_var) {}

void ASTREE::CallVarNode::printInfo(int) {
    std::cout << "variable: " << this->content;
}
