#ifndef _SYMBOL_H_
#define _SYMBOL_H_
#include <string>
#include <unordered_map>
#include <vector>
#include "../ASTree/RootNode.h"
#include "./SymbolType.h"
#include "../ASTree/VarNode.h"
#include "../ASTree/FuncNode.h"

#define INT_OFFSET 4
namespace SMB {
    class Symbol {
    protected:
        std::string name;
        SMB::SymbolType type;
        int offset;
        int index;

    public:
        Symbol();
        Symbol(std::string name, SMB::SymbolType type);
        const std::string getName();
        SMB::SymbolType getType();
        inline int getOffset() { return offset; }
        inline int getIndex() { return index; }
        inline void setOffset(int offset) { this->offset = offset; }
        inline void setIndex(int index) { this->index = index; }
    };

    class FuncSymbol : public Symbol {
        private:
            std::string dec_name;
            ASTREE::RootNode* arg_list;
            int total_arg_offset;
            SMB::SymbolType rtn_type;
        
        public:
            FuncSymbol();
            FuncSymbol(ASTREE::RootNode* node);
            bool operator==(const FuncSymbol& second);
            inline std::string getDecName() { return this->dec_name; }
            inline int getTotalArgOffset() { return this->total_arg_offset; }
            inline ASTREE::RootNode *getArgList() { return this->arg_list; }
    };

    class StructDefSymbol : public Symbol {
        private:
            std::string stuct_type_name;
        public:
            StructDefSymbol(std::string struct_type_name, std::string id_name);
            inline std::string getTypeName() { return this->stuct_type_name; }
    };

    class StructSymbol : public Symbol {
        private:
            std::unordered_map<std::string, int> offset_table;
            int total_member_offset;

        public:
            StructSymbol();
            StructSymbol(std::string name, ASTREE::RootNode* node);
            inline int getTotalMemberOffset() { return this->total_member_offset; }
            int getMemberOffset(std::string member_name);
    };

    class StructTable{
        private:
            std::unordered_map<std::string, StructSymbol*> struct_hash_table;
            static int num;
        public:
            StructTable();
            StructSymbol *findStruct(std::string id_name);
            bool addStruct(StructSymbol *curr_struct);
    };

    class SymbolTable {
        private:
            std::unordered_map<std::string, Symbol*> symbol_hash_map;
            std::vector<Symbol *> *arg_list;
            std::vector<Symbol*> *symbol_list;
            SymbolTable *parent_table;
            SymbolTable *child_table;
            SymbolTable *cousin_table;
            StructTable *struct_list;
            int total_symbol_count;
            int total_offset;
            int total_arg_offset;                     // ???????????????  
            bool is_func;
            SymbolTable *root_table;
            static SymbolTable *global_table;
            std::string table_name;
            
            Symbol *findInTable(const std::string name);
            //void visitFuncArgs(AbstractASTNode *arg, int &offset, int &index);
        
        public:
            static const int SUCCESS=1;
            static const int FAIL=0;
            SymbolTable();
            SymbolTable(SymbolTable*, bool);
            SymbolTable(bool, StructTable*);
            int addSymbol(ASTREE::RootNode *node);
            int addFuncSymbol(FuncSymbol *func_symbol);
            int addStructSymbol(std::string, std::string);
            int addArraySymbol(ASTREE::RootNode *array_node);
            void addFromFunctionArgs(FuncSymbol *func);
            SymbolTable* createChildTable(bool);

            Symbol* findSymbol(const std::string name);
            inline void setChild(SymbolTable* child) { this->child_table = child; };
            inline void setParent(SymbolTable* parent) { this->parent_table = parent; };
            inline void setTableName(std::string name) { this->table_name = name; }

            inline SymbolTable* getParent() { return this->parent_table; };
            inline SymbolTable* getChild() { return this->child_table; };
            inline SymbolTable* getCousin() { return this->cousin_table; }
            inline std::string getTableName() { return this->table_name; }
            inline int getTotalOffset() { return this->total_offset; }
            //inline int getArgTotalOffset() { return this->argTotalOffset; }
            inline StructTable *getStructTable() { return this->struct_list; }
            inline static void setGlobalTable(SymbolTable *glb) { global_table = glb; }
    };
} // namespace SMB

#endif