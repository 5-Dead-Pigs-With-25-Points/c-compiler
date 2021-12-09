%{
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "./grammar/Nodes.h"  
#include "./grammar/InterMediate/InterMediate.h"
#include "./grammar/InterMediate/AsmGenerator.h"
using namespace std;

using ASTREE::RootNode;
using SMB::StructTable;
class RootNode;
extern char* yytext;
extern int yylex();
extern FILE* yyin;
void yyerror(const char *s);
RootNode* root = NULL;
StructTable* struct_table = NULL;
extern int yylineno;
%}


%union {
    ASTREE::RootNode* astree;
    char* str;
}
%locations
//%define parser.error verbose

%right <astree> '='
%right <astree> '&'    // 取地址运算符应该是右结合
%right <astree> PLUS_ASSIGN MINUS_ASSIGN MULTI_ASSIGN DIV_ASSIGN
%left <astree> OR 
%left <astree> AND
%left <str> RELOP 
%left <astree> '+' '-'
%left <astree> '*' '/' '%'
%left DPLUS
%right <astree> '^'     // 幂运算是右结合
%right <astree> '!'
%left '(' ')' '[' ']'
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%token <astree> DPLUD DMINUS
%token ERRORID
%token <str> ID INT STR
%token <str> TYPE
%token ',' ';' 
%token STRUCT
%token IF ELSE WHILE FOR CONTINUE RETURN ERRORCHAR GETMEMBER
%token '{' '}'

/* 非终结符 */
%type <astree> program translation_unit external_declaration
%type <str> declaration_specifier
%type <astree> struct_parameter struct_parameters struct_definition
%type <astree> variable_declarator function_declarator parameter_list parameter_declaration
%type <astree> compound_statement block_list for_definition
%type <astree> expression argument_expression_list statement definition declaration_list declaration 
%type <astree> declarators_init declarator_init

%%
program: translation_unit {
		root = new RootNode("begin", ASTREE::root);
		root -> addChildNode($1);
	}
	;

/* 编译单元： 多个外部声明的集合 */
translation_unit: external_declaration {
		$$ = $1;
	}
    | translation_unit external_declaration {
        if ($1 == NULL) {
			$$ = $2;
        } else {
			if ($2 != NULL) {
				$1 -> getLastPeerNode() -> addPeerNode($2);
			}
			$$ = $1;
		}
	}
    ;
  
// 外部声明
/*
int a, b=5, c[1], m[2]=4;
int; //含义？
函数 int a(..) {...} 
int a(..);
c语言中函数定义时不能省略参数名 此处好像不能检测出该错误 可以做一个测试
struct a {};
*/
external_declaration: declaration_specifier declarators_init ';' {
		ASTREE::RootNode* statement = new ASTREE::StatementNode(ASTREE::definition);
		ASTREE::DefineVarNode* variable = (ASTREE::DefineVarNode*)$2;
		cout << $1 << endl;
		variable -> setAllSymbolType($1);
		statement -> addChildNode(variable);
		$$ = statement; 
	}
	| declaration_specifier ';' {}
	| declaration_specifier function_declarator compound_statement {
		ASTREE::DefineFunctionNode* func = (ASTREE::DefineFunctionNode*) $2;
		func -> addChildNode($3);
		func -> setReturnSymbolType($1);
		$$ = func;
	}
	| declaration_specifier function_declarator ';' {
		ASTREE::DefineFunctionNode* func = (ASTREE::DefineFunctionNode*) $2;
		func -> setReturnSymbolType($1);
		$$ = func;
	}
	| struct_definition ';' {
		$$ = $1;
	}
	| error ';' { yyerrok; $$ = NULL; }
	;

// 声明符列表 a=5, b=10, a, a[10]
declarators_init: declarator_init {
		$$ = $1;
	}
	| declarators_init ',' declarator_init {
		$1 -> getLastPeerNode() -> addPeerNode($3);
		$$ = $1;
	}
	;

// 声明符初始化
/*
a a[10]
a = 5 a[10] = 5
*/
declarator_init: variable_declarator {$$ = $1;}
    | variable_declarator '=' INT {
        ASTREE::RootNode* ope = new ASTREE::OperatorNode("=", ASTREE::assign);
        ASTREE::RootNode* t = new ASTREE::LiteralNode($3);
        ope -> addChildNode($1);
        $1 -> addPeerNode(t);
        $$ = ope;
    }
    ;


// 声明说明符
/*
declaration_specifier: INT {
      $$ = strdup("int");
    }
    | VOID {
        $$ = strdup("void")
    }
    | INT '*' {
        $$ = strdup("int poiter");
    }
    | VOID '*' {
        $$ = strdup("void pointer");
    }
    ;
*/
/* 按照词法分析器中的匹配，统一使用TYPE，注意declaration_specifier是char*类型 */

declaration_specifier: TYPE {
		$$ = $1;
	}
	| TYPE '*' {
		$$ = strcat($1, " pointer");
	}

// 结构体定义 struct a {}
struct_definition: STRUCT ID '{' struct_parameters '}' {
		if(struct_table == NULL) {
			struct_table = new SMB::StructTable();
		}
		SMB::StructSymbol* current_struct = new SMB::StructSymbol($2, $4);
		struct_table -> addStruct(current_struct);
		$$ = NULL;
    }
    ;

// 结构体变量列表
/*
int a;
int b;
*/
struct_parameters: struct_parameter {
        $$ = $1;
    }
    | struct_parameters struct_parameter {
        $1 -> getLastPeerNode() -> addPeerNode($2);
        $$ = $1;
    }
    ;
  
// 结构体中的变量形式 int a; 
// 好像没有定义到 int a, b, a[2]的情况 可以测试编译器的输出 
// 如果有问题可以尝试用 declaration_specifier declarators_init ';' 来代替
/* struct_parameter: declaration_specifier ID ';' {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode($2);
		var -> setAllSymbolType($1);
		$$ = var;
    }
    ;
*/
// 可能会涉及到structTable 后续更改
struct_parameter: declaration_specifier declarators_init ';' {
	ASTREE::RootNode* statement = new ASTREE::StatementNode(ASTREE::definition);
	ASTREE::DefineVarNode* variable = (ASTREE::DefineVarNode*)$2;
	variable -> setAllSymbolType($1);
	statement -> addChildNode(variable);
	$$ = statement;
}

// 变量声明符 a a[5]
variable_declarator: ID {
		$$ = new ASTREE::DefineVarNode($1);
    }
    | ID '[' INT ']' {
        ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode($1);
        var -> setAllSymbolType("array");
        var -> setArrayLength($3);
        $$ = var; 
    }
    ;

// 函数：有参 无参
function_declarator: ID '(' parameter_list ')' {
		$$ = new ASTREE::DefineFunctionNode($1, $3);
    }
    | ID '(' ')' {
		$$ = new ASTREE::DefineFunctionNode($1);
    }
    ;

// 参数列表：多参数 1参数
parameter_list: parameter_list ',' parameter_declaration {
		$1 -> getLastPeerNode() -> addPeerNode($3);
        $$  =$1;
    }
    | parameter_declaration {
		$$ = $1;
    }
    ;

// 参数： 有名 int a  无名 int
parameter_declaration: declaration_specifier ID {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode($2);
		var -> setAllSymbolType($1);
		$$ = var;
	}
	| declaration_specifier {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode("");
		var -> setAllSymbolType($1);
	    $$ = var;
	}
	;


/* expression 表达式 */
expression: expression '=' expression{									/* 赋值运算 */
		ASTREE::OperatorNode* assignOpNode = new ASTREE::OperatorNode("=", ASTREE::assign);
		if($1->getASTNodeType() == ASTREE::op) {
			ASTREE::OperatorNode *leftOpNode = (ASTREE::OperatorNode *)$1;
			std::cout<<"I am in!\n";
			if(leftOpNode->getOpType() == ASTREE::get_member) {			/* 对对象属性赋值 */
				assignOpNode->setOpType(ASTREE::assign_member);
				std::cout<<leftOpNode->getOpType()<<std::endl;
			} else if(leftOpNode->getOpType() == ASTREE::get_arr_var) {	/* 对数组元素赋值 */
				assignOpNode->setOpType(ASTREE::assign_arr);
			}
		}
		assignOpNode -> addChildNode($1);
		// std::cout<<"child type: "<< assignOpNode -> getChildNode() -> getOpType()<<std::endl;
		$1 -> addPeerNode($3);
		$$ = assignOpNode;
	}
	| expression AND expression {										/* 与运算 */
		RootNode* andOpNode = new ASTREE::OperatorNode("&&", ASTREE::and_op);
		andOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = andOpNode;
	}
	| expression OR expression {
		RootNode* orOpNode = new ASTREE::OperatorNode("||", ASTREE::or_op);
		orOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = orOpNode;
	}
	
	| expression '+' expression {										/* 加运算 */
		RootNode* addOpNode = new ASTREE::OperatorNode("+", ASTREE::add);
		addOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = addOpNode;
	}
	| expression '-' expression {										/* 减运算 */
		RootNode* minusOpNode = new ASTREE::OperatorNode("-", ASTREE::minus);
		minusOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = minusOpNode;
	}
	| expression '*' expression {										/* 乘运算 */
		RootNode* multiOpNode = new ASTREE::OperatorNode("*", ASTREE::multi);
		multiOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = multiOpNode;
	}
	| expression '/' expression {										/* 除运算 */
		RootNode* divOpNode = new ASTREE::OperatorNode("/", ASTREE::div);
		divOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = divOpNode;
	}
	| expression '%' expression {										/* 取模运算 */
		RootNode* modOpNode = new ASTREE::OperatorNode("%", ASTREE::mod);
		modOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = modOpNode;
	}
	| expression '^' expression {										/* 幂运算 */
		RootNode* powOpNode = new ASTREE::OperatorNode("^", ASTREE::pow);
		powOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = powOpNode;
	}
	| expression RELOP expression {
		RootNode* temp = new ASTREE::OperatorNode($2, ASTREE::relop);
		temp->addChildNode($1);
		$1->addPeerNode($3);
		$$ = temp;
        }
	| '!' expression {													/* 非运算（单目） */
		RootNode* notOpNode = new ASTREE::OperatorNode("!", ASTREE::not_op);
		notOpNode -> addChildNode($2);
		$$ = notOpNode;
	}
	| '(' expression ')' {												/**/
		$$ = $2;
	}
	| '-' expression {													/* 负值 */
		RootNode* negNode = new ASTREE::OperatorNode("-", ASTREE::negative);
		negNode -> addChildNode($2);
		$$ = negNode;
	}
	| ID '(' argument_expression_list ')' {								/* 调用函数 */
		ASTREE::CallFuncNode* callNode = new ASTREE::CallFuncNode($1);
		callNode -> setArgList($3);
		$$ = callNode;
	}
	| ID '(' ')' {														/* 调用无参数函数 */
		$$ = new ASTREE::CallFuncNode($1);
	}
	| STR {
		$$ = new ASTREE::CallVarNode($1);
	}
	| ID {
		$$ = new ASTREE::CallVarNode($1);
	}
	| ID '[' expression ']' {											/* 取数组元素，[]内可为expression */
		RootNode* getVarNode = new ASTREE::OperatorNode("[]", ASTREE::get_arr_var);
		RootNode* temp = new ASTREE::CallVarNode($1);
		getVarNode -> addChildNode(temp);
		temp -> addPeerNode($3);
		$$ = getVarNode;
	}
	| ID GETMEMBER ID {													/* 获取对象成员属性 */
		RootNode* getMemberNode = new ASTREE::OperatorNode(".", ASTREE::get_member);
		ASTREE::CallVarNode* var1 = new ASTREE::CallVarNode($1);
		ASTREE::CallVarNode* var2 = new ASTREE::CallVarNode($3);
		getMemberNode -> addChildNode(var1);
		var1 -> addPeerNode(var2);
		$$ = getMemberNode;
	}
	| INT {																/* 字面量节点 */
		$$ = new ASTREE::LiteralNode($1);
	}
	| '*' ID {															/* 指针取值 */
		RootNode* starNode = new ASTREE::OperatorNode("*", ASTREE::get_value);
		ASTREE::CallVarNode* var = new ASTREE::CallVarNode($2);
		starNode -> addChildNode(var);
		$$ = var;
	}
	| '&' ID {															/* 取地址 */
		RootNode* getAddressNode = new ASTREE::OperatorNode("&", ASTREE::get_address);
		RootNode* temp = new ASTREE::CallVarNode($2);
		getAddressNode -> addChildNode(temp);
		$$ = temp;
	}
	| ID DPLUS {
		RootNode* dplusOpNode = new ASTREE::OperatorNode("++", ASTREE::after_dplus);
		RootNode* temp = new ASTREE::CallVarNode($1);
		dplusOpNode -> addChildNode(temp);
		$$ = dplusOpNode;
	}
	| DPLUS ID {
		RootNode* dplusOpNode = new ASTREE::OperatorNode("++", ASTREE::before_dplus);
		RootNode* temp = new ASTREE::CallVarNode($2);
		dplusOpNode -> addChildNode(temp);
		$$ = dplusOpNode;
	}
	| ID DMINUS {
	        RootNode* dminusOpNode = new ASTREE::OperatorNode("--", ASTREE::after_dminus);
		RootNode* temp = new ASTREE::CallVarNode($1);
		dminusOpNode -> addChildNode(temp);
		$$ = dminusOpNode;
	}
	| DMINUS ID{
		RootNode* dminusOpNode = new ASTREE::OperatorNode("--", ASTREE::before_dminus);
		RootNode* temp = new ASTREE::CallVarNode($2);
		dminusOpNode -> addChildNode(temp);
		$$ = dminusOpNode;
	}
	| expression PLUS_ASSIGN expression {
		RootNode* plusAssignOpNode = new ASTREE::OperatorNode("+=", ASTREE::plus_assign);
		if($1->getASTNodeType() == ASTREE::op) {
			ASTREE::OperatorNode *leftOpNode = (ASTREE::OperatorNode *)$1;
			if(leftOpNode->getOpType() == ASTREE::get_member) {			/* 对对象属性赋值 */
				leftOpNode->setOpType(ASTREE::plus_assign_member);
			} else if(leftOpNode->getOpType() == ASTREE::get_arr_var) {	/* 对数组元素赋值 */
				leftOpNode->setOpType(ASTREE::plus_assign_arr);
			}
		}
		plusAssignOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = plusAssignOpNode;
	}
	| expression MINUS_ASSIGN expression {
		RootNode* minusAssignOpNode = new ASTREE::OperatorNode("-=", ASTREE::minus_assign);
		if($1->getASTNodeType() == ASTREE::op) {
			ASTREE::OperatorNode *leftOpNode = (ASTREE::OperatorNode *)$1;
			if(leftOpNode->getOpType() == ASTREE::get_member) {			/* 对对象属性赋值 */
				leftOpNode->setOpType(ASTREE::minus_assign_member);
			} else if(leftOpNode->getOpType() == ASTREE::get_arr_var) {	/* 对数组元素赋值 */
				leftOpNode->setOpType(ASTREE::minus_assign_arr);
			}
		}
		minusAssignOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = minusAssignOpNode;
	}
	| expression MULTI_ASSIGN expression {
		RootNode* multiAssignOpNode = new ASTREE::OperatorNode("*=", ASTREE::multi_assign);
		if($1->getASTNodeType() == ASTREE::op) {
			ASTREE::OperatorNode *leftOpNode = (ASTREE::OperatorNode *)$1;
			if(leftOpNode->getOpType() == ASTREE::get_member) {			/* 对对象属性赋值 */
				leftOpNode->setOpType(ASTREE::multi_assign_member);
			} else if(leftOpNode->getOpType() == ASTREE::get_arr_var) {	/* 对数组元素赋值 */
				leftOpNode->setOpType(ASTREE::multi_assign_arr);
			}
		}
		multiAssignOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = multiAssignOpNode;
	}
	| expression DIV_ASSIGN expression {
		RootNode* divAssignOpNode = new ASTREE::OperatorNode("/=", ASTREE::div_assign);
		if($1->getASTNodeType() == ASTREE::op) {
			ASTREE::OperatorNode *leftOpNode = (ASTREE::OperatorNode *)$1;
			if(leftOpNode->getOpType() == ASTREE::get_member) {			/* 对对象属性赋值 */
				leftOpNode->setOpType(ASTREE::div_assign_member);
			} else if(leftOpNode->getOpType() == ASTREE::get_arr_var) {	/* 对数组元素赋值 */
				leftOpNode->setOpType(ASTREE::div_assign_arr);
			}
		}
		divAssignOpNode -> addChildNode($1);
		$1 -> addPeerNode($3);
		$$ = divAssignOpNode;
	}
	| error ')' {yyerrok;}
	;
		
/* 函数传入的参数列表 */
argument_expression_list: expression {										
		$$ = $1;
	}
	| argument_expression_list ',' expression {
		$1 -> getLastPeerNode() -> addPeerNode($3);
		$$ = $1;
	}
	;	

/* 代码块 */
compound_statement: '{' block_list '}' {
        RootNode* t= new ASTREE::StatementNode(ASTREE::compoundation);
        t->addChildNode($2);
        $$ = t;
    }
    | error '}' { yyerrok; }
    ;
	
block_list: block_list statement {
        $1->getLastPeerNode()->addPeerNode($2);
    }
    | statement {
		$$ = $1;
	}
    ;
	
/* Local Definitions */
definition: declaration_specifier declaration_list  {
        if ($2->getASTNodeType() == ASTREE::op) {								/* 有初始化的声明 */				
            ASTREE::OperatorNode* t = (ASTREE::OperatorNode*)$2;
            t->setAllSymbolType($1);
        } else {
            ASTREE::DefineVarNode* t= (ASTREE::DefineVarNode*)$2;
            t->setAllSymbolType($1);
        }
        $$ = $2;
    }
    | error ';' { yyerrok; }
    ;

declaration_list: declaration { $$ = $1; }
    | declaration ',' declaration_list {
        $1->getLastPeerNode()->addPeerNode($3);
        $$ = $1;
    }
    ;

declaration: variable_declarator{ $$ = $1; }			
    | variable_declarator '=' expression {
        $$ = new ASTREE::OperatorNode("=", ASTREE::assign);
        $$->addChildNode($1);
        $1->addPeerNode($3);
    }
;

for_definition: definition { $$ = $1;}
	| expression {$$ = $1;}
	;

/* statement 语句 */
statement: expression ';' { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::expression);
        t->addChildNode($1);
        $$ = t;
    }
    | definition ';' { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::definition);
        t->addChildNode($1);
        $$ = t;
    }
    | STRUCT ID ID ';' { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::definition);
        RootNode* structDefinitionNode = new ASTREE::DefineVarNode($3, $2);
        t->addChildNode(structDefinitionNode);
        $$ = t; }
    | compound_statement { $$=$1;}
    | RETURN expression ';' {
        RootNode* t= new ASTREE::StatementNode(ASTREE::return_stmt);
        t->addChildNode($2);
        $$ = t;
    }
    | RETURN ';' {
        RootNode* t= new ASTREE::StatementNode(ASTREE::return_stmt);
        $$ = t;
    }
    | IF '(' expression ')' statement {  
        ASTREE::SelectNode* t= new ASTREE::SelectNode(ASTREE::if_stmt);
        t->setBodyNode($5);
        t->setCondNode($3);
        $$ = t;
    }
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE{
        ASTREE::SelectNode* t= new ASTREE::SelectNode(ASTREE::if_stmt);
        t->setBodyNode($5);
        t->setCondNode($3);
        t->setElseNode($7);
        $$ = t;
    }
    | WHILE '(' expression ')' statement {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::while_loop, $3);
        t->addChildNode($5);
        $$ = t;
    }
    | FOR '(' ';' ';' ')' statement{
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, NULL, NULL);
        t->addChildNode($6);
        $$ = t;
    }
    | FOR '(' for_definition ';' ';' ')' statement{
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, $3, NULL);
        t->addChildNode($7);
        $$ = t;
    }
    | FOR '(' ';' expression ';' ')' statement{ 
        RootNode* t = new ASTREE::LoopNode("", ASTREE::for_loop, $4, NULL, NULL);
        t->addChildNode($7);
        $$ = t;
    }
    | FOR '(' ';' ';' expression ')' statement{
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, NULL, $5);
        t->addChildNode($7);
        $$ = t;
    }
    | FOR '(' for_definition ';' expression ';' expression ')' statement {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, $5, $3, $7);
        t->addChildNode($9);
        $$ = t;
    }
    | FOR '(' for_definition ';' expression ';' ')' statement  {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, $5, $3, NULL);
        t->addChildNode($8);
        $$ = t;
    }
    | FOR '(' for_definition ';' ';' expression ')' statement  {
        RootNode* t = new ASTREE::LoopNode("", ASTREE::for_loop, NULL, $3, $6);
        t->addChildNode($8);
        $$ = t;
    }
    | FOR '(' ';' expression ';' expression ')' statement {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, $4, NULL, $6);
        t->addChildNode($8);
        $$ = t;
    }
    | error ';' { yyerrok; } 
    ;
	
%%

void yyerror(const char* s){
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
}

int main(int argc, char* argv[]){
	char *filename = NULL;
	filename = argv[1];
	yyin = fopen(filename, "r");
	do{
		yyparse();
		} while(!feof(yyin));
	fclose(yyin);
	
	// 打印语法树
	if(root) root -> printTree();
	SMB::SymbolTable* root_symbol_table = new SMB::SymbolTable(NULL, false);
	SMB::tree(root_symbol_table, root, 0);
	

	// 打印中间代码
	IM::InterMediate *im = new IM::InterMediate(root, struct_table);
    im->generate(root, im->getTable());
    im->print();
	
	// asm
	ASM::AsmGenerator* asmgenerator = new ASM::AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());
    asmgenerator->generate();
    // if (flag_print_asm) {
    std::cout << asmgenerator->getAsmCode();
    // }
	
	if(root) delete root;
	return 0;
}
