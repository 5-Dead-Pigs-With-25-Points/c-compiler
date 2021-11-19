#include "./LoopNode.h"

ASTREE::LoopNode::LoopNode() : RootNode(ASTREE::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
}

ASTREE::LoopNode::LoopNode(std::string content) : RootNode(content, ASTREE::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
}

ASTREE::LoopNode::LoopNode(LoopType tp) : RootNode(ASTREE::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
    this->loop_type = tp;
}

ASTREE::LoopNode::LoopNode(std::string content, LoopType tp) : RootNode(content, ASTREE::ASTNodeType::loop) {
    this->cond = NULL;
    this->declare = NULL;
    this->action = NULL;
    this->loop_type = tp;
}

// whileѭ��
ASTREE::LoopNode::LoopNode(std::string content,
    LoopType loop_type,
    RootNode* condition)
    : RootNode(content, ASTREE::loop) {
    this->loop_type = loop_type;
    this->cond = condition;
    condition->setParentNode(this);
    this->declare = NULL;
    this->action = NULL;
}

// forѭ��
ASTREE::LoopNode::LoopNode(std::string content,
    LoopType loop_type,
    RootNode* cond,
    RootNode* dec,
    RootNode* action)
    : RootNode(content, ASTREE::loop) {
    this->loop_type = loop_type;
    this->cond = cond;
    if(cond != NULL){
	    cond->setParentNode(this);
    }
    this->declare = dec;
    if(dec != NULL){
	    dec->setParentNode(this);
	}
    this->action = action;
    if (action !=NULL){
	    action->setParentNode(this);
	}
}

void ASTREE::LoopNode::printInfo(int) {
    switch (this->loop_type) {
    case while_loop:
        std::cout << "loop statement(while): ";
        break;
    case for_loop:
        std::cout << "loop statement(for): ";
        break;
    }
}

ASTREE::LoopNode::~LoopNode() {
    if (this->declare) delete declare;
    if (this->cond) delete cond;
    if (this->action) delete action;
}
