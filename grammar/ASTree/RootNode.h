#ifndef _ROOTNODE_H_
#define _ROOTNODE_H_

#include<iostream>
#include<string>
#include<vector>

namespace AST {
    enum ASTNodeType {
        root = 0, // 根节点
        def_var = 1, // 定义变量 
        call_var = 2, // 调用变量
        def_func = 3, // 定义函数
        call_func = 4, // 调用函数
        op = 5, // 操作符
        stmt = 6, // 语句
        loop = 7, // 循环类型
        select = 8, // 选择类型
        literal = 9 // 字面量
    };

    static std::string prefix[2] = {"└─ ", "├─ "};
    static std::string separator[2] = {"│  ", "   "};

    class RootNode {
        private:
            ASTNodeType type;
            RootNode *parent;
            RootNode *child;
            RootNode *peer;

        protected:
            std::string content;
            static void tree(RootNode*, int, bool, std::vector<bool>, std::string="");

        public:
            // constructor
            RootNode();
            RootNode(ASTNodeType); // 只传入节点类型
            RootNode(std::string, ASTNodeType); // 传入节点类型与内容
            RootNode(std::string); // 只传入节点内容

            // setters
            inline void setParentNode(RootNode *parent) { this->parent = parent; } // 设置父节点
            void addChildNode(RootNode*); // 添加孩子节点
            void addPeerNode(RootNode*); // 添加兄弟节点

            // getters
            RootNode *getLastPeerNode(); // 返回最后的兄弟节点
            inline ASTNodeType getASTNodeType() { return this->type; } // 返回节点类型
            inline std::string getContent() { return this->content; } // 返回节点内容
            inline RootNode* getChildNode() { return this->child; } // 返回孩子节点
            inline RootNode* getParentNode() { return this->parent; } // 返回父节点
            inline RootNode* getPeerNode() { return this->peer; } // 返回兄弟节点

            // printers
            void printTree(); // 输出以当前节点为根节点的子树
            virtual void printInfo(int); // 输出节点信息

            // deconstructor
            virtual ~RootNode();
    };
}

#endif