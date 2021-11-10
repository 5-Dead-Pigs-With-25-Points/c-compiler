#include "./OperatorNode.h"
#include "./VarNode.h"

AST::OperatorNode::OperatorNode() : RootNode(AST::ASTNodeType::op) {}

AST::OperatorNode::OperatorNode(std::string content) : RootNode(content, AST::ASTNodeType::op) {
    this->op_type = AST::none;
}

AST::OperatorNode::OperatorNode(std::string content, OpType op_type)
    : RootNode(content, AST::ASTNodeType::op) {
    this->op_type = op_type;
}

void AST::OperatorNode::printInfo(int) {
    std::cout << "operator: " << this->content;
}

void AST::OperatorNode::setAllSymbolType(std::string tp) {
    AST::RootNode* c = this->getChildNode();
    if (c == NULL) {
        return;
    }
    if (c->getASTNodeType() == AST::def_var) {
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)c;
        tmp->setAllSymbolType(tp);
    }

    AST::RootNode* peer = this->getPeerNode();
    if (peer == NULL) {
        return;
    }
    if (peer->getASTNodeType() == AST::op) {
        AST::OperatorNode* tmp = (AST::OperatorNode*)peer;
        tmp->setAllSymbolType(tp);
    }
}