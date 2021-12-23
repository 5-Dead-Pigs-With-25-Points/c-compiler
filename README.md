# 编译原理实验报告


#### 成员分工

**王家驹（组长，学号1913136）**

1.词法分析

2.语法分析：创建抽象语法树的工具类；

3.汇编

**文雨晨（学号1913143）**

1.词法分析

2.语法分析：生成逻辑运算和for控制流语句等的语法树部分

3.汇编

**李玥（学号1913147）**

1.语法分析：写测试文件，测试最后的生成树

2.中间代码：生成四则运算和赋值表达式的中间代码；

3.汇编

4.类型检查：不同类型间赋值、运算会有warning

**金娃（学号1913173）**

1.语法分析：生成四则运算的语法树；

2.中间代码：生成部分控制流语句、逻辑运算和关系运算的中间代码

3.代码优化：只定义而未使用变量不会被生成中间代码

4.错误处理：变量未定义、变量重定义；

**崔涵旭（学号1913169）**

1.语法分析：生成赋值表达式的语法树

2.中间代码：四元式的工具类；生成控制流语句for的中间代码

3.代码优化：标记符号表中的变量是否被使用

4.实验报告整合



#### 项目架构

---

- example目录
  - 运行测试用例的相关make指令
- grammar目录
  - ASTtree目录 -- 语法树相关源文件和头文件
  - InterMediate目录 -- 中间代码生成相关源文件和头文件、生成汇编头文件和相关原文件
  - symbol目录 -- 符号表相关源文件和头文件
  - Nodes.h -- 总头文件
  - SymbolTableTree.cpp / SymbolTableTree.h -- 生成符号表树

- test目录
  - 测试用例

- lexical.l
  - 词法分析文件
- grammar.y
  - 语法分析文件



#### 环境准备

---

- 编译环境：`Ubuntu LTS 20.04 desktop amd64`
- 运行环境：`Ubuntu LTS 16.04 desktop i386`
- 项目依赖：`build-essential` ,`flex`,`bison`,`g++`,`nasm`



#### 运行方式

---

- 在64位系统下，在根目录下依次执行`make clean`, `make run`, `make`, `make build`

- 切换到`build`目录下：`cd build`

- 执行`make all`

- 在`build`目录下即可看到名为`array1d`, `base`, `function_normal`, `function_recursive`, `pointer1d`, `struct`的可执行程序，将这些程序复制到32位操作系统上执行即可。



#### 主要思路

---

**一、实验目的** 

​		根据 C 语言设计编译器，包含词法分析、语法分析、语义分析、 中间代码生成及优化部分。学习汇编语言，将所生产中间代码转换为汇编语言，所得汇编语言用汇编器转换为二进制程序后运行。 

**二、实验内容及要求** 

**1. 词法分析器** 

- 输入源程序，输出对应的 token 表，符号表和词法错误信息。 
- 过滤空白符，跳过注释、换行符等无用符号；对源代码进行行列计数，用于指出含有错误的行列号，进行提醒。 

**2. 语法分析器** 

- 输入 token 串，通过语法分析，寻找其中语法错误。
- 自行实现文法，进行自底向上的移入归约，构建语法分析树。
- 文法实现基本的语法单位分析
  - 6 种算术运算（+，-，*，/，%，^）
  - 6 种关系运算（==，>，<，>=，<=，!=）
  - 3 种逻辑运算（&&（与），|| （或），!（非））
  - if 语句、else 语句、else if 语句、for 语句、 while 语句、声明语句、赋值语句、输入输出语句
  - **结构体、一维数组、指针**

**3. 语义分析和中间代码生成** 

- 在词法分析返回词法单元时，返回一些额外的信息， 诸如类型、数值和运算符等。
- 在语法分析构建语法树时，利用从词法分析返回的附加信息，在归约时添加相应的语义动作，对类型等语义规则进行分析，在出现错误时给出相应的错误提示。
- 对语法树进行遍历，同时为变量、函数、数组和指针等建立相应的符号表，进行全局的语义分析，以及提供更为完备的错误提示。
- 通过建立相应的符号表，在语义层面上对变量的定义与否、类型问题、函数参数的检查、函数定义与否等，进行信息维护，从而对变量未定义、变量重复定义、函数参数不匹配、函数未定义、函数已定义进行错误信息的收集以及报告。 

**4. 中间代码优化** 

- 在生成四元式序列时，标记符号表中的变量是否被使用； 在生成四元式序列后遍历之，删除未使用变量的定义四元式。

**三、实验方案设计** 

**1. 词法分析程序设计** 

- 工具介绍：采用 lex 进行实现。Lex 是一种生成扫描器的工具，常用 yacc 结合使用。其实现主要为两步，第一，以 Lex 可以理解的格式指定模式相关的动作，第二，在这一文件上运行 Lex，生成扫描器的 C 代码。 
- 设计原理：根据实验要求设计 lex 词法规则段，对于注释、空白符、数据类型(int、int* 等)、布尔值(true、false)、 控制流关键词(if、else、while、for、return 等)、运算符(<=、>=、==、!=、=、[]、&&、||、&、!、+、-、*、/、%、^、<、>、|等)、输入输出函数名、标识符、数字、字符串进行处理，返回 token 序列，同时对于非法格式调用yyerror 进行错误处理。 

**2. 语法分析程序设计** 

- 工具介绍：采用 yacc 实现。Yacc 的 GNU 版叫做 Bison。 它将任何一种编程语言的所有语法翻译成针对此种语言的 Yacc 语法解析器。它用巴科斯范式(BNF)来书写。用 Yacc 来创建一个编译器包括四个步骤： 第一，通过在语法文件上运行 Yacc 生成一个解析器。第二，编写一个 .y 的语法文件，将 lex 处理输入后的标记传递给解析器，编写一个函数，通过调用 yyparse() 来开始解析，编写错误处理例程（如 yyerror()）。第三，编译 Yacc 生成的代码以及其他相关的源文件。第四，将目标文件链接到适当的可执行解析器库。
- 设计原理: 根据课上所学，自行设计文法，总体思路为，C 语言源码由多个函数构成，函数按照函数定义格式组成，其中函数体部分由多条语句组成。语句包含 if 语句、if-else 语句、while 语句、for循环语句、变量声明语句、数组声明语句、return 返回语句和表达式。而表达式包括布尔表达式，函数调用表达式、算术表达式、赋值表达式、标识符、数字、字符串、数组取值、指针、取地址等。
- 设计特点： 将错误提示以错误输出流的方式输出到屏幕，同时以特殊控制字符将错误信息标志为红色。 
- 已实现语法： 
  - if-elseif-else语句 
  - while 语句
  - for 循环语句
  - 变量、数组、指针的定义以及使用 
  - 支持函数定义以及函数的调用 
  - 支持众多的表达式以及相关运算符 

**3. 语义分析的设计** 

- 设计原理：在语法分析的基础上，为每一个词法单元附上一个类型，从而在词法分析返回词法单元时，可以从词法分析之时所处的上下文环境中，将更多的信息随着词法单元的返回一同传递给语法树。 
- 具体实现方法： 在词法单元具有诸如类型、常量、标识符、运算符等相关信息后， 在产生式自底向上归约时，在产生式的最后附加语义动作，进行类型等语义检查。 为了进行后续的语法制导翻译，建立了抽象语法树，通过对抽象语法树的多趟遍历，建立完备的符号表，从而根据符号表， 检查变量的作用域，类型信息等，对变量的定义和使用，检查重复定义、未定义的错误和函数参数错误。通过为函数建立相关符号表，在函数的使用上进行了参数的检查以及相关错误的提示。

**4. 中间代码的生成级优化程序设计** 

- 设计原理：利用语法分析和语义分析建立的抽象语法树，结合回填的方式，对指令标号以及跳转指令的标号进行回填。 
- 具体实现方法： 在每生成一条中间代码时，为其标志序号，遍历结束后根据序号排序。同时在“归约”诸如 if-else 等具有复杂跳转指令的语句时，在恰当位置及时的回填目标标号。 在处理诸如 a and b，c or d 的具有跳转指令的条件判断表达式时，使用的是递归回填标号的方式，从而弥补了 yacc 不能推出空产生式也即无标记非终结符的问题。 在跳转指令的优化方面，利用程序会顺序向下执行的特点，对于条件判断的跳转指令做到了去冗余以及条件跳转指令的精简化。在代码优化方面， 根据活跃变量与非活跃变量，恰当的删除非活跃变量的定值语句，并且递归的回溯查找非活跃变量，从而一定程度上减少了临时变量的产生，提高生成汇编代码时的效率。 

 **5. 汇编生成程序的设计** 

- 设计原理选用精简指令集 MIPS 指令集，MIPS 包含 32 个通用寄存器， 这些寄存器的用法都遵循一系列约定，按照规定，通过对中间代码（四元式序列）进行格式识别，寄存器分配，翻译为对应的汇编指令。 



#### 实验总结

---

##### 遇到的困难和解决方法

> - 产生式和语义规则不适配。后期参考ANSI C grammar官方文档进行参考和修改。
> - 代码编译过程中经常遇到段错误。解决方法：没有注意对空指针的管理和判断，在程序中对空指针进行操作，引起段错误
> - 生成AST时对其在代码中的数据结构不清楚。解决方法：查询相关资料，决定使用树的儿子兄弟表示法

##### 心得体会

>  		通过此次实验，我们将课上所学应用于实践，对于编译器构造过程，诸如词法分析、语法分析、中间代码生成、代码优化都有了充分的了解，对于汇编语言进行了相应学习，了解了有关寄存器分配、底层语言逻辑构造等，有了很大的收获！ 



#### 程序源码

> 源码地址：https://github.com/5-Dead-Pigs-With-25-Points/c-compiler.git

