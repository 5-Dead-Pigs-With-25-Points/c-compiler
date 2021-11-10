#ifndef _OPERATORNODE_H_
#define _OPERATORNODE_H_

#include "./RootNode.h"
#include <string>

namespace ASTREE {

    enum OpType {
        none = 0,   
        
        add = 1,    // +
        minus = 2,  // -
        multi = 3,  // *
        div = 4,    // /
        mod = 5,    // %
        pow = 6,    // ^

        and_op = 7, // &&
        or_op = 8,  // ||
        not_op = 9, // !

        relop = 10, // == | != | >= | <= | > | < 

        get_address = 11, // &
        get_value = 12,// *

        assign = 13, // =

        get_arr_var = 14, // []
        get_member = 15, // a.b
        assign_arr = 16, // []=
        assign_member = 17, // a.b=

        negative = 18 // -
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