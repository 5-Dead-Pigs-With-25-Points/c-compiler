#include "./InterMediate.h"
#include <typeinfo>
#include <cstdio>

IM::InterMediate::InterMediate(AST::RootNode* root_node, SMB::StructTable* struct_table)
{
  tempVars.reserve(100); //预留100个空间
  this->root = root_node;
  this->rootSymbolTable = new SMB::SymbolTable(false, struct_table);
  SMB::SymbolTable::setGlobalTable(this->rootSymbolTable);
  this->buildInFunctionRegister();
}

//?
void IM::InterMediate::buildInFunctionRegister()
{
  AST::DefineVarNode* tmp_arg;
  AST::DefineFuncNode* tmp_func;
  SMB::FuncSymbol* func_symbol;

  tmp_arg = new AST::DefineVarNode("i"); //?
  tmp_arg->setAllSymbolType("int");
  tmp_func = new AST::DefineFuncNode("print_int", tmp_arg);
  tmp_func->setReturnSymbolType("void");
  func_symbol = new SMB::FuncSymbol(tmp_func);
  this->rootSymbolTable->addFuncSymbol(func_symbol);
}

/*
this->quads: 表示三地址代码的四元组的队列
*/
// 一般中间代码生成
void IM::InterMediate::generate(AST::RootNode* node, SMB::SymbolTable* symbol_table)
{
  if (node == NULL)
  {
    std::cout << "node is NULL" << std::endl;
    return;
  }
  AST::RootNode* p = node->getChildNode();
  switch (node->getASTNodeType())
  {
  case AST::def_func:
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
  case AST::call_func:
  { // 函数调用的中间代码
    int count = 0;  // 参数个数
    AST::RootNode* var = ((AST::CallFuncNode*)node)->getArgList(); // 参数列表
    std::string add_on = "";
    while (var != NULL)
    {
      count = count + 1;
      Quaternion* temp;
      if (var->getASTNodeType() == AST::assign_var)
      {
        SMB::Symbol* arg1 = symbol_table->findSymbol(var->getContent()); // 参数是变量，从符号表中找
        temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);     // 声明参数的中间代码 param x
        switch (arg1->getType())
        {
        case SMB::interger:
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
      else if (var->getASTNodeType() == AST::literal)
      { // 传入的参数是数字字面量
        int arg1 = std::stoi(var->getContent());
        temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
        add_on = add_on + "_i";
      }
      else if (var->getASTNodeType() == AST::op)
      {                                                                               // 传入的参数是计算节点
        SMB::Symbol* arg1 = generateOperator((AST::OperatorNode*)var, symbol_table); // 生成计算表达式的中间代码，返回表示结果的地址？
        temp = new Quaternion(IM::PARAM, arg1, (SMB::symbol*)NULL);
        switch (arg1->getType())
        {
        case SMB::integer:
          add_on = add_on + "_i";
          break;
        case SMB::pointer:
          add_on = add + "_p";
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

    if (node->getParentNode()->getASTNodeType() == AST::stmt) {
      AST::StatementNode* stmt = (AST::StatementNode*)node->getParentNode();
      if (stmt->getStmtType() == AST::expression) {  // 不需要返回值
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
  case AST::literal: {
    if (node->getParentNode()->getATSNodeType() == AST::op) {   // bool的第一个分量
      AST::OperatorNode* par = (AST::OperatorNode*)node->getParentNode();
      if (par->getOpType() == AST::and_op
        || par->getOpType() == AST::or_op
        || par->getOpType() == AST::not_op) {
        Quaternion* true_quad = new Quaternion(IM::JUMP_GREAT, std::stoi(node->getContent()), 0, (int)NULL);  // 条件为true应该执行的代码
        Quaternion* false_quad = new Quaternion(IM::JUMP, (int)NULL);  // 条件为false应该执行的代码
        std::list<int> true_list;
        true_list.push_back(quads.size());  // 需要回填的指令序号
        this->quads.push_back(*true_quad);
        std::list<int> false_l;
        false_list.push_back(quads.size());
        this->quads.push_back(*false_quad);
        trueList.push(true_list);
        falseList.push(false_list);
      }
    }
    break;
  }
  case AST::op: {
    if (((AST::OperatorNode*)node)->getOpType() == AST::and_op
      || ((AST::OperatorNode*)node)->getOpType() == AST::or_op)
    {
      generate(p, symbol_table);
      signal.push(quads.size());  // signal 布尔表达式中的标号
      generate(p->getPeerNode(), symbol_table);
    }
    else if (((AST::OperatorNode*)node)->getOpType() == AST::not_op
      || ((AST::OperatorNode*)node)->getOpType() == AST::relop) {
      while (p != NULL) {
        generate(p, symbol_table);
        p = p->getPeerNode();
      }
    }
    this->generateOperator((AST::OperatorNode*)node, symbol_table);
    break;
  }
  case AST::stmt: {  // 语句的中间代码
    AST::StatementNode* ret = (AST::StatementNode*)node;
    if (ret->getStmtType() == AST::return_stmt) {
      generateReturn((AST::StatementNode*)node, symbol_table);
    }
    else {
      while (p != NULL) {
        generate(p, this->generateStatement((AST::StatementNode*)node, symbol_table));
        p = p->getPeerNode();
      }
    }
    break;
  }
  case AST::def_var: {  // 声明变量的中间代码 
    AST::DefineVarNode* temp_node = (AST::DefineVarNode*)node;
    if (temp_node->getSymbolType() == SMB::strcut_type) {
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
      if (p->getASTNodeType() == AST::literal) {
        int arg1 = std::stoi(p->getContent());
        temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
      }
      else if (p->getASTNodeType() == AST::assign_var) {
        SMB::Symbol* arg1 = symbol_table->findSymbol(p->getContent());
        temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
      }
      else if (p->getASTNodeType() == AST::op) {
        SMB::Symbol* arg1 = this->generateOperator((AST::OperatorNode*)p, symbol_table);
        temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
      }
      else if (p->getASTNodeType() == AST::call_func) {
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
  case AST::assign_var: {  // 布尔表达式中的赋值？
    if (node->getParentNode()->getASTNodeType() == AST::op) {
      AST::OperatorNode* par = (AST::OperatorNode*)node->getParentNode();
      if (par->getOpType() == AST::and_op
        || par->getOpType() == AST::or_op
        || par->getOpType() == AST::not_op)
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
  case AST::loop: {  // 循环
    AST::LoopNode* loop = (AST::LoopNode*)node;
    if (loop->getLoopType() == AST::for_loop) {
      SMB::SymbolTable* child_table = symbol_table->createChildTable(false);
      child_table->setTableName("for");
      generate(((AST::LoopNode*)node)->getDecNode(), child_table);
      int start = quads.size();
      generate(((AST::LoopNode*)node)->getCondNode(), child_table);  // 这里面会压栈trueList falseList
      std::list<int> Judge_true = trueList.top();
      std::list<int> Judge_false = falseList.top();
      trueList.pop();
      falseList.pop();  // for循环condition部分的条件转移
      backPatch(&Judge_true, Judge_true.back() + 2);
      while (p != NULL)  // for的{}内部分
      {
        generate(p, child_table);
        p = p->getPeerNode();
      }
      generate(((AST::LoopNode*)node)->getActionNode(), child_table);  // for(;;)第三部分

      Quaternion* temp = new Quaternion(IM::JUMP, start);  // 回到循环最初
      this->quads.push_back(*temp);
      int end = quads.size();
      backPatch(&Judge_false, end);  // 回填，跳出for循环的后一条指令序号
    }
    else if (loop->getLoopType() == AST::while_loop)
    {
      int start = quads.size();
      generate(((AST::LoopNode*)node)->getCondNode(), symbol_table);
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
  case AST::select: {  // if else
    AST::SelectNode* select = (AST::SelectNode*)node;
    generate(select->getCondNode(), symbol_table);
    int start = quads.size();
    std::list<int> Judge_true = trueList.top();
    std::list<int> Judge_false = falseList.top();
    trueList.pop();
    falseList.pop();

    backPatch(&Judge_true, start);
    // Body:
    // std::cout << "body: " << select->getBodyNode() << "\n";
    generate(select->getBodyNode(), symbol_table);
    if (select->getElse() != NULL) {
      Quaternion* temp = new Quaternion(IM::JUMP, (int)NULL);  // 
      this->quads.push_back(*temp);
      temp = &quads.back();
      int else_start = quads.size();
      generate(select->getElse(), symbol_table);
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
  case AST::root: {
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
SMB::SymbolTable* IM::InterMediate::generateStatement(AST::Statement* node, SMB::SymbolTable* symbol_table) {
  switch (node->getStmtType()) {
  case AST::comparation: {  //?
    if (node->getParentNode()->getASTNodeType() == AST::loop)
      return symbol_table;
    if (node->getParentNode()->getASTNodeType() == AST::def_func)
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

SMB::SymbolTable* IM::InterMediate::generateReturn(AST::StatementNode* node, SMB::SymbolTable* symbol_table)
{
  AST::BaseNode* p = node->getChildNode();
  Quaternion* temp;
  SMB::Symbol* result = new SMB::Symbol("Temp" + std::to_string(tempVars.size()), SMB::integer);
  tempVars.push_back(result);
  if (p == NULL) {
    temp = new Quaternion(IM::RETURN, (SMB::Symbol*)NULL, (SMB::Symbol*)NULL, (SMB::Symbol*)NULL);
  }
  else if (p->getASTNodeType() == AST::literal) {
    int arg1 = std::stoi(p->getContent());
    temp = new Quaternion(IM::RETURN, arg1, result);
  }
  else if (p->getASTNodeType() == AST::assign_var) {
    SMB::Symbol* arg1 = symbol_table->findSymbol(p->getContent());
    temp = new Quaternion(IM::RETURN, arg1, result);
  }
  else if (p->getASTNodeType() == AST::op) {
    SMB::Symbol* arg1 = this->generateOperator((AST::OperatorNode*)p, symbol_table);
    temp = new Quaternion(IM::RETURN, arg1, result);
  }
  else if (p->getASTNodeType() == AST::call_func) {
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

// 计算节点的中间代码生成
IM::Quaternion* IM::InterMediate::caculateOperator(OperatorCode op,
  AST::RootNode* arg1_node,
  AST::RootNode* arg2_node,
  SMB::Symbol* result,
  SMB::SymbolTable* symbol_table)
{
  Quaternion* temp;
  SMB::Symbol* result = new SMB::Symbol(std::to_string(tempVars.size()), SMB::integer);
  tempVars.push_back(result);
  result = tempVars.back();

  if (arg1_node->getASTNodeType() == AST::assign_var
    && arg2_node->getASTNodeType() == AST::assign_var)
  {
    SMB::Symbol* arg1 = symbol_table->findSymbol(arg1_node->getContent());
    SMB::Symbol* arg2 = symbol_table->findSymbol(arg2_node->getContent());
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == AST::assign_var
    && arg2_node->getASTNodeType() == AST::op)
  {
    SMB::Symbol* arg1 = symbol_table->findSymbol(arg1_node->getContent());
    SMB::Symbol* arg2 = generateOperator((AST::OperatorNode*)arg2_node, symbol_table);
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == AST::assign_var
    && arg2_node->getASTNodeType() == AST::literal)
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
  else if (arg1_node->getASTNodeType() == AST::op
    && arg2_node->getASTNodeType() == AST::assign_var)
  {
    SMB::Symbol* arg1 = generateOperator((AST::OperatorNode*)arg1_node, symbol_table);
    SMB::Symbol* arg2 = symbol_table->findSymbol(arg2_node->getContent());
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == AST::op
    && arg2_node->getASTNodeType() == AST::op)
  {
    SMB::Symbol* arg1 = generateOperator((AST::OperatorNode*)arg1_node, symbol_table);
    SMB::Symbol* arg2 = generateOperator((AST::OperatorNode*)arg2_node, symbol_table);
    typeCheck(op, arg1, arg2);
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == AST::op
    && arg2_node->getASTNodeType() == AST::literal)
  {
    SMB::Symbol* arg1 = generateOperator((AST::OperatorNode*)arg1_node, symbol_table);
    if (arg1->getType() != SMB::integer) {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    int arg2 = std::stoi(arg2_node->getContent());
    temp = new Quaternion(op, arg1, arg2, result);
  }

  else if (arg1_node->getASTNodeType() == AST::literal
    && arg2_node->getASTNodeType() == AST::assign_var)
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
  else if (arg1_node->getASTNodeType() == AST::literal
    && arg2_node->getASTNodeType() == AST::op)
  {
    int arg1 = std::stoi(arg1_node->getContent());
    SMB::Symbol* arg2 = generateOperator((AST::OperatorNode*)arg2_node, symbol_table);
    if (arg2->getType() != SMB::integer) {
      std::cout << "\033[31mError: \033[0m"
        << "Type error!" << std::endl;
      exit(1);
    }
    temp = new Quaternion(op, arg1, arg2, result);
  }
  else if (arg1_node->getASTNodeType() == AST::literal
    && arg2_node->getASTNodeType() == AST::literal)
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
  AST::RootNode* arg1_node,
  AST::RootNode* arg2_node,
  SMB::SymbolTable* symbol_table)
{
  if (arg1_node->getASTNodeType() == AST::assign_var
    && arg2_node->getASTNodeType() == AST::assign_var)
  {
    true_quad = new Quaternion(op, symbol_table->findSymbol(arg1_node->getContent()),
      symbol_table->findSymbol(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  else if (arg1_node->getASTNodeType() == AST::assign_var
    && arg2_node->getASTNodeType() == AST::literal)
  {
    true_quad = new Quaternion(op,
      symbol_table->findSymbol(arg1_node->getContent()),
      std::stoi(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  else if (arg1_node->getASTNodeType() == AST::literal
    && arg2_node->getASTNodeType() == AST::assign_var)
  {
    true_quad = new Quaternion(op,
      std::stoi(arg1_node->getContent()),
      symbol_table->findSymbol(arg2_node->getContent()),
      (int)NULL);
    false_quad = new Quaternion(IM::JUMP, (int)NULL);
  }
  else if (arg1_node->getASTNodeType() == AST::literal
    && arg2_node->getASTNodeType() == AST::literal)
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
  std::cout << "\t   Operator   \targ1\targ2\tresult" << std::endl;
  int count = 0;  // 表示指令的序号
  for (; it != this->quads.end(); it++)
  {
    std::cout << count++ << "\t";
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

