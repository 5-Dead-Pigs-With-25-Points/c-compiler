#ifndef _VARNODE_H_
#define _VARNODE_H_

#include "./RootNode.h"
#include "./SymbolType.h"

namespace AST {
    class DefineVarNode : public RootNode {
        private:
            SMB::SymbolType symbol_type;
            int array_length;
            std::string struct_name;    // 结构体名
        public:
            // constructors
            DefineVarNode();
            DefineVarNode(std::string); // 普通变量构造函数
            DefineVarNode(std::string, std::string);    // 结构体变量构造函数

            // getters
            inline SMB::SymbolType getSymbolType() { return this->symbol_type; }
            inline std::string getStructName() { return this->struct_name; }
            inline int getArrayLength() { return this->array_length; }

            //setters
            void setAllSymbolType(std::string);
            inline void setTypeToArray() { this->symbol_type = SMB::array; }
            void setArrayLength(std::string);

            //printers
            void printInfo(int);
    };

    class CallVarNode : public RootNode {
        public:
            // constructors
            CallVarNode();
            CallVarNode(std::string);

            //printer
            void printInfo(int);
    };
}

#endif