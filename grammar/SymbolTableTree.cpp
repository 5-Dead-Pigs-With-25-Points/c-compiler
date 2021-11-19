#include "SymbolTableTree.h"

void SMB::tree(SMB::SymbolTable* table, ASTREE::RootNode* node, int depth){
    if (!node) return;
    if (node->getASTNodeType() == ASTREE::def_var){
        if(table->addSymbol(node) == 0){
            std::cout << "\033[31mError: \033[0m"
              << "value " << node->getContent() << " is redeclaration" << std::endl;
            exit(1);
        }
    } else if (node->getASTNodeType() == ASTREE::def_func){
        SMB::FuncSymbol* func_node = new SMB::FuncSymbol(node);
        if (table->addFuncSymbol(func_node) == 0){
            std::cout << "\033[31mError: \033[0m"
              << "function " << func_node->getDecName() << " is redeclaration" << std::endl;
            exit(1);
        } else {
            SMB::SymbolTable* child_table = table->createChildTable(true);
            child_table->setTableName(func_node->getDecName());
            child_table->addFromFunctionArgs(func_node);
            tree(child_table,node->getChildNode(), depth + 1);
            tree(table,node->getPeerNode(), depth);
            return;
        }
    } else if (node->getASTNodeType() == ASTREE::select) {
        SMB::SymbolTable* child_table = table->createChildTable(false);
        child_table->setTableName("select");
        
        ASTREE::SelectNode *select_node = (ASTREE::SelectNode*) node;
        
        tree(child_table, select_node->getBodyNode(), depth + 1);
        tree(table,node->getPeerNode(), depth);
        return;
        }
        else if (node->getASTNodeType() == ASTREE::loop) {
        ASTREE::LoopNode *loop_node = (ASTREE::LoopNode*) node;
        SMB::SymbolTable* child_table = table->createChildTable(false);
        child_table->setTableName("loop");
        ASTREE::RootNode *dec = loop_node->getDeclareNode();
        if (dec) {
            if (dec->getASTNodeType() == ASTREE::op) {
                dec = dec->getChildNode();
            }
            if (dec->getASTNodeType() == ASTREE::def_var) {
                child_table->addSymbol(dec);
            }
        }
        tree(child_table,node->getChildNode(), depth + 1);
        tree(table,node->getPeerNode(), depth);
        return;
    }
    tree(table,node->getChildNode(), depth + 1);
    tree(table,node->getPeerNode(), depth);
}
