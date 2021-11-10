#include "./StmtNode.h"

ASTREE::StatementNode::StatementNode() : RootNode(ASTREE::ASTNodeType::stmt) {}

ASTREE::StatementNode::StatementNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::stmt) {}

ASTREE::StatementNode::StatementNode(StatementType tp) : RootNode(ASTREE::ASTNodeType::stmt) {
    this->stmt_type = tp;
}

ASTREE::StatementNode::StatementNode(std::string content, StatementType tp) : RootNode(content, ASTREE::ASTNodeType::stmt) {
    this->stmt_type = tp;
}

void ASTREE::StatementNode::printInfo(int) {
    switch (this->stmt_type) {
    case compoundation:
        std::cout << "compound statement: ";
        break;
    case comparison:
        std::cout << "compare statement: ";
        break;
    case return_stmt:
        std::cout << "return statement: ";
        break;
    case definition:
        std::cout << "define statement: ";
        break;
    case expression:
        std::cout << "expression: ";
        break;
    }
    std::cout << this->content;
}