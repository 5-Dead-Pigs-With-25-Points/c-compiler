#ifndef _LITERALNODE_H_
#define _LITERALNODE_H_

#include "./RootNode.h"
#include <string>

namespace ASTREE {
    
    class LiteralNode: public RootNode {
        public:
            // constructors
            LiteralNode();
            LiteralNode(std::string);

            // getter
            int getValue();

            // printer
            void printInfo(int);
    };

}


#endif