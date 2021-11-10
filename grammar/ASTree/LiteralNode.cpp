#include "./LiteralNode.h"

AST::LiteralNode::LiteralNode() : RootNode(AST::ASTNodeType::literal) {}

AST::LiteralNode::LiteralNode(std::string content) : RootNode(content, AST::ASTNodeType::literal) {}

int AST::LiteralNode::getValue() {
    return std::stoi(this->content);
    return std::stoi(this->content);
}

void AST::LiteralNode::printInfo(int) {
    std::cout << "literal: " << this->content;
}