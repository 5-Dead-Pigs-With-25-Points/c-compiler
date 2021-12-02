#include "./InterMediate.h"
#include <typeinfo>
#include <cstdio>

IM::InterMediate::InterMediate(ASTREE::RootNode* root_node, SMB::StructTable* struct_table)
{
  tempVars.reserve(100); //预留100个空间
  this->root = root_node;
  this->rootSymbolTable = new SMB::SymbolTable(false, struct_table);
  SMB::SymbolTable::setGlobalTable(this->rootSymbolTable);
  std::cout << "rootSymbolTable: " << this->rootSymbolTable << std::endl;
  std::cout << "struct_table: " << struct_table << std::endl;
  this->buildInFunctionRegister();
}

//?
void IM::InterMediate::buildInFunctionRegister()
{
  ASTREE::DefineVarNode* tmp_arg;
  ASTREE::DefineFunctionNode* tmp_func;
  SMB::FuncSymbol* func_symbol;

  tmp_arg = new ASTREE::DefineVarNode("i"); //?
  tmp_arg->setAllSymbolType("int");
  tmp_func = new ASTREE::DefineFunctionNode("print_int", tmp_arg);
  tmp_func->setReturnSymbolType("void");
  func_symbol = new SMB::FuncSymbol(tmp_func);
  this->rootSymbolTable->addFuncSymbol(func_symbol);
}

/*
this->quads: 表示三地址代码的四元组的队列
*/
// 一般中间代码生成
void IM::InterMediate::generate(ASTREE::RootNode* node, SMB::SymbolTable* symbol_table)
{
  if (node == NULL)
  {
    std::cout << "node is NULL" << std::endl;
    return;
  }
  std::cout<<"symbol_table_name: "<<symbol_table->getTableName()<<std::endl;
  ASTREE::RootNode* p = node->getChildNode();
  switch (node->getASTNodeType())
  {
  case ASTREE::def_func:
  { // 函数声明的中间代码
    SMB::FuncSymbol* func = new SMB::FuncSymbol(node);
    this->rootSymbolTable->addFuncSymbol(func);
    Quaternion* temp;
    SMB::Symbol* temp_symbol = new SMB::Symbol(func->getDecName(), SMB::void_type);
    temp = new Quaternion(IM::FUNC_DEF, temp_symbol, (SMB::Symbol*)NULL);
    this->quads.push_back(*temp);
    while (p != NULL)
    {
      SMB::SymbolTable* child_table = symbol_table->createChildTable(true); //函数的符号表
      child_table->setTableName(func->getDecName());
      generate(p, child_table); //
      p = p->getPeerNode();
    }
    temp = new Quaternion(IM::END_FUNCTION, (SMB::Symbol*)NULL, (SMB::Symbol*)NULL);
    this->quads.push_back(*temp);
    break;
  }
  case ASTREE::call_func:
  { // 函数调用的中间代码
    int count = 0;  // 参数个数
    ASTREE::RootNode* var = ((ASTREE::CallFuncNode*)node)->getArgList(); // 参数列表
    std::string add_on = "";
    while (var != NULL)
    {
      count = count + 1;
      Quaternion* temp;
      if (var->getASTNodeType() == ASTREE::call_var)
      {
        SMB::Symbol* arg1 = symbol_table->findSymbol(var->getContent()); // 参数是变量，从符号表中找
        temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);     // 声明参数的中间代码 param x
        switch (arg1->getType())
        {
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
      }
      else if (var->getASTNodeType() == ASTREE::literal)
      { // 传入的参数是数字字面量
        int arg1 = std::stoi(var->getContent());
        temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
        add_on = add_on + "_i";
      }
      else if (var->getASTNodeType() == ASTREE::op)
      {                                                                               // 传入的参数是计算节点
        SMB::Symbol* arg1 = generateOperator((ASTREE::OperatorNode*)var, symbol_table); // 生成计算表达式的中间代码，返回表示结果的地址？
        temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
        switch (arg1->getType())
        {
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
    SMB::FuncSymbol* func_sym = (SMB::FuncSymbol*)this->rootSymbolTable->findSymbol(node->getContent() + add_on); //在符号表中查找是否声明过该函数
    if (func_sym == NULL)
    {
      std::cout << "\033[31mError: \033[0m"
        << " function is not declared." << std::endl;
      exit(1);
    }
    SMB::Symbol* func_symbol = new SMB::Symbol(func_sym->getDecName(), SMB::void_type);
    SMB::Symbol* temp_v = NULL;  // 保存函数返回值的临时变量的地址

    if (node->getParentNode()->getASTNodeType() == ASTREE::stmt) {
      ASTREE::StatementNode* stmt = (ASTREE::StatementNode*)node->getParentNode();
      if (stmt->getStmtType() == ASTREE::expression) {  // 不需要返回值
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

    Quaternion* temp = new Quaternion(IM::CALL, func_symbol, count, temp_v);  // 函数调用 (temp_v=) call func n
    this->quads.push_back(*temp);
  }
  case ASTREE::literal: {
    if (node->getParentNode()->getASTNodeType() == ASTREE::op) {   // bool的第一个分量
      ASTREE::OperatorNode* par = (ASTREE::OperatorNode*)node->getParentNode();
      if (par->getOpType() == ASTREE::and_op
        || par->getOpType() == ASTREE::or_op
        || par->getOpType() == ASTREE::not_op) {
        Quaternion* true_quad = new Quaternion(IM::JUMP_GREAT, std::stoi(node->getContent()), 0, (int)NULL);  // 条件为true应该执行的代码
        Quaternion* false_quad = new Quaternion(IM::JUMP, (int)NULL);  // 条件为false应该执行的代码
        std::list<int> true_list;
        true_list.push_back(quads.size());  // 需要回填的指令序号
        this->quads.push_back(*true_quad);
        std::list<int> false_list;
        false_list.push_back(quads.size());
        this->quads.push_back(*false_quad);
        trueList.push(true_list);
        falseList.push(false_list);
      }
    }
    break;
  }
  case ASTREE::op: {
    if (((ASTREE::OperatorNode*)node)->getOpType() == ASTREE::and_op
      || ((ASTREE::OperatorNode*)node)->getOpType() == ASTREE::or_op)
    {
      generate(p, symbol_table);
      signal.push(quads.size());  // signal 布尔表达式中的标号
      generate(p->getPeerNode(), symbol_table);
    }
    else if (((ASTREE::OperatorNode*)node)->getOpType() == ASTREE::not_op
      || ((ASTREE::OperatorNode*)node)->getOpType() == ASTREE::relop) {
      while (p != NULL) {
        generate(p, symbol_table);
        p = p->getPeerNode();
      }
    }
    this->generateOperator((ASTREE::OperatorNode*)node, symbol_table);
    break;
  }
  case ASTREE::stmt: {  // 语句的中间代码
    ASTREE::StatementNode* ret = (ASTREE::StatementNode*)node;
    if (ret->getStmtType() == ASTREE::return_stmt) {
      generateReturn((ASTREE::StatementNode*)node, symbol_table);
    }
    else {
      while (p != NULL) {
        generate(p, this->generateStatement((ASTREE::StatementNode*)node, symbol_table));
        p = p->getPeerNode();
      }
    }
    break;
  }
  case ASTREE::def_var: {  // 声明变量的中间代码 
    ASTREE::DefineVarNode* temp_node = (ASTREE::DefineVarNode*)node;
    if (temp_node->getSymbolType() == SMB::struct_type) {
      if (symbol_table->addStructSymbol(temp_node->getStructName(), temp_node->getContent()) == 0) { // 结构体未定义
        std::cout << "\033[31mError: \033[0m"
          << "struct " << temp_node->getStructName() << " is not defined" << std::endl;
        exit(1);
      }
    }
    else if (temp_node->getSymbolType() == SMB::array) {
      symbol_table->addArraySymbol(temp_node);
    }
    else {
      if (symbol_table->addSymbol(node) == 0) {  // 重定义
        std::cout << "\033[31mError: \033[0m"
          << "value " << node->getContent() << " is redeclaration" << std::endl;
        exit(1);
      }
    }
    // 上面是加入符号表，下面生成中间代码
    SMB::Symbol* var_symbol = symbol_table->findSymbol(node->getContent());
    if (p != NULL) {  // x = ...
      Quaternion* temp;
      if (p->getASTNodeType() == ASTREE::literal) {
        int arg1 = std::stoi(p->getContent());
        temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
      }
      else if (p->getASTNodeType() == ASTREE::call_var) {
        SMB::Symbol* arg1 = symbol_table->findSymbol(p->getContent());
        temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
      }
      else if (p->getASTNodeType() == ASTREE::op) {
        SMB::Symbol* arg1 = this->generateOperator((ASTREE::OperatorNode*)p, symbol_table);
        temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
      }
      else if (p->getASTNodeType() == ASTREE::call_func) {
        generate(p, symbol_table);
        SMB::Symbol* arg1 = tempVars.back();
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
  case ASTREE::call_var: {  // 布尔表达式中的赋值？
    if (node->getParentNode()->getASTNodeType() == ASTREE::op) {
      ASTREE::OperatorNode* par = (ASTREE::OperatorNode*)node->getParentNode();
      if (par->getOpType() == ASTREE::and_op
        || par->getOpType() == ASTREE::or_op
        || par->getOpType() == ASTREE::not_op)
      {
        SMB::Symbol* arg1 = symbol_table->findSymbol(node->getContent());
        Quaternion* true_quad = new Quaternion(IM::JUMP_GREAT, arg1, 0, (int)NULL);
        Quaternion* false_quad = new Quaternion(IM::JUMP, (int)NULL);
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
  case ASTREE::loop: {  // 循环
    // ASTREE::LoopNode* loop = (ASTREE::LoopNode*)node;
    // if (loop->getLoopType() == ASTREE::for_loop) {
    //   SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
    //   child_table->setTableName("for");
    //   generate(((ASTREE::LoopNode*)node)->getDeclareNode(), child_table);
    //   int start = quads.size();
    //   generate(((ASTREE::LoopNode*)node)->getCondNode(), child_table);  // 这里面会压栈trueList falseList
    //   std::list<int> Judge_true = trueList.top();
    //   std::list<int> Judge_false = falseList.top();
    //   trueList.pop();
    //   falseList.pop();  // for循环condition部分的条件转移
    //   backPatch(&Judge_true, Judge_true.back() + 2);
    //   while (p != NULL)  // for的{}内部分
    //   {
    //     generate(p, child_table);
    //     p = p->getPeerNode();
    //   }
    //   generate(((ASTREE::LoopNode*)node)->getActionNode(), child_table);  // for(;;)第三部分

    //   Quaternion* temp = new Quaternion(IM::JUMP, start);  // 回到循环最初
    //   this->quads.push_back(*temp);
    //   int end = quads.size();
    //   backPatch(&Judge_false, end);  // 回填，跳出for循环的后一条指令序号
    // }
    // else if (loop->getLoopType() == ASTREE::while_loop)
    // {
    //   int start = quads.size();
    //   generate(((ASTREE::LoopNode*)node)->getCondNode(), symbol_table);
    //   std::list<int> Judge_true = trueList.top();
    //   std::list<int> Judge_false = falseList.top();
    //   trueList.pop();
    //   falseList.pop();
    //   backPatch(&Judge_true, Judge_true.back() + 2);
    //   while (p != NULL) {
    //     SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
    //     child_table->setTableName("while");
    //     generate(p, child_table);
    //     p = p->getPeerNode();
    //   }

    //   Quaternion* temp = new Quaternion(IM::JUMP, start);
    //   this->quads.push_back(*temp);
    //   int end = quads.size();
    //   backPatch(&Judge_false, end);
    // }
    // break;
    ASTREE::LoopNode* loop = (ASTREE::LoopNode*)node;
    if (loop->getLoopType() == ASTREE::for_loop) {
      SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
      child_table->setTableName("for");
      generate(((ASTREE::LoopNode*)node)->getDeclareNode(), child_table);
      int start = quads.size();
      bool isCondEmpty = ((ASTREE::LoopNode*)node)->getCondNode() == NULL; 
      std::list<int> Judge_true;
      std::list<int> Judge_false;
      generate(((ASTREE::LoopNode*)node)->getCondNode(), child_table);  // 这里面会压栈trueList falseList
      if(!isCondEmpty){
        Judge_true = trueList.top();
        // std::cout<<"true pop ok"<<std::endl;
        Judge_false = falseList.top();
        // std::cout<<"false pop ok"<<std::endl;
        trueList.pop();
        falseList.pop();  // for循环condition部分的条件转移
        backPatch(&Judge_true, Judge_true.back() + 2);
      } else {
      	// for(int i=0;;) condNode == NULL  dead loop
      	std::cout <<"Cond Node is NULL" << std::endl;
      }
      while (p != NULL)  // for的{}内部分
      {
        generate(p, child_table);
        p = p->getPeerNode();
      }
      generate(((ASTREE::LoopNode*)node)->getActionNode(), child_table);  // for(;;)第三部分

      Quaternion* temp = new Quaternion(IM::JUMP, start);  // 回到循环最初
      this->quads.push_back(*temp);
      int end = quads.size();
      if(!isCondEmpty){
      	std::cout <<"Cond not  NULL" << std::endl;
      	backPatch(&Judge_false, end);  // 回填，跳出for循环的后一条指令序号
      	std::cout <<"Cond not  NULL ok" << std::endl;
      }
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
        SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
        child_table->setTableName("while");
        generate(p, child_table);
        p = p->getPeerNode();
      }

      Quaternion* temp = new Quaternion(IM::JUMP, start);
      this->quads.push_back(*temp);
      int end = quads.size();
      backPatch(&Judge_false, end);
    }
    break;
  }
  case ASTREE::select: {  // if else
    ASTREE::SelectNode* select = (ASTREE::SelectNode*)node;
    generate(select->getCondNode(), symbol_table);
    int start = quads.size();
    std::list<int> Judge_true = trueList.top();
    std::list<int> Judge_false = falseList.top();
    trueList.pop();
    falseList.pop();

    backPatch(&Judge_true, start);
    // Body:
    SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
    child_table->setTableName("select-if");
    generate(select->getBodyNode(), child_table);
    if (select->getElse() != NULL) {
      Quaternion* temp = new Quaternion(IM::JUMP, (int)NULL);  // 
      this->quads.push_back(*temp);
      temp = &quads.back();
      int else_start = quads.size();
      SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
      child_table->setTableName("select-else");
      generate(select->getElse(), child_table);
      backPatch(&Judge_false, else_start);  // if false 跳转到else这里
      int end = quads.size();
      temp->backPatch(end);
    }
    else {
      int end = quads.size();
      backPatch(&Judge_false, end);
    }
    break;
  }
  case ASTREE::root: {
    while (p != NULL) {
      generate(p, symbol_table);  // 深度
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


// 语句的中间代码
// Create a child symbol table to generate follow code
SMB::SymbolTable* IM::InterMediate::generateStatement(ASTREE::StatementNode* node, SMB::SymbolTable* symbol_table) {
  switch (node->getStmtType()) {
  case ASTREE::comparison: {  //?
    if (node->getParentNode()->getASTNodeType() == ASTREE::loop)
      return symbol_table;
    if (node->getParentNode()->getASTNodeType() == ASTREE::def_func)
      return symbol_table;
    SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
    child_table->setTableName("comparation");
    return child_table;
  }
  default:
    break;
  }
  return symbol_table;
}

void IM::InterMediate::generateReturn(ASTREE::StatementNode* node, SMB::SymbolTable* symbol_table)
{
  ASTREE::RootNode* p = node->getChildNode();
  Quaternion* temp;
  SMB::Symbol* result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
  tempVars.push_back(result);
  if (p == NULL) {
    temp = new Quaternion(IM::RETURN, (SMB::Symbol*)NULL, (SMB::Symbol*)NULL, (SMB::Symbol*)NULL);
  }
  else if (p->getASTNodeType() == ASTREE::literal) {
    int arg1 = std::stoi(p->getContent());
    temp = new Quaternion(IM::RETURN, arg1, result);
  }
  else if (p->getASTNodeType() == ASTREE::call_var) {
    SMB::Symbol* arg1 = symbol_table->findSymbol(p->getContent());
    temp = new Quaternion(IM::RETURN, arg1, result);
  }
  else if (p->getASTNodeType() == ASTREE::op) {
    SMB::Symbol* arg1 = this->generateOperator((ASTREE::OperatorNode*)p, symbol_table);
    temp = new Quaternion(IM::RETURN, arg1, result);
  }
  else if (p->getASTNodeType() == ASTREE::call_func) {
    generate(p, symbol_table);
    SMB::Symbol* arg1 = tempVars.back();
    temp = new Quaternion(IM::RETURN, arg1, (SMB::Symbol*)NULL);
  }
  else {
    std::cout << "\033[31mError: \033[0m"
      << "Type error" << std::endl;
    exit(1);
  }
  quads.push_back(*temp);
}

SMB::Symbol *IM::InterMediate::generateOperator(ASTREE::OperatorNode *node, SMB::SymbolTable *symbol_table)  //运算符结点
{
    std::cout << "op begin, type: " << node->getOpType() << "\n";   //对照符号表看输出
    Quaternion *temp;
    ASTREE::RootNode *arg1_node, *arg2_node;
    switch (node->getOpType()) {                  //判断运算符类型
    case ASTREE::assign: {                        //赋值操作
        std::cout<<"assign\n";                    
        SMB::Symbol *result;
        IM::OperatorCode op;
        if (node->getChildNode()->getASTNodeType() == ASTREE::op            //若子节点为运算符且子节点为取值？指针？
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
            } else if (node->getChildNode()->getASTNodeType() == ASTREE::def_var) {   //定义新变量
                if(symbol_table->addSymbol(node->getChildNode()) == 0){
                    std::cout << "\033[31mError: \033[0m"
                    << "value " << node->getChildNode()->getContent() << " is redeclaration" << std::endl;
                    exit(1);
                }
            }
            result = symbol_table->findSymbol(node->getChildNode()->getContent());
        }

        ASTREE::RootNode *arg1_node = node->getChildNode()->getPeerNode();  //找到孩子结点的兄弟结点
        std::cout<<"t = "<<arg1_node->getASTNodeType()<<std::endl;          //
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
            typeCheck(op, result, arg1);  //类型检查
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
        else if (arg1_node->getASTNodeType() == ASTREE::call_func) {  //调用函数
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
    case ASTREE::assign_arr: {   //声明数组
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
        else if (arg1_node->getASTNodeType() == ASTREE::op) {     //操作数
            SMB::Symbol *arg1 = generateOperator((ASTREE::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::literal) {   //字面值
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == ASTREE::call_func) {   //调用函数
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
    case ASTREE::assign_member: {                                       //为成员赋值
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
    case ASTREE::relop: {      //操作符
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

// 计算节点的中间代码生成
IM::Quaternion* IM::InterMediate::caculateOperator(OperatorCode op,
  ASTREE::RootNode* arg1_node,
  ASTREE::RootNode* arg2_node,
  SMB::Symbol* result,
  SMB::SymbolTable* symbol_table)
{
  Quaternion* temp;
  // SMB::Symbol* result = new SMB::Symbol(std::to_string(tempVars.size()), SMB::integer);
  // tempVars.push_back(result);
  // result = tempVars.back();

  if (arg1_node->getASTNodeType() == ASTREE::call_var
    && arg2_node->getASTNodeType() == ASTREE::call_var)
  {
    SMB::Symbol* arg1 = symbol_table->findSymbol(arg1_node->getContent());
    SMB::Symbol* arg2 = symbol_table->findSymbol(arg2_node->getContent());
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::call_var
    && arg2_node->getASTNodeType() == ASTREE::op)
  {
    SMB::Symbol* arg1 = symbol_table->findSymbol(arg1_node->getContent());
    SMB::Symbol* arg2 = generateOperator((ASTREE::OperatorNode*)arg2_node, symbol_table);
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::call_var
    && arg2_node->getASTNodeType() == ASTREE::literal)
  {
    SMB::Symbol* arg1 = symbol_table->findSymbol(arg1_node->getContent());
    int arg2 = std::stoi(arg2_node->getContent());
    if (arg1->getType() != SMB::integer) {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::op
    && arg2_node->getASTNodeType() == ASTREE::call_var)
  {
    SMB::Symbol* arg1 = generateOperator((ASTREE::OperatorNode*)arg1_node, symbol_table);
    SMB::Symbol* arg2 = symbol_table->findSymbol(arg2_node->getContent());
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::op
    && arg2_node->getASTNodeType() == ASTREE::op)
  {
    SMB::Symbol* arg1 = generateOperator((ASTREE::OperatorNode*)arg1_node, symbol_table);
    SMB::Symbol* arg2 = generateOperator((ASTREE::OperatorNode*)arg2_node, symbol_table);
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::op
    && arg2_node->getASTNodeType() == ASTREE::literal)
  {
    SMB::Symbol* arg1 = generateOperator((ASTREE::OperatorNode*)arg1_node, symbol_table);
    if (arg1->getType() != SMB::integer) {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    int arg2 = std::stoi(arg2_node->getContent());
    temp = new Quaternion(op, arg1, arg2, result);
  }

  else if (arg1_node->getASTNodeType() == ASTREE::literal
    && arg2_node->getASTNodeType() == ASTREE::call_var)
  {
    int arg1 = std::stoi(arg1_node->getContent());
    SMB::Symbol* arg2 = symbol_table->findSymbol(arg2_node->getContent());
    if (arg2->getType() != SMB::integer) {  // 类型不匹配（字面量只有整数）
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::literal
    && arg2_node->getASTNodeType() == ASTREE::op)
  {
    int arg1 = std::stoi(arg1_node->getContent());
    SMB::Symbol* arg2 = generateOperator((ASTREE::OperatorNode*)arg2_node, symbol_table);
    if (arg2->getType() != SMB::integer) {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::literal
    && arg2_node->getASTNodeType() == ASTREE::literal)
  {
    int arg1 = std::stoi(arg1_node->getContent());
    int arg2 = std::stoi(arg2_node->getContent());
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else {
    std::cout << "\033[31mError: \033[0m"
      << "No match type for" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
    exit(1);
  }
  return temp;
}

// 比较表达式中间代码生成
void IM::InterMediate::relopOperator(Quaternion* true_quad,
  Quaternion* false_quad,
  OperatorCode op,
  ASTREE::RootNode* arg1_node,
  ASTREE::RootNode* arg2_node,
  SMB::SymbolTable* symbol_table)
{
  if (arg1_node->getASTNodeType() == ASTREE::call_var
    && arg2_node->getASTNodeType() == ASTREE::call_var)
  {
    true_quad = new Quaternion(op, symbol_table->findSymbol(arg1_node->getContent()),
      symbol_table->findSymbol(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::call_var
    && arg2_node->getASTNodeType() == ASTREE::literal)
  {
    true_quad = new Quaternion(op,
      symbol_table->findSymbol(arg1_node->getContent()),
      std::stoi(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::literal
    && arg2_node->getASTNodeType() == ASTREE::call_var)
  {
    true_quad = new Quaternion(op,
      std::stoi(arg1_node->getContent()),
      symbol_table->findSymbol(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  else if (arg1_node->getASTNodeType() == ASTREE::literal
    && arg2_node->getASTNodeType() == ASTREE::literal)
  {
    true_quad = new Quaternion(op,
      std::stoi(arg1_node->getContent()),
      std::stoi(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  std::list<int> trueL; // true quad的指令序号，便于后续回填
  trueL.push_back(quads.size());
  this->quads.push_back(*true_quad);
  std::list<int> falseL; // Same as the upper one
  falseL.push_back(quads.size());
  this->quads.push_back(*false_quad);  // false_quad: if false jump...
  trueList.push(trueL);
  falseList.push(falseL);
  return;
}

std::list<int>* IM::InterMediate::makeList(int index) {
  std::list<int>* jump_list = new std::list<int>();
  jump_list->push_back(index);
  return jump_list;
}

// 合并list
std::list<int>* IM::InterMediate::merge(std::list<int>* list1, std::list<int>* list2) {
  list1->merge(*list2);
  return list1;
}

// trueList和falseList回填
void IM::InterMediate::backPatch(std::list<int>* backList, int target) {
  std::list<int>::iterator it;
  for (it = backList->begin(); it != backList->end(); it++) {
    quads[*it].backPatch(target);
  }
  return;
}

// 打印中间代码（四元组形式）
void IM::InterMediate::print() {
  std::vector<Quaternion>::iterator it = this->quads.begin();
  std::cout << "No. (Operator,Arg1,Arg2,Result)" << std::endl;
  int count = 0;  // 表示指令的序号
  for (; it != this->quads.end(); it++)
  {
    std::cout << count++ << ' ';
    if (&(*it) == NULL) std::cout << "NULL \n";
    else it->print();
  }
  return;
}

// 类型检查
void IM::InterMediate::typeCheck(OperatorCode op, SMB::Symbol* arg1, SMB::Symbol* arg2) {
  switch (op) {
  case ASSIGN:
    if (arg1->getType() != arg2->getType())
    {
      std::cout << "arg1_name: " << arg1->getName() << " arg1_type: " << arg1->getType()
        << "arg2_name: " << arg2->getName() << " arg2_type: " << arg2->getType() << std::endl;
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    break;
  case PLUS:
    if (arg1->getType() == SMB::pointer &&
      arg2->getType() == SMB::pointer)
    {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    break;
  case MINUS:
    break;
  case TIMES:
  case DIV:
  case POWER:
  case MOD:
    if (!(arg1->getType() == SMB::integer &&
      arg2->getType() == SMB::integer))  // 整数的乘除取模运算
    {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    break;
  default:
    break;
  }
}

