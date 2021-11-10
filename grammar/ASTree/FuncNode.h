#ifndef _FUNCNODE_H_
#define _FUNCNODE_H_

#include "./RootNode.h"
#include "../symbol/SymbolType.h"
#include<string>

namespace ASTREE {
    class DefineFunctionNode : public RootNode {
        private:
            RootNode* arg_list;
            SMB::SymbolType return_symbol_type;
        public:
            // constructors
            DefineFunctionNode();
            DefineFunctionNode(std::string);
            DefineFunctionNode(std::string, RootNode*);

            // getters
            inline RootNode* getArgList() { return this->arg_list; }
            inline SMB::SymbolType getReturnSymbolType() { return this->return_symbol_type; }

            // setters
            void setReturnSymbolType(std::string);
            void printInfo(int);

            // deconstructor
            ~DefineFunctionNode();
    };

    class CallFuncNode : public RootNode {
        private:
            RootNode* arg_list;
        public:
            // constructors
            CallFuncNode();
            CallFuncNode(std::string);

            // getter
            inline RootNode* getArgList() { return this->arg_list; }

            // setter
            inline void setArgList(RootNode* v) { this->arg_list = v; v->setParentNode(this); }

            //printer
            void printInfo(int);

            // deconstructor
            ~CallFuncNode();
    };
}

#endif
