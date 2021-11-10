#include "./StmtNode.h"

AST::StatementNode::StatementNode() : RootNode(AST::ASTNodeType::stmt) {}

AST::StatementNode::StatementNode(std::string content) : RootNode(content, AST::ASTNodeType::stmt) {}

AST::StatementNode::StatementNode(StatementType tp) : RootNode(AST::ASTNodeType::stmt) {
    this->stmt_type = tp;
}

AST::StatementNode::StatementNode(std::string content, StatementType tp) : RootNode(content, AST::ASTNodeType::stmt) {
    this->stmt_type = tp;
}

void AST::StatementNode::printInfo(int) {
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