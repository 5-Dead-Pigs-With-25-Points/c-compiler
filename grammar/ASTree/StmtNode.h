#ifndef _STATEMENTNODE_H_
#define _STATEMENTNODE_H_

#include "./RootNode.h"
#include <string>

namespace AST {

    enum StatementType {
        compoundation = 0, // 语句块
        comparison = 1, // 比较语句
        definition = 2, // 定义语句
        return_stmt = 3, // 返回语句
        expression = 4 // 表达式语句
    };

    class StatementNode: public RootNode {
    private:
        StatementType stmt_type;
    public:
        // constructors
        StatementNode();
        StatementNode(StatementType);
        StatementNode(std::string);
        StatementNode(std::string, StatementType);

        // getter
        inline StatementType getStmtType() {return this->stmt_type;}
        
        // printer
        void printInfo(int); 
    };
} 

#endif 