#ifndef _OPERATORNODE_H_
#define _OPERATORNODE_H_

#include "./RootNode.h"
#include <string>

namespace AST {

    enum OpType {
        none = 0,   
        
        add = 1,    // +
        minus = 2,  // -
        multi = 3,  // *
        div = 4,    // /
        mod = 5,    // %

        and = 6, // &&
        or = 7,  // ||
        not = 8, // !

        relop = 9, // == | != | >= | <= | > | < 

        get_address = 10, // &
        get_value = 11,// *

        assign = 12, // =
    };
    
    class OperatorNode: public RootNode {
        private:
            OpType op_type;
        public:
            // constructors
            OperatorNode();
            OperatorNode(std::string);
            OperatorNode(std::string, OpType);

            // getter
            inline OpType getOpType() {return this->op_type;}
            
            //setters
            inline void setOpType(OpType type) { this->op_type = type;}
            void setAllSymbolType(std::string);
            
            //printer
            void printInfo(int);
    };

}


#endif