#include "./RootNode.h"
#include "./LoopNode.h"
#include "./SelectNode.h"

AST::RootNode::RootNode() {
    this->child = NULL;
    this->parent = NULL;
    this->peer = NULL;
    this->content = "code start:";
}

AST::RootNode::RootNode(std::string content) {
    this->child = NULL;
    this->parent = NULL;
    this->peer = NULL;
    this->content = content;
}

AST::RootNode::RootNode(ASTNodeType type) {
    this->child = NULL;
    this->parent = NULL;
    this->peer = NULL;
    this->type = type;
    this->content = "";
}

AST::RootNode::RootNode(std::string content, ASTNodeType type) {
    this->child = NULL;
    this->parent = NULL;
    this->peer = NULL;
    this->type = type;
    this->content = content;
}

void AST::RootNode::addPeerNode(AST::RootNode* node) {
    this->peer = node;
    if (node) {
        node->parent = this->parent;
    }
}

void AST::RootNode::addChildNode(AST::RootNode* node) {
    this->child = node;
    // 遍历新node的所有peer
    // peer->parent = this
    while(node) {
        node->parent = this;
        node = node->peer;
    }
}

void AST::RootNode::printInfo(int depth) {
    /* while(depth) {
        std::cout << "   ";
        depth--;
    } */
    std::cout << this->content;
}

void AST::RootNode::tree(AST::RootNode* node, int depth, bool flag, std::vector<bool> pre_sep, std::string prefix_str) {
    for (std::vector<bool>::iterator i = pre_sep.begin(); i != pre_sep.end(); i++) {
        std::cout << separator[*i];
    }
    std::cout << prefix[!flag] << prefix_str;
    node->printInfo(depth);
    std::cout << std::endl;
    ++depth;
    pre_sep.push_back(flag);

    // 打印循环
    if (node->getASTNodeType() == AST::loop) {
        bool f = node->child;
        LoopNode* loop_node = (LoopNode*)node;
        RootNode* tmp = loop_node->getDeclareNode();
        if(tmp)AST::RootNode::tree(tmp, depth, !f, pre_sep, "(declare): ");
        tmp = loop_node->getCondNode();
        if(tmp)AST::RootNode::tree(tmp, depth, !f, pre_sep, "(condition): ");
        tmp = loop_node->getActionNode();
        if(tmp)AST::RootNode::tree(tmp, depth, !f, pre_sep, "(action): ");
    }
    
    // 打印选择
    if (node->getASTNodeType() == AST::select) {
        SelectNode *select_node = (SelectNode*)node;
        RootNode *tmp = select_node->getCondNode();
        bool f = select_node->getBodyNode();
        if(tmp)AST::RootNode::tree(tmp, depth, !f, pre_sep, "(condition): ");
        tmp = select_node->getBodyNode();
        if(tmp)AST::RootNode::tree(tmp, depth, true, pre_sep, "(body): ");
    }

    node = node->child;
    while(node) {
        bool f = node->peer;
        AST::RootNode::tree(node, depth, !f, pre_sep);
        node = node->peer;
    }
}

void AST::RootNode::printTree() {
    std::vector<bool> v(0);
    AST::RootNode::tree(this, 1, true, v);
}

AST::RootNode* AST::RootNode::getLastPeerNode() {
    AST::RootNode* node = this;
    while(node->peer) {
        node = node->peer;
    }
    return node;
}

AST::RootNode::~RootNode() {
    if (this->peer) {
        delete this->peer;
    }
    if (this->child) {
        delete this->child;
    }
}
// for test
int main() {
     AST::RootNode* r[11];
     for (int i = 0; i < 11; i++) {
         char* a = (char*)malloc(sizeof(char) * 5);
         sprintf(a, "%d", i + 1);
         r[i] = new AST::RootNode(a);
     }
     r[0]->addChildNode(r[1]);
     r[1]->addChildNode(r[2]);
     r[1]->addPeerNode(r[3]);
     r[3]->addChildNode(r[4]);
     r[3]->addPeerNode(r[5]);
     r[5]->addChildNode(r[6]);
     r[5]->addPeerNode(r[9]);
     r[4]->addPeerNode(r[7]);
     r[7]->addChildNode(r[8]);
     r[6]->addPeerNode(r[10]);
     r[0]->printTree();
     return 0;
 }