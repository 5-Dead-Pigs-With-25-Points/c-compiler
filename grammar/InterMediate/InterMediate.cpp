#include "./InterMediate.h"
#include <typeinfo>
#include <cstdio>
IM::InterMediate::InterMediate(ASTREE::RootNode *root_node, SMB::StructTable *struct_table) {
    tempVars.reserve(100);
    this->root = root_node;
    this->rootSymbolTable = new SMB::SymbolTable(false, struct_table);
    SMB::SymbolTable::setGlobalTable(this->rootSymbolTable);
    // std::cout << "rootSymbolTable: " << this->rootSymbolTable << std::endl;
    // std::cout << "struct_table: " << struct_table << std::endl;
    this->buildInFunctionRegister();
}

void IM::InterMediate::buildInFunctionRegister() {
    ASTREE::DefineVarNode  *tmp_arg;
    ASTREE::DefineFunctionNode *tmp_func;
    SMB::FuncSymbol *func_symbol;

    // print_int
    tmp_arg = new ASTREE::DefineVarNode("i");
    tmp_arg->setAllSymbolType("int");
    tmp_func = new ASTREE::DefineFunctionNode("print_int", tmp_arg);
    tmp_func->setReturnSymbolType("void");
    func_symbol = new SMB::FuncSymbol(tmp_func);
    this->rootSymbolTable->addFuncSymbol(func_symbol);

}

void IM::InterMediate::generate(ASTREE::RootNode *node, SMB::SymbolTable *symbol_table) {
    if (node == NULL) {
        std::cout << "node is NULL" << std::endl;
        return;
    }
    ASTREE::RootNode *p = node->getChildNode();
    switch (node->getASTNodeType()) {
    case ASTREE::def_func: {
        // 主要负责生成函数声明的四元组，以及表示函数结束的四元组
        // 中间部分继续调用generate()
        SMB::FuncSymbol *func = new SMB::FuncSymbol(node);
        this->rootSymbolTable->addFuncSymbol(func);
        Quaternion *temp;
        // 不懂为什么是void_type
        SMB::Symbol *temp_symbol = new SMB::Symbol(func->getDecName(), SMB::void_type);
        temp = new Quaternion(IM::FUNC_DEF, temp_symbol, (SMB::Symbol *)NULL);
        this->quads.push_back(*temp);
        while (p != NULL) {
            SMB::SymbolTable *child_table = symbol_table->createChildTable(true);
            child_table->setTableName(func->getDecName());
            child_table->addFromFunctionArgs(func);
            generate(p, child_table);
            p = p->getPeerNode();
        }
        temp = new Quaternion(IM::END_FUNCTION, (SMB::Symbol *)NULL, (SMB::Symbol *)NULL);
        this->quads.push_back(*temp);
        break;
    }
    case ASTREE::call_func: {
        // 先写出参数的四元组，再写调用函数的整体四元组
        int count = 0;
        ASTREE::RootNode *var = ((ASTREE::CallFuncNode*)node)->getArgList();
        std::string add_on = "";
        while (var != NULL) {
            count = count + 1;
            Quaternion *temp;
            if (var->getASTNodeType() == ASTREE::call_var) {
                // std::cout<<"var_content: "<<var->getContent()<<std::endl;
                SMB::Symbol *arg1 = symbol_table->findSymbol(var->getContent());
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol *)NULL);
                // std::cout<<"arg1_name: "<<arg1->getName()<<" arg1_type: "<<arg1->getType()<<std::endl;
                switch (arg1->getType()) {
                case SMB::integer:
                    add_on = add_on + "_i";
                    break;
                case SMB::pointer:
                    add_on = add_on + "_p";
                    break;
                default:
                    std::cout << "Wrong Type!\n";
                    break;
                }
            } else if (var->getASTNodeType() == ASTREE::literal) {
                int arg1 = std::stoi(var->getContent());
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
                add_on = add_on + "_i";
            } else if (var->getASTNodeType() == ASTREE::op) {
                SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode*)var, symbol_table);
                // std::cout << "generate op finished!\n";
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
                switch (arg1->getType()) {
                case SMB::integer:
                    add_on = add_on + "_i";
                    break;
                case SMB::pointer:
                    add_on = add_on + "_p";
                    break;
                default:
                    break;
                }
            }
            this->quads.push_back(*temp);
            var = var->getPeerNode();
        }
        SMB::FuncSymbol *fun_sym = (SMB::FuncSymbol*)this->rootSymbolTable->findSymbol(node->getContent() + add_on);
        if (fun_sym == NULL) {
            std::cout << "\033[31mError: \033[0m"
                      << " function is not decleared." << std::endl;
            exit(1);
        }
        SMB::Symbol *func_symbol = new SMB::Symbol(fun_sym->getDecName(), SMB::void_type);
        // SMB::Symbol *func_symbol = new SMB::Symbol(fun_sym->getFunName(), SMB::void_type);
        SMB::Symbol *temp_v = NULL;
        // 为什么要去看函数的父节点的类型？
        if (node->getParentNode()->getASTNodeType() == ASTREE::stmt) {
            ASTREE::StatementNode *stmt = (ASTREE::StatementNode *)node->getParentNode();
            if (stmt->getStmtType() == ASTREE::expression) {
                temp_v = NULL;
            }
            else {
                temp_v = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
                tempVars.push_back(temp_v);
            }
        }
        else {
            temp_v = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
            tempVars.push_back(temp_v);
        }

        Quaternion *temp = new Quaternion(IM::CALL, func_symbol, count, temp_v);
        this->quads.push_back(*temp);
    }
    case ASTREE::literal: {
        if (node->getParentNode()->getASTNodeType() == ASTREE::op) {
            ASTREE::OperatorNode *par = (ASTREE::OperatorNode *)node->getParentNode();
            if (par->getOpType() == ASTREE::and_op 
             || par->getOpType() == ASTREE::or_op 
             || par->getOpType() == ASTREE::not_op) 
            {
                Quaternion *true_quad = new Quaternion(IM::JUMP_GREAT, std::stoi(node->getContent()), 0, (int)NULL);
                Quaternion *false_quad = new Quaternion(IM::JUMP, (int)NULL);
                std::list<int> true_l;
                true_l.push_back(quads.size());
                this->quads.push_back(*true_quad);
                std::list<int> false_l;
                false_l.push_back(quads.size());
                this->quads.push_back(*false_quad);
                trueList.push(true_l);
                falseList.push(false_l);
            }
        }
        break;
    }
    case ASTREE::op: {
        if (((ASTREE::OperatorNode*)node)->getOpType() == ASTREE::and_op 
        || ((ASTREE::OperatorNode *)node)->getOpType() == ASTREE::or_op)
        {
            generate(p, symbol_table);
            signal.push(quads.size());
            generate(p->getPeerNode(), symbol_table);
        }
        else if (((ASTREE::OperatorNode*)node)->getOpType() == ASTREE::not_op 
             || ((ASTREE::OperatorNode *)node)->getOpType() == ASTREE::relop)
        {
            while (p != NULL) {
                generate(p, symbol_table);
                p = p->getPeerNode();
            }
        }
        this->generateOperator((ASTREE::OperatorNode *)node, symbol_table);
        break;
    }
    case ASTREE::stmt: {
        ASTREE::StatementNode *ret = (ASTREE::StatementNode *)node;
        if (ret->getStmtType() == ASTREE::return_stmt) {
            generateReturn((ASTREE::StatementNode *)node, symbol_table);
        }
        else {
            while (p != NULL) {
                generate(p, this->generateStatement((ASTREE::StatementNode *)node, symbol_table));
                p = p->getPeerNode();
            }
        }
        break;
    }
    case ASTREE::def_var: {
        ASTREE::DefineVarNode *temp_node = (ASTREE::DefineVarNode*)node;
        if (temp_node->getSymbolType() == SMB::struct_type) {
            // TODO: addStructSymbol
            if (symbol_table->addStructSymbol(temp_node->getStructName(), temp_node->getContent()) == 0) {
                std::cout << "\033[31mError: \033[0m"
                << "struct " << temp_node->getStructName() << " is not defined" << std::endl;
                exit(1);
            }
        } else if (temp_node->getSymbolType() == SMB::array) {
            symbol_table->addArraySymbol(temp_node);
        } else {
            if(symbol_table->addSymbol(node) == 0){
                std::cout << "\033[31mError: \033[0m"
                << "value " << node->getContent() << " is redeclaration" << std::endl;
                exit(1);
            }
        }
        SMB::Symbol *var_symbol = symbol_table->findSymbol(node->getContent());
        if (p != NULL) {
            Quaternion *temp;
            if (p->getASTNodeType() == ASTREE::literal) {
                int arg1 = std::stoi(p->getContent());
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else if (p->getASTNodeType() == ASTREE::call_var) {
                SMB::Symbol *arg1 = symbol_table->findSymbol(p->getContent());
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else if (p->getASTNodeType() == ASTREE::op) {
                SMB::Symbol *arg1 = this->generateOperator((ASTREE::OperatorNode *)p, symbol_table);
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else if (p->getASTNodeType() == ASTREE::call_func) {
                generate(p, symbol_table);
                SMB::Symbol *arg1 = tempVars.back();
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            this->quads.push_back(*temp);
        }
        break;
    }
    case ASTREE::call_var: {
        std::cout<<"call_var"<<std::endl;
        if (node->getParentNode()->getASTNodeType() == ASTREE::op) {
            ASTREE::OperatorNode *par = (ASTREE::OperatorNode *)node->getParentNode();
            if (par->getOpType() == ASTREE::and_op 
             || par->getOpType() == ASTREE::or_op 
            || par->getOpType() == ASTREE::not_op)
            {
                SMB::Symbol *arg1 = symbol_table->findSymbol(node->getContent());
                Quaternion *true_quad = new Quaternion(IM::JUMP_GREAT, arg1, 0, (int)NULL);
                Quaternion *false_quad = new Quaternion(IM::JUMP, (int)NULL);
                std::list<int> trueL;
                trueL.push_back(quads.size());
                this->quads.push_back(*true_quad);
                std::list<int> falseL;
                falseL.push_back(quads.size());
                this->quads.push_back(*false_quad);
                trueList.push(trueL);
                falseList.push(falseL);
            }
        }
        break;
    }
    case ASTREE::loop: // for(1.DefASTNODE, 2.OperatorASTNODE, 3.OperatorASTNODE, 4.StmtASTNODE)
    {
        ASTREE::LoopNode *loop = (ASTREE::LoopNode*)node;
        if (loop->getLoopType() == ASTREE::for_loop) {
            SMB::SymbolTable *child_table = symbol_table->createChildTable(false);
            child_table->setTableName("for");
            generate(((ASTREE::LoopNode*)node)->getDeclareNode(), child_table);
            int start = quads.size();
            generate(((ASTREE::LoopNode*)node)->getCondNode(), child_table);
            std::list<int> Judge_true = trueList.top();
            std::list<int> Judge_false = falseList.top();
            trueList.pop();
            falseList.pop();
            backPatch(&Judge_true, Judge_true.back() + 2);
            while (p != NULL)
            {
                generate(p, child_table);
                p = p->getPeerNode();
            }
            generate(((ASTREE::LoopNode*)node)->getActionNode(), child_table);

            Quaternion *temp = new Quaternion(IM::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backPatch(&Judge_false, end);
        }
        else if (loop->getLoopType() == ASTREE::while_loop)
        {
            int start = quads.size();
            generate(((ASTREE::LoopNode*)node)->getCondNode(), symbol_table);
            std::list<int> Judge_true = trueList.top();
            std::list<int> Judge_false = falseList.top();
            trueList.pop();
            falseList.pop();
            backPatch(&Judge_true, Judge_true.back() + 2);
            while (p != NULL) {
                SMB::SymbolTable *child_table = symbol_table->createChildTable(false);
                child_table->setTableName("while");
                generate(p, child_table);
                p = p->getPeerNode();
            }

            Quaternion *temp = new Quaternion(IM::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backPatch(&Judge_false, end);
        }
        break;
    }
    case ASTREE::select: // Just IF and ELSE.
    {
        ASTREE::SelectNode *select = (ASTREE::SelectNode*)node;
        generate(select->getCondNode(), symbol_table);
        // std::cout << "generate finished!\n";
        int start = quads.size();
        std::cout << "trueList pop!\n";
        std::list<int> Judge_true = trueList.top();
        std::list<int> Judge_false = falseList.top();
        trueList.pop();
        falseList.pop();

        backPatch(&Judge_true, start);
        // Body:
        // std::cout << "body: " << select->getBodyNode() << "\n";
        generate(select->getBodyNode(), symbol_table);
        if (select->getElse() != NULL) {
            // std::cout << "else if\n";
            Quaternion *temp = new Quaternion(IM::JUMP, (int)NULL);
            this->quads.push_back(*temp);
            temp = &quads.back();
            int else_start = quads.size();
            generate(select->getElse(), symbol_table);
            // std::cout << "generate finished\n";
            backPatch(&Judge_false, else_start);
            int end = quads.size();
            temp->backPatch(end);
        } else {
            int end = quads.size();
            backPatch(&Judge_false, end);
        }
        break;
    }
    case ASTREE::root: {
        while (p != NULL) {
            generate(p, symbol_table);
            p = p->getPeerNode();
        }
        break;
    }
    default:
        std::cout << "Hello! Something Wrong happened!\n";
        break;
    }
    return;
}

SMB::SymbolTable *IM::InterMediate::generateStatement(ASTREE::StatementNode *node, SMB::SymbolTable *symbol_table) {
    switch (node->getStmtType()) {
    case ASTREE::comparison: {
        if (node->getParentNode()->getASTNodeType() == ASTREE::loop)
            return symbol_table;
        if (node->getParentNode()->getASTNodeType() == ASTREE::def_func)
            return symbol_table;
        SMB::SymbolTable *child_table = symbol_table->createChildTable(false);
        child_table->setTableName("comparation");
        return child_table;
    }
    break;
    default:
        break;
    }
    return symbol_table;
}

SMB::SymbolTable *IM::InterMediate::generateReturn(ASTREE::StatementNode *node, SMB::SymbolTable *symbol_table)
{
    ASTREE::RootNode *p = node->getChildNode();
    Quaternion *temp;
    SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
    tempVars.push_back(result);
    if (p == NULL) {
        temp = new Quaternion(IM::RETURN, (SMB::Symbol *)NULL, (SMB::Symbol *)NULL, (SMB::Symbol *)NULL);
    }
    else if (p->getASTNodeType() == ASTREE::literal) {
        int arg1 = std::stoi(p->getContent());
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == ASTREE::call_var) {
        SMB::Symbol *arg1 = symbol_table->findSymbol(p->getContent());
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == ASTREE::op) {
        SMB::Symbol *arg1 = this->generateOperator((ASTREE::OperatorNode *)p, symbol_table);
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == ASTREE::call_func) {
        generate(p, symbol_table);
        SMB::Symbol *arg1 = tempVars.back();
        temp = new Quaternion(IM::RETURN, arg1, (SMB::Symbol *)NULL);
    }
    else {
        std::cout << "\033[31mError: \033[0m"
                  << "Type error" << std::endl;
        exit(1);
    }
    quads.push_back(*temp);
}

SMB::Symbol *IM::InterMediate::generateOperator(ASTREE::OperatorNode *node, SMB::SymbolTable *symbol_table)
{
    std::cout << "op begin, type: " << node->getOpType() << "\n";
    Quaternion *temp;
    ASTREE::RootNode *arg1_node, *arg2_node;
    switch (node->getOpType()) {
    case ASTREE::assign: {
        std::cout<<"assign\n";
        SMB::Symbol *result;
        IM::OperatorCode op;
        if (node->getChildNode()->getASTNodeType() == ASTREE::op 
        && ((ASTREE::OperatorNode *)node->getChildNode())->getOpType() == ASTREE::get_value)
        {
            op = IM::ASSIGN_POINTER;
            result = symbol_table->findSymbol(node->getChildNode()->getChildNode()->getContent());
            
        }
        else {
            op = IM::ASSIGN;
            if (node->getChildNode()->getASTNodeType() != ASTREE::call_var
            &&  node->getChildNode()->getASTNodeType() != ASTREE::def_var) {
                std::cout << "\033[31mError: \033[0m"
                          << "node_type:"<<node->getChildNode()->getASTNodeType()
                          << node->getChildNode()->getContent() << " is not a variable. What are u doing?" << std::endl;
                exit(1);
            } else if (node->getChildNode()->getASTNodeType() == ASTREE::def_var) {
                if(symbol_table->addSymbol(node->getChildNode()) == 0){
                    std::cout << "\033[31mError: \033[0m"
                    << "value " << node->getChildNode()->getContent() << " is redeclaration" << std::endl;
                    exit(1);
                }
            }
            result = symbol_table->findSymbol(node->getChildNode()->getContent());
        }

        ASTREE::RootNode *arg1_node = node->getChildNode()->getPeerNode();
        std::cout<<"t = "<<arg1_node->getASTNodeType()<<std::endl;
        if (arg1_node->getASTNodeType() == ASTREE::call_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            std::cout<<"getTypeName: "<<arg1->getName()<<std::endl;
            // if (result->getType() == SMB::integer && arg1->getType() == SMB::pointer) {
            //     std::cout << "\033[31mError: \033[0m"
            //               << "Syntax error, maybe you have used the wrong type: " << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
            //     exit(1);
            // } else if (result->getType() == arg1->getType()){
            //     std::cout << "\033[31mError: \033[0m"
            //               << "Type error!" << std::endl;
            //     exit(1);
            // }
            typeCheck(op, result, arg1);
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::op) {
            SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode *)arg1_node, symbol_table);
            typeCheck(op, result, arg1);
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            std::cout << "res type: " << result->getType() << "\n";
            if (result->getType() != SMB::integer) {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error!" << std::endl;
                exit(1);
            }
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = tempVars.back();
            typeCheck(op, result, arg1);
            temp = new Quaternion(op, arg1, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::assign_arr: {
        SMB::Symbol *result;
        if (node->getChildNode()->getASTNodeType() != ASTREE::op) {
            std::cout << "\033[31mError: \033[0m"
                      << node->getContent() << " syntax error. What are u doing?" << std::endl;
        }
        result = generateOperator((ASTREE::OperatorNode *)node->getChildNode(), symbol_table);
        ASTREE::RootNode *arg1_node = node->getChildNode()->getPeerNode();
        SMB::Symbol *arg2 = this->childValue.top();
        this->childValue.pop();
        if (arg1_node->getASTNodeType() == ASTREE::call_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
            // if (result->getType() != arg2->getType()) {
            //     std::cout << "\033[31mError: \033[0m"
            //               << "Type error!" << std::endl;
            //     exit(1);
            // }
        }
        else if (arg1_node->getASTNodeType() == ASTREE::op) {
            SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = tempVars.back();
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);

        return result;
        break;
    }
    case ASTREE::assign_member: {
        std::cout<<"assign_member\n";
        SMB::Symbol *result;
        if (node->getChildNode()->getASTNodeType() != ASTREE::op) {
            std::cout << "\033[31mError: \033[0m"
                      << node->getContent() << " syntax error. What are u doing?" << std::endl;
        }
        result = generateOperator((ASTREE::OperatorNode *)node->getChildNode(), symbol_table);
        ASTREE::RootNode *arg1_node = node->getChildNode()->getPeerNode();
        SMB::Symbol *arg2 = this->childValue.top();
        this->childValue.pop();
        if (arg1_node->getASTNodeType() == ASTREE::call_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        } else if (arg1_node->getASTNodeType() == ASTREE::op) {
            SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        } else if (arg1_node->getASTNodeType() == ASTREE::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        } else if (arg1_node->getASTNodeType() == ASTREE::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = tempVars.back();
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);

        break;
    }
    case ASTREE::relop: {
        Quaternion *temp_true, *temp_false;
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        // std::cout<<"relop:"<<node->getContent()<<std::endl;
        if (node->getContent() == ">") {
            relopOperator(temp_true, temp_false, IM::JUMP_GREAT, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == ">=") {
            relopOperator(temp_true, temp_false, IM::JUMP_EQ_GREAT, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "<") {
            relopOperator(temp_true, temp_false, IM::JUMP_SMALL, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "<=") {
            relopOperator(temp_true, temp_false, IM::JUMP_EQ_SMALL, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "!=") {
            relopOperator(temp_true, temp_false, IM::JUMP_NOT_EQUAL, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "==") {
            relopOperator(temp_true, temp_false, IM::JUMP_EQUAL, arg1_node, arg2_node, symbol_table);
        } else {
            std::cout << "Wrong Content in RELOP\n";
            exit(1);
        }
        break;
    }
    case ASTREE::add: // 可能需要重构一下，方便看
    {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        tempVars.push_back(result);
        result = tempVars.back();
        temp = this->caculateOperator(IM::PLUS, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::minus: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        tempVars.push_back(result);
        result = tempVars.back();
        temp = this->caculateOperator(IM::MINUS, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::multi: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        tempVars.push_back(result);
        result = tempVars.back();
        temp = this->caculateOperator(IM::TIMES, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::div: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        tempVars.push_back(result);
        result = tempVars.back();
        temp = this->caculateOperator(IM::DIV, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::mod: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        tempVars.push_back(result);
        result = tempVars.back();
        temp = this->caculateOperator(IM::MOD, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::pow: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getPeerNode();
        tempVars.push_back(result);
        result = tempVars.back();
        temp = this->caculateOperator(IM::POWER, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::negative: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        tempVars.push_back(result);
        result = tempVars.back();
        if (arg1_node->getASTNodeType() == ASTREE::call_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::op) {
            SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::get_address: {
        std::cout<<"get_address\n"<<std::endl;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::pointer);
        arg1_node = node->getChildNode();
        tempVars.push_back(result);
        if (arg1_node->getASTNodeType() == ASTREE::call_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::GET_ADDRESS, arg1, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << " lvalue required as unary ‘&’ operand" << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::and_op: // 保证栈顶是：node2List, node1List,所以得先遍历子节点，再到&&节点
    {
        std::list<int> left_true, right_true, left_false, right_false;
        right_true = trueList.top();
        trueList.pop();
        left_true = trueList.top();
        trueList.pop();
        right_false = falseList.top();
        falseList.pop();
        left_false = falseList.top();
        falseList.pop();
        left_false.merge(right_false);
        falseList.push(left_false);
        trueList.push(right_true);
        backPatch(&left_true, signal.top());
        signal.pop();
        break;
    }
    case ASTREE::or_op: {
        std::list<int> left_true, right_true, left_false, right_false;
        right_true = trueList.top();
        trueList.pop();
        left_true = trueList.top();
        trueList.pop();
        right_false = falseList.top();
        falseList.pop();
        left_false = falseList.top();
        falseList.pop();
        left_true.merge(right_true);
        trueList.push(left_true);
        falseList.push(right_false);
        backPatch(&left_false, signal.top());
        signal.pop();
        break;
    }
    case ASTREE::not_op: {
        std::list<int> trueL, falseL;
        trueL = trueList.top();
        trueList.pop();
        falseL = falseList.top();
        falseList.pop();
        trueList.push(falseL);
        falseList.push(trueL);
        break;
    }
    case ASTREE::get_value: {
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        tempVars.push_back(result);
        if (arg1_node->getASTNodeType() == ASTREE::call_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = tempVars.back();
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::op) {
            SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else {
            std::cout << "\033[31mError sbjx: \033[0m"
                      << " lvalue required as unary ‘&’ operand" << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case ASTREE::get_arr_var:
    {
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        ASTREE::RootNode *arg1_node = node->getChildNode();
        ASTREE::RootNode *arg2_node = arg1_node->getPeerNode();
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());

        if (node->getParentNode()->getASTNodeType() == ASTREE::op 
        && ((ASTREE::OperatorNode *)node->getParentNode())->getOpType() == ASTREE::assign_arr)
        {
            if (arg2_node->getASTNodeType() == ASTREE::call_var) {
                childValue.push(symbol_table->findSymbol(arg2_node->getContent()));
            }
            else if (arg2_node->getASTNodeType() == ASTREE::call_func) {
                generate(arg2_node, symbol_table);
                SMB::Symbol *arg2 = tempVars.back();
                childValue.push(arg2);
            }
            else if (arg2_node->getASTNodeType() == ASTREE::literal) {
                SMB::Symbol *arg2 = new SMB::Symbol(arg2_node->getContent(), SMB::literal);
                childValue.push(arg2);
            }
            else if (arg2_node->getASTNodeType() == ASTREE::op) {
                SMB::Symbol *arg2 = generateOperator((ASTREE::OperatorNode *)arg2_node, symbol_table);
                childValue.push(arg2);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        }
        else {
            if (arg2_node->getASTNodeType() == ASTREE::call_var) {
                SMB::Symbol *arg2 = symbol_table->findSymbol(arg2_node->getContent());
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2_node->getASTNodeType() == ASTREE::call_func) {
                generate(arg2_node, symbol_table);
                SMB::Symbol *arg2 = tempVars.back();
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2_node->getASTNodeType() == ASTREE::literal) {
                int arg2 = std::stoi(arg2_node->getContent());
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2_node->getASTNodeType() == ASTREE::op) {
                SMB::Symbol *arg2 = generateOperator((ASTREE::OperatorNode *)arg2_node, symbol_table);
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            tempVars.push_back(result);
            this->quads.push_back(*temp);
            return result;
        }
    }
    case ASTREE::get_member:
    {
        std::cout << "get_member\n";
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
        ASTREE::RootNode *arg1_node = node->getChildNode();
        ASTREE::RootNode *arg2_node = arg1_node->getPeerNode();
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
        std::cout << "parent: " << node->getParentNode() << std::endl;
        if (node->getParentNode()->getASTNodeType() == ASTREE::op 
        && ((ASTREE::OperatorNode *)node->getParentNode())->getOpType() == ASTREE::assign_member)
        {
            if (arg2_node->getASTNodeType() == ASTREE::call_var) {
                // TODO: struct table
                std::string type_name = ((SMB::StructDefSymbol *)arg1)->getTypeName();
                // std::cout<<"struct_list:"<<this->rootSymbolTable->getStructTable()<<std::endl;
                int offset = this->rootSymbolTable->getStructTable()->findStruct(type_name)->getMemberOffset(arg2_node->getContent());
                SMB::Symbol *arg2 = new SMB::Symbol(std::to_string(offset), SMB::literal);
                childValue.push(arg2);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        } else {
            if (arg2_node->getASTNodeType() == ASTREE::call_var) {
                std::string type_name = ((SMB::StructDefSymbol *)arg1)->getTypeName();
                // std::cout<<"struct_list:"<<this->rootSymbolTable->getStructTable()<<std::endl;
                int offset = this->rootSymbolTable->getStructTable()->findStruct(type_name)->getMemberOffset(arg2_node->getContent());
                SMB::Symbol *arg2 = new SMB::Symbol(std::to_string(offset), SMB::literal);
                temp = new Quaternion(IM::GET_STRUCT, arg1, arg2, result);
            } else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            tempVars.push_back(result);
            this->quads.push_back(*temp);
            return result;
        }
    }
    default:
        break;
    }
    return NULL;
}
