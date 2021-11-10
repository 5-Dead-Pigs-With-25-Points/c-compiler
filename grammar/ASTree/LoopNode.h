#ifndef _LOOPNODE_H_
#define _LOOPNODE_H_

#include "./RootNode.h"
#include <string>

namespace ASTREE {

    enum LoopType {
        for_loop = 0,
        while_loop = 1
    };

    class LoopNode: public RootNode {
    private:
        LoopType loop_type;
        RootNode* declare;  // for循环中的第一句
        RootNode* cond; // for循环中的第二句
        RootNode* action;   // for循环中的第三句
    public:
        // constructors
        LoopNode();
        LoopNode(std::string);
        LoopNode(LoopType);
        LoopNode(std::string, LoopType);
        LoopNode(std::string, LoopType, RootNode*); // while循环
        LoopNode(std::string, LoopType, RootNode*, RootNode*, RootNode*); // for循环
        
        // getters
        inline RootNode* getDeclareNode() { return this->declare; }
        inline RootNode* getCondNode() { return this->cond; }
        inline RootNode* getActionNode() { return this->action; }
        inline LoopType getLoopType() { return this->loop_type; }
        
        // printer
        void printInfo(int);

        // deconstructor
        ~LoopNode();
    };
    
}


#endif