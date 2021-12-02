#if !defined(_INTERMEDIATE_H_)
#define _INTERMEDIATE_H_

#include "../Nodes.h"
#include "./Quaternion.h"
#include <stack>
#include <list>

namespace IM {

class InterMediate {
private:
    ASTREE::RootNode *root;
    std::vector<Quaternion> quads;
    std::vector<SMB::Symbol*> tempVars;
    // FuncTable funcTable;
    SMB::SymbolTable *rootSymbolTable;

    std::stack< std::list<int> > trueList;
    std::stack< std::list<int> > falseList;
    std::stack<int> signal;
    std::stack<SMB::Symbol*> childValue;
    // Function for backPatch.
    std::list<int> *makeList(int index);
    std::list<int> *merge(std::list<int> *list1, std::list<int> *list2);
    void backPatch(std::list<int> *backList, int target);

    void buildInFunctionRegister();

    // typecheck:
    void typeCheck(OperatorCode, SMB::Symbol*, SMB::Symbol*);
    

public:
    inline ASTREE::RootNode *getRoot() { return this->root; }
    inline SMB::SymbolTable *getTable() { return this->rootSymbolTable; }
    // inline FuncTable &getFuncTable() { return this->funcTable; }
    inline std::vector<Quaternion> &getQuads() { return this->quads; }
    inline std::vector<SMB::Symbol*> &getTempVars() { return this->tempVars; }
    InterMediate(ASTREE::RootNode *rootNode, SMB::StructTable*);
    void generate(ASTREE::RootNode *node, SMB::SymbolTable*);
    // Create a child symbol table to generate follow code.
    SMB::SymbolTable *generateStatement(ASTREE::StatementNode*, SMB::SymbolTable*);
    void generateReturn(ASTREE::StatementNode*, SMB::SymbolTable*);
    SMB::Symbol *generateOperator(ASTREE::OperatorNode*, SMB::SymbolTable*);
    Quaternion *caculateOperator(OperatorCode, ASTREE::RootNode*, ASTREE::RootNode*, SMB::Symbol*, SMB::SymbolTable*);
    void relopOperator(Quaternion*, Quaternion*, OperatorCode, ASTREE::RootNode*, ASTREE::RootNode*, SMB::SymbolTable*);
    void print();
};

} // namespace IM


#endif
