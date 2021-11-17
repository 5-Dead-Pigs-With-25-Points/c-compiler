#ifndef SYMBOLTABLETREE_H
#define SYMBOLTABLETREE_H

#include "./ASTree/RootNode.h"
#include "./ASTree/LoopNode.h"
#include "./ASTree/StmtNode.h"
#include "./symbol/symbol.h"

namespace SMB {
    void tree(SymbolTable* table, ASTREE::RootNode* node, int depth);
}

#endif
