#include "./SelectNode.h"

ASTREE::SelectNode::SelectNode() : RootNode(ASTREE::ASTNodeType::select) {
    this->body = NULL;
    this->cond = NULL;
}

ASTREE::SelectNode::SelectNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::select) {
    this->body = NULL;
    this->cond = NULL;
}

ASTREE::SelectNode::SelectNode(SelectType select_type) : RootNode(ASTREE::ASTNodeType::select) {
    this->select_type = select_type;
    this->body = NULL;
    this->cond = NULL;
}

ASTREE::SelectNode::SelectNode(std::string content, SelectType select_type) : RootNode(content, ASTREE::ASTNodeType::select) {
    this->select_type = select_type;
    this->body = NULL;
    this->cond = NULL;
}

// if / else if
ASTREE::SelectNode::SelectNode(std::string content, SelectType select_type, RootNode* cond, RootNode* body)
    : RootNode(content, ASTREE::ASTNodeType::select) {
    this->select_type = select_type;
    this->cond = cond;
    this->body = body;
}

// else
ASTREE::SelectNode::SelectNode(std::string content, SelectType select_type, RootNode* body)
    : RootNode(content, ASTREE::ASTNodeType::select) {
    this->select_type = select_type;
    this->body = body;
    this->cond = NULL;
}

void ASTREE::SelectNode::printInfo(int) {
    switch (this->select_type) {
    case if_stmt:
        std::cout << "select statement(if): ";
        break;
    case else_stmt:
        std::cout << "select statement(else): ";
        break;
    case else_if_stmt:
        std::cout << "select statement(else if): ";
        break;
    }
    std::cout << this->content;
}

ASTREE::SelectNode::~SelectNode() {
    if (cond) delete cond;
    if (body) delete body;
}