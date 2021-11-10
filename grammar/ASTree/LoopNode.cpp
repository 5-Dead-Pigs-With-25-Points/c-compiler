#include "./LoopNode.h"

AST::LoopNode::LoopNode() : RootNode(AST::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
}

AST::LoopNode::LoopNode(std::string content) : RootNode(content, AST::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
}

AST::LoopNode::LoopNode(LoopType tp) : RootNode(AST::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
    this->loop_type = tp;
}

AST::LoopNode::LoopNode(std::string content, LoopType tp) : RootNode(content, AST::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
    this->loop_type = tp;
}

// whileÑ­»·
AST::LoopNode::LoopNode(std::string content,
    LoopType loop_type,
    RootNode* condition)
    : RootNode(content, AST::loop) {
    this->loop_type = loop_type;
    this->cond = condition;
    condition->setParentNode(this);
    this->declare = NULL;
    this->action = NULL;
}

// forÑ­»·
AST::LoopNode::LoopNode(std::string content,
    LoopType loop_type,
    RootNode* cond,
    RootNode* dec,
    RootNode* action)
    : RootNode(content, AST::loop) {
    this->loop_type = loop_type;
    this->cond = cond;
    cond->setParentNode(this);
    this->declare = dec;
    dec->setParentNode(this);
    this->action = action;
    action->setParentNode(this);
}

void AST::LoopNode::printInfo(int) {
    switch (this->loop_type) {
    case while_loop:
        std::cout << "loop statement(while): ";
        break;
    case for_loop:
        std::cout << "loop statement(for): ";
        break;
    }
}

AST::LoopNode::~LoopNode() {
    if (this->declare) delete declare;
    if (this->cond) delete cond;
    if (this->action) delete action;
}