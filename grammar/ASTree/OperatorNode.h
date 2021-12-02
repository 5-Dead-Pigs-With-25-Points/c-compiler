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

        negative = 18, // -
        
        before_dplus = 19, // ++i
        after_dplus = 20, // i++
        before_dminus = 21, // --i
        after_dminus = 22, // i--
        multi_assign = 23, // *=
        div_assign = 24, // /=
        plus_assign = 25, // +=
        minus_assign = 26, // -=
        multi_assign_arr = 27, // []*=
        multi_assign_member = 28, // a.b *=
        div_assign_arr = 29, // []/=
        div_assign_member = 30, // a.b /=
        plus_assign_arr = 31, // [] +=
        plus_assign_member = 32, // a.b +=
        minus_assign_arr = 33, // [] -=
        minus_assign_member = 34, // a.b -=
        
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
