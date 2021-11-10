#include "./OperatorNode.h"
#include "./VarNode.h"

ASTREE::OperatorNode::OperatorNode() : RootNode(ASTREE::ASTNodeType::op) {}

ASTREE::OperatorNode::OperatorNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::op) {
    this->op_type = ASTREE::none;
}

ASTREE::OperatorNode::OperatorNode(std::string content, OpType op_type)
    : RootNode(content, ASTREE::ASTNodeType::op) {
    this->op_type = op_type;
}

void ASTREE::OperatorNode::printInfo(int) {
    std::cout << "operator: " << this->content;
}

void ASTREE::OperatorNode::setAllSymbolType(std::string tp) {
    ASTREE::RootNode* c = this->getChildNode();
    if (c == NULL) {
        return;
    }
    if (c->getASTNodeType() == ASTREE::def_var) {
        ASTREE::DefineVarNode* tmp = (ASTREE::DefineVarNode*)c;
        tmp->setAllSymbolType(tp);
    }

    ASTREE::RootNode* peer = this->getPeerNode();
    if (peer == NULL) {
        return;
    }
    if (peer->getASTNodeType() == ASTREE::op) {
        ASTREE::OperatorNode* tmp = (ASTREE::OperatorNode*)peer;
        tmp->setAllSymbolType(tp);
    }
}
