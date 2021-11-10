#ifndef _SELECTNODE_H_
#define _SELECTNODE_H_

#include "./RootNode.h"
#include <string>

namespace AST {
    
    enum SelectType {
        if_stmt = 0,
        else_stmt = 1,
        else_if_stmt = 2
    };

    class SelectNode: public RootNode {
    private: 
        SelectType select_type;
        RootNode *cond;
        RootNode *body;
        RootNode *else_node;
    public:
        // constructors
        SelectNode();
        SelectNode(std::string);
        SelectNode(SelectType);
        SelectNode(std::string, SelectType);
        SelectNode(std::string, SelectType, RootNode*, RootNode*); // if / else if
        SelectNode(std::string, SelectType, RootNode*); // else
        
        // getters
        inline SelectType getSelectType() { return this->select_type; }
        inline RootNode *getCondNode() { return this->cond; }
        inline RootNode *getBodyNode() { return this->body; }
        inline RootNode *getElse() { return this->else_node; }
        
        // setters
        inline void setCondNode(RootNode* c) { this->cond = c; c->setParentNode(this); }
        inline void setBodyNode(RootNode* b) { this->body = b; b->setParentNode(this); }
        inline void setElseNode(RootNode* e) { this->else_node = e; e->setParentNode(this); }
        
        // printer
        void printInfo(int);
        
        // deconstructor
        ~SelectNode();
    };
}

#endif