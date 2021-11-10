#include "./LiteralNode.h"

ASTREE::LiteralNode::LiteralNode() : RootNode(ASTREE::ASTNodeType::literal) {}

ASTREE::LiteralNode::LiteralNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::literal) {}

int ASTREE::LiteralNode::getValue() {
    return std::stoi(this->content);
    return std::stoi(this->content);
}

void ASTREE::LiteralNode::printInfo(int) {
    std::cout << "literal: " << this->content;
}