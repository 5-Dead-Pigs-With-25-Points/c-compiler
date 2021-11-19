/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./grammar.y"

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "./grammar/Nodes.h"  

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

#line 90 "./parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OR = 258,
    AND = 259,
    RELOP = 260,
    LOWER_THAN_ELSE = 261,
    ELSE = 262,
    ERRORID = 263,
    ID = 264,
    INT = 265,
    STR = 266,
    TYPE = 267,
    STRUCT = 268,
    IF = 269,
    WHILE = 270,
    FOR = 271,
    CONTINUE = 272,
    RETURN = 273,
    ERRORCHAR = 274,
    GETMEMBER = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "./grammar.y"

    ASTREE::RootNode* astree;
    char* str;

#line 168 "./parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   511

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

#define YYUNDEFTOK  2
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    14,     2,     2,     2,    12,     4,     2,
      15,    16,    10,     8,    26,     9,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    17,     2,    18,    13,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,    19,    20,    21,    22,    23,    24,    25,    28,    29,
      30,    31,    32,    33,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    66,    69,    90,    98,    99,   105,   110,
     113,   117,   120,   131,   132,   160,   163,   168,   183,   186,
     203,   212,   215,   224,   227,   233,   237,   243,   248,   257,
     271,   277,   284,   290,   296,   302,   308,   314,   320,   326,
     332,   335,   340,   345,   348,   351,   354,   361,   369,   372,
     378,   384,   388,   391,   398,   403,   406,   409,   415,   425,
     428,   429,   435,   436,   443,   444,   448,   453,   458,   463,
     464,   469,   473,   479,   486,   491,   496,   501,   506,   511,
     516,   521,   526,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'&'", "OR", "AND", "RELOP",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'!'", "'('", "')'", "'['",
  "']'", "LOWER_THAN_ELSE", "ELSE", "ERRORID", "ID", "INT", "STR", "TYPE",
  "','", "';'", "STRUCT", "IF", "WHILE", "FOR", "CONTINUE", "RETURN",
  "ERRORCHAR", "GETMEMBER", "'{'", "'}'", "$accept", "program",
  "translation_unit", "external_declaration", "declarators_init",
  "declarator_init", "declaration_specifier", "struct_definition",
  "struct_parameters", "struct_parameter", "variable_declarator",
  "function_declarator", "parameter_list", "parameter_declaration",
  "expression", "argument_expression_list", "compound_statement",
  "block_list", "definition", "declaration_list", "declaration",
  "for_definition", "statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,    61,    38,   258,   259,   260,    43,    45,
      42,    47,    37,    94,    33,    40,    41,    91,    93,   261,
     262,   263,   264,   265,   266,   267,    44,    59,   268,   269,
     270,   271,   272,   273,   274,   275,   123,   125
};
# endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,    -6,    12,    13,    56,    15,   -57,    48,    40,   -57,
     -57,    21,   -57,   -57,    27,   -57,    54,   -57,    66,     5,
     -57,    52,    -2,    67,    70,   -57,    71,    59,   -57,   140,
     -57,    70,   -17,   -57,   -57,    77,     1,   -57,    84,    87,
     -57,   -57,   -57,    -9,    85,   363,    86,   363,   363,    -5,
     -57,   -57,    92,   101,   105,   106,    64,    70,   235,   -57,
     109,    95,   -57,    58,   -57,   -57,   -57,   -57,    52,   -57,
     -57,   102,   -57,   114,   115,   -57,   -57,   399,   283,   363,
     113,   121,   363,   363,   171,   -57,   246,   133,   -57,   122,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   483,     3,
     385,   -57,   120,   411,   423,    -3,   196,   483,   -57,   124,
     -57,   363,    70,   483,   491,   498,    51,   115,   115,   139,
     139,   139,   139,   -57,   363,   -57,   -57,   140,   140,   -57,
     299,   258,   212,   483,   -57,   483,   136,   -57,   140,   435,
     315,   331,   269,   140,   -57,   140,   140,   447,   140,   459,
     347,   -57,   -57,   -57,   140,   -57,   140,   140,   471,   -57,
     -57,   -57,   140,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,     0,     0,     0,     3,     0,     0,    10,
      16,     0,     1,     4,    21,     6,     0,    11,    13,     0,
       9,     0,     0,     0,     0,     5,     0,     0,     8,     0,
       7,     0,     0,    18,    24,    28,     0,    26,     0,    21,
      12,    14,    55,     0,     0,     0,     0,     0,     0,    45,
      48,    44,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,    57,     0,    17,    19,    27,    23,     0,    22,
      51,    83,    50,     0,    41,    49,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,    62,    58,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    54,    56,    67,    20,    25,    40,    43,    52,     0,
       0,    47,     0,     0,     0,     0,     0,    65,    64,     0,
      70,     0,     0,    29,    31,    30,    38,    32,    33,    34,
      35,    36,    37,    42,     0,    46,    68,     0,     0,    59,
       0,     0,     0,    63,    61,    53,    72,    74,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,    73,    78,    77,     0,    76,     0,     0,     0,    82,
      81,    80,     0,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   148,   126,   134,     4,   -57,   -57,   127,
     -56,   -57,   -57,    93,   -45,   -57,   141,   -57,    82,    45,
     -57,   -57,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    16,    17,    57,     8,    32,    33,
      18,    19,    36,    37,    58,   109,    59,    60,    61,    88,
      89,   119,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    87,    76,    77,     7,   102,    27,    70,     2,     7,
      78,    86,    79,    70,    34,    -2,     1,    67,    71,   133,
      64,     9,    10,     2,   139,    31,    35,    68,    42,   134,
      80,     1,    28,   108,   110,    11,    31,   113,   114,   117,
       2,    29,    22,     3,    23,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     2,    12,    21,     3,    94,
      95,    96,    97,    98,    99,    73,    87,    20,    44,    26,
      14,   141,    35,    45,    46,    15,   143,     2,    47,    48,
      24,    25,   146,   147,    24,   104,    49,    50,    51,   145,
      38,    85,    39,   154,    41,   149,    42,   152,   161,    66,
     162,   163,    69,   165,    23,   157,   159,    72,    75,   169,
      43,   170,   171,    44,    81,   168,    82,   173,    45,    46,
      83,    84,   103,    47,    48,    96,    97,    98,    99,   -59,
      70,    49,    50,    51,     2,   111,   121,    52,    53,    54,
      55,    43,    56,   112,    44,    29,   101,   136,   122,    45,
      46,   142,    99,    13,    47,    48,   153,    63,    40,    65,
      30,   105,    49,    50,    51,     2,   118,   144,    52,    53,
      54,    55,   115,    56,     0,    44,    29,     0,     0,     0,
      45,    46,     0,     0,     0,    47,    48,     0,     0,     0,
       0,     0,     0,    49,    50,    51,     2,    73,   116,     0,
      44,     0,     0,     0,     0,    45,    46,     0,     0,     0,
      47,    48,     0,    73,     0,     0,    44,     0,    49,    50,
      51,    45,    46,   140,     0,     0,    47,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,     0,    90,   151,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    90,
       0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,    90,   100,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    90,   120,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,    73,   150,     0,    44,     0,     0,
       0,     0,    45,    46,     0,     0,   160,    47,    48,   107,
      73,     0,     0,    44,     0,    49,    50,    51,    45,    46,
       0,     0,     0,    47,    48,   148,    73,     0,     0,    44,
       0,    49,    50,    51,    45,    46,     0,     0,     0,    47,
      48,   156,    73,     0,     0,    44,     0,    49,    50,    51,
      45,    46,     0,     0,     0,    47,    48,   158,    73,     0,
       0,    44,     0,    49,    50,    51,    45,    46,     0,     0,
       0,    47,    48,   167,    73,     0,     0,    44,     0,    49,
      50,    51,    45,    46,     0,     0,     0,    47,    48,     0,
       0,     0,     0,     0,     0,    49,    50,    51,    90,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,    90,   135,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,    90,   106,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,    90,   137,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,    90,   138,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
      90,   155,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,    90,   164,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,    90,   166,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,    90,   172,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    92,    93,    94,
      95,    96,    97,    98,    99,    93,    94,    95,    96,    97,
      98,    99
};

static const yytype_int16 yycheck[] =
{
      45,    57,    47,    48,     0,    60,     1,    16,    25,     5,
      15,    56,    17,    16,    16,     0,     1,    16,    27,    16,
      37,    27,    10,    25,    27,    21,    22,    26,    37,    26,
      35,     1,    27,    78,    79,    22,    32,    82,    83,    84,
      25,    36,    15,    28,    17,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    25,     0,    36,    28,     8,
       9,    10,    11,    12,    13,     1,   122,    27,     4,     3,
      22,   116,    68,     9,    10,    27,   121,    25,    14,    15,
      26,    27,   137,   138,    26,    27,    22,    23,    24,   134,
      23,    27,    22,   148,    23,   140,    37,   142,   153,    22,
     155,   156,    18,   158,    17,   150,   151,    22,    22,   164,
       1,   166,   167,     4,    22,   160,    15,   172,     9,    10,
      15,    15,    27,    14,    15,    10,    11,    12,    13,    27,
      16,    22,    23,    24,    25,    22,     3,    28,    29,    30,
      31,     1,    33,    22,     4,    36,    37,    27,    26,     9,
      10,    27,    13,     5,    14,    15,    20,    31,    24,    32,
      19,    68,    22,    23,    24,    25,    84,   122,    28,    29,
      30,    31,     1,    33,    -1,     4,    36,    -1,    -1,    -1,
       9,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,     1,    27,    -1,
       4,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    -1,
      14,    15,    -1,     1,    -1,    -1,     4,    -1,    22,    23,
      24,     9,    10,    27,    -1,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,     3,    27,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,     3,    27,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     3,    27,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     1,    27,    -1,     4,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    27,    14,    15,    16,
       1,    -1,    -1,     4,    -1,    22,    23,    24,     9,    10,
      -1,    -1,    -1,    14,    15,    16,     1,    -1,    -1,     4,
      -1,    22,    23,    24,     9,    10,    -1,    -1,    -1,    14,
      15,    16,     1,    -1,    -1,     4,    -1,    22,    23,    24,
       9,    10,    -1,    -1,    -1,    14,    15,    16,     1,    -1,
      -1,     4,    -1,    22,    23,    24,     9,    10,    -1,    -1,
      -1,    14,    15,    16,     1,    -1,    -1,     4,    -1,    22,
      23,    24,     9,    10,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,     3,    18,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     3,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,     3,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,     3,    16,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       3,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     3,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     3,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,     3,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,     7,     8,     9,    10,    11,
      12,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    25,    28,    39,    40,    41,    44,    45,    27,
      10,    22,     0,    41,    22,    27,    42,    43,    48,    49,
      27,    36,    15,    17,    26,    27,     3,     1,    27,    36,
      54,    44,    46,    47,    16,    44,    50,    51,    23,    22,
      43,    23,    37,     1,     4,     9,    10,    14,    15,    22,
      23,    24,    28,    29,    30,    31,    33,    44,    52,    54,
      55,    56,    60,    42,    37,    47,    22,    16,    26,    18,
      16,    27,    22,     1,    52,    22,    52,    52,    15,    17,
      35,    22,    15,    15,    15,    27,    52,    48,    57,    58,
       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      27,    37,    60,    27,    27,    51,    16,    16,    52,    53,
      52,    22,    22,    52,    52,     1,    27,    52,    56,    59,
      27,     3,    26,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    16,    26,    18,    27,    16,    16,    27,
      27,    52,    27,    52,    57,    52,    60,    60,    16,    52,
      27,    27,    52,    20,    60,    16,    16,    52,    16,    52,
      27,    60,    60,    60,    16,    60,    16,    16,    52,    60,
      60,    60,    16,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    42,    42,    43,    43,    44,    44,    45,    46,    46,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     2,
       2,     1,     3,     1,     3,     1,     2,     5,     1,     2,
       3,     1,     4,     4,     3,     3,     1,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     4,     3,     1,     1,     4,     3,     1,     2,
       2,     2,     1,     3,     3,     2,     2,     1,     2,     2,
       1,     3,     1,     3,     1,     1,     2,     2,     4,     1,
       3,     2,     5,     7,     5,     6,     7,     7,     7,     9,
       8,     8,     8,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 59 "./grammar.y"
                          {
		root = new RootNode("begin", ASTREE::root);
		root -> addChildNode((yyvsp[0].astree));
	}
#line 1641 "./parser.tab.cpp"
    break;

  case 3:
#line 66 "./grammar.y"
                                       {
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 1649 "./parser.tab.cpp"
    break;

  case 4:
#line 69 "./grammar.y"
                                            {
        if ((yyvsp[-1].astree) == NULL) {
			(yyval.astree) = (yyvsp[0].astree);
        } else {
			if ((yyvsp[0].astree) != NULL) {
				(yyvsp[-1].astree) -> getLastPeerNode() -> addPeerNode((yyvsp[0].astree));
			}
			(yyval.astree) = (yyvsp[-1].astree);
		}
	}
#line 1664 "./parser.tab.cpp"
    break;

  case 5:
#line 90 "./grammar.y"
                                                                 {
		ASTREE::RootNode* statement = new ASTREE::StatementNode(ASTREE::definition);
		ASTREE::DefineVarNode* variable = (ASTREE::DefineVarNode*)(yyvsp[-1].astree);
		cout << (yyvsp[-2].str) << endl;
		variable -> setAllSymbolType((yyvsp[-2].str));
		statement -> addChildNode(variable);
		(yyval.astree) = statement; 
	}
#line 1677 "./parser.tab.cpp"
    break;

  case 6:
#line 98 "./grammar.y"
                                    {}
#line 1683 "./parser.tab.cpp"
    break;

  case 7:
#line 99 "./grammar.y"
                                                                       {
		ASTREE::DefineFunctionNode* func = (ASTREE::DefineFunctionNode*) (yyvsp[-1].astree);
		func -> addChildNode((yyvsp[0].astree));
		func -> setReturnSymbolType((yyvsp[-2].str));
		(yyval.astree) = func;
	}
#line 1694 "./parser.tab.cpp"
    break;

  case 8:
#line 105 "./grammar.y"
                                                        {
		ASTREE::DefineFunctionNode* func = (ASTREE::DefineFunctionNode*) (yyvsp[-1].astree);
		func -> setReturnSymbolType((yyvsp[-2].str));
		(yyval.astree) = func;
	}
#line 1704 "./parser.tab.cpp"
    break;

  case 9:
#line 110 "./grammar.y"
                                {
		(yyval.astree) = (yyvsp[-1].astree);
	}
#line 1712 "./parser.tab.cpp"
    break;

  case 10:
#line 113 "./grammar.y"
                    { yyerrok; (yyval.astree) = NULL; }
#line 1718 "./parser.tab.cpp"
    break;

  case 11:
#line 117 "./grammar.y"
                                  {
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 1726 "./parser.tab.cpp"
    break;

  case 12:
#line 120 "./grammar.y"
                                               {
		(yyvsp[-2].astree) -> getLastPeerNode() -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = (yyvsp[-2].astree);
	}
#line 1735 "./parser.tab.cpp"
    break;

  case 13:
#line 131 "./grammar.y"
                                     {(yyval.astree) = (yyvsp[0].astree);}
#line 1741 "./parser.tab.cpp"
    break;

  case 14:
#line 132 "./grammar.y"
                                  {
        ASTREE::RootNode* ope = new ASTREE::OperatorNode("=", ASTREE::assign);
        ASTREE::RootNode* t = new ASTREE::LiteralNode((yyvsp[0].str));
        ope -> addChildNode((yyvsp[-2].astree));
        (yyvsp[-2].astree) -> addPeerNode(t);
        (yyval.astree) = ope;
    }
#line 1753 "./parser.tab.cpp"
    break;

  case 15:
#line 160 "./grammar.y"
                            {
		(yyval.str) = (yyvsp[0].str);
	}
#line 1761 "./parser.tab.cpp"
    break;

  case 16:
#line 163 "./grammar.y"
                   {
		(yyval.str) = strcat((yyvsp[-1].str), " pointer");
	}
#line 1769 "./parser.tab.cpp"
    break;

  case 17:
#line 168 "./grammar.y"
                                                       {
		if(struct_table == NULL) {
			struct_table = new SMB::StructTable();
		}
		SMB::StructSymbol* current_struct = new SMB::StructSymbol((yyvsp[-3].str), (yyvsp[-1].astree));
		struct_table -> addStruct(current_struct);
		(yyval.astree) = NULL;
    }
#line 1782 "./parser.tab.cpp"
    break;

  case 18:
#line 183 "./grammar.y"
                                    {
        (yyval.astree) = (yyvsp[0].astree);
    }
#line 1790 "./parser.tab.cpp"
    break;

  case 19:
#line 186 "./grammar.y"
                                         {
        (yyvsp[-1].astree) -> getLastPeerNode() -> addPeerNode((yyvsp[0].astree));
        (yyval.astree) = (yyvsp[-1].astree);
    }
#line 1799 "./parser.tab.cpp"
    break;

  case 20:
#line 203 "./grammar.y"
                                                             {
	ASTREE::RootNode* statement = new ASTREE::StatementNode(ASTREE::definition);
	ASTREE::DefineVarNode* variable = (ASTREE::DefineVarNode*)(yyvsp[-1].astree);
	variable -> setAllSymbolType((yyvsp[-2].str));
	statement -> addChildNode(variable);
	(yyval.astree) = statement;
}
#line 1811 "./parser.tab.cpp"
    break;

  case 21:
#line 212 "./grammar.y"
                        {
		(yyval.astree) = new ASTREE::DefineVarNode((yyvsp[0].str));
    }
#line 1819 "./parser.tab.cpp"
    break;

  case 22:
#line 215 "./grammar.y"
                     {
        ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode((yyvsp[-3].str));
        var -> setAllSymbolType("array");
        var -> setArrayLength((yyvsp[-1].str));
        (yyval.astree) = var; 
    }
#line 1830 "./parser.tab.cpp"
    break;

  case 23:
#line 224 "./grammar.y"
                                               {
		(yyval.astree) = new ASTREE::DefineFunctionNode((yyvsp[-3].str), (yyvsp[-1].astree));
    }
#line 1838 "./parser.tab.cpp"
    break;

  case 24:
#line 227 "./grammar.y"
                 {
		(yyval.astree) = new ASTREE::DefineFunctionNode((yyvsp[-2].str));
    }
#line 1846 "./parser.tab.cpp"
    break;

  case 25:
#line 233 "./grammar.y"
                                                         {
		(yyvsp[-2].astree) -> getLastPeerNode() -> addPeerNode((yyvsp[0].astree));
        (yyval.astree)  =(yyvsp[-2].astree);
    }
#line 1855 "./parser.tab.cpp"
    break;

  case 26:
#line 237 "./grammar.y"
                            {
		(yyval.astree) = (yyvsp[0].astree);
    }
#line 1863 "./parser.tab.cpp"
    break;

  case 27:
#line 243 "./grammar.y"
                                                {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode((yyvsp[0].str));
		var -> setAllSymbolType((yyvsp[-1].str));
		(yyval.astree) = var;
	}
#line 1873 "./parser.tab.cpp"
    break;

  case 28:
#line 248 "./grammar.y"
                                {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode("");
		var -> setAllSymbolType((yyvsp[0].str));
	    (yyval.astree) = var;
	}
#line 1883 "./parser.tab.cpp"
    break;

  case 29:
#line 257 "./grammar.y"
                                     {									/* 赋值运算 */
		RootNode* assignOpNode = new ASTREE::OperatorNode("=", ASTREE::assign);
		if((yyvsp[-2].astree)->getASTNodeType() == ASTREE::op) {
			ASTREE::OperatorNode *leftOpNode = (ASTREE::OperatorNode *)(yyvsp[-2].astree);
			if(leftOpNode->getOpType() == ASTREE::get_member) {			/* 对对象属性赋值 */
				leftOpNode->setOpType(ASTREE::assign_member);
			} else if(leftOpNode->getOpType() == ASTREE::get_arr_var) {	/* 对数组元素赋值 */
				leftOpNode->setOpType(ASTREE::assign_arr);
			}
		}
		assignOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = assignOpNode;
	}
#line 1902 "./parser.tab.cpp"
    break;

  case 30:
#line 271 "./grammar.y"
                                    {										/* 与运算 */
		RootNode* andOpNode = new ASTREE::OperatorNode("&&", ASTREE::and_op);
		andOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = andOpNode;
	}
#line 1913 "./parser.tab.cpp"
    break;

  case 31:
#line 277 "./grammar.y"
                                   {
		RootNode* orOpNode = new ASTREE::OperatorNode("||", ASTREE::or_op);
		orOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = orOpNode;
	}
#line 1924 "./parser.tab.cpp"
    break;

  case 32:
#line 284 "./grammar.y"
                                    {										/* 加运算 */
		RootNode* addOpNode = new ASTREE::OperatorNode("+", ASTREE::add);
		addOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = addOpNode;
	}
#line 1935 "./parser.tab.cpp"
    break;

  case 33:
#line 290 "./grammar.y"
                                    {										/* 减运算 */
		RootNode* minusOpNode = new ASTREE::OperatorNode("-", ASTREE::minus);
		minusOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = minusOpNode;
	}
#line 1946 "./parser.tab.cpp"
    break;

  case 34:
#line 296 "./grammar.y"
                                    {										/* 乘运算 */
		RootNode* multiOpNode = new ASTREE::OperatorNode("*", ASTREE::multi);
		multiOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = multiOpNode;
	}
#line 1957 "./parser.tab.cpp"
    break;

  case 35:
#line 302 "./grammar.y"
                                    {										/* 除运算 */
		RootNode* divOpNode = new ASTREE::OperatorNode("/", ASTREE::div);
		divOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = divOpNode;
	}
#line 1968 "./parser.tab.cpp"
    break;

  case 36:
#line 308 "./grammar.y"
                                    {										/* 取模运算 */
		RootNode* modOpNode = new ASTREE::OperatorNode("%", ASTREE::mod);
		modOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = modOpNode;
	}
#line 1979 "./parser.tab.cpp"
    break;

  case 37:
#line 314 "./grammar.y"
                                    {										/* 幂运算 */
		RootNode* powOpNode = new ASTREE::OperatorNode("^", ASTREE::pow);
		powOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = powOpNode;
	}
#line 1990 "./parser.tab.cpp"
    break;

  case 38:
#line 320 "./grammar.y"
                                      {
		RootNode* temp = new ASTREE::OperatorNode((yyvsp[-1].str), ASTREE::relop);
		temp->addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree)->addPeerNode((yyvsp[0].astree));
		(yyval.astree) = temp;
        }
#line 2001 "./parser.tab.cpp"
    break;

  case 39:
#line 326 "./grammar.y"
                         {													/* 非运算（单目） */
		RootNode* notOpNode = new ASTREE::OperatorNode("!", ASTREE::not_op);
		notOpNode -> addChildNode((yyvsp[-1].astree));
		(yyvsp[-1].astree) -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = notOpNode;
	}
#line 2012 "./parser.tab.cpp"
    break;

  case 40:
#line 332 "./grammar.y"
                             {												/**/
		(yyval.astree) = (yyvsp[-1].astree);
	}
#line 2020 "./parser.tab.cpp"
    break;

  case 41:
#line 335 "./grammar.y"
                         {													/* 负值 */
		RootNode* negNode = new ASTREE::OperatorNode("-", ASTREE::negative);
		negNode -> addChildNode((yyvsp[0].astree));
		(yyval.astree) = negNode;
	}
#line 2030 "./parser.tab.cpp"
    break;

  case 42:
#line 340 "./grammar.y"
                                              {								/* 调用函数 */
		ASTREE::CallFuncNode* callNode = new ASTREE::CallFuncNode((yyvsp[-3].str));
		callNode -> setArgList((yyvsp[-1].astree));
		(yyval.astree) = callNode;
	}
#line 2040 "./parser.tab.cpp"
    break;

  case 43:
#line 345 "./grammar.y"
                     {														/* 调用无参数函数 */
		(yyval.astree) = new ASTREE::CallFuncNode((yyvsp[-2].str));
	}
#line 2048 "./parser.tab.cpp"
    break;

  case 44:
#line 348 "./grammar.y"
              {
		(yyval.astree) = new ASTREE::CallVarNode((yyvsp[0].str));
	}
#line 2056 "./parser.tab.cpp"
    break;

  case 45:
#line 351 "./grammar.y"
             {
		(yyval.astree) = new ASTREE::CallVarNode((yyvsp[0].str));
	}
#line 2064 "./parser.tab.cpp"
    break;

  case 46:
#line 354 "./grammar.y"
                                {											/* 取数组元素，[]内可为expression */
		RootNode* getVarNode = new ASTREE::OperatorNode("[]", ASTREE::get_arr_var);
		RootNode* temp = new ASTREE::CallVarNode((yyvsp[-3].str));
		getVarNode -> addChildNode(temp);
		temp -> addPeerNode((yyvsp[-1].astree));
		(yyval.astree) = getVarNode;
	}
#line 2076 "./parser.tab.cpp"
    break;

  case 47:
#line 361 "./grammar.y"
                          {													/* 获取对象成员属性 */
		RootNode* getMemberNode = new ASTREE::OperatorNode(".", ASTREE::get_member);
		ASTREE::CallVarNode* var1 = new ASTREE::CallVarNode((yyvsp[-2].str));
		ASTREE::CallVarNode* var2 = new ASTREE::CallVarNode((yyvsp[0].str));
		getMemberNode -> addChildNode(var1);
		var1 -> addPeerNode(var2);
		(yyval.astree) = getMemberNode;
	}
#line 2089 "./parser.tab.cpp"
    break;

  case 48:
#line 369 "./grammar.y"
              {																/* 字面量节点 */
		(yyval.astree) = new ASTREE::LiteralNode((yyvsp[0].str));
	}
#line 2097 "./parser.tab.cpp"
    break;

  case 49:
#line 372 "./grammar.y"
                 {															/* 指针取值 */
		RootNode* starNode = new ASTREE::OperatorNode("*", ASTREE::get_value);
		ASTREE::CallVarNode* var = new ASTREE::CallVarNode((yyvsp[0].str));
		starNode -> addChildNode(var);
		(yyval.astree) = var;
	}
#line 2108 "./parser.tab.cpp"
    break;

  case 50:
#line 378 "./grammar.y"
                 {															/* 取地址 */
		RootNode* getAddressNode = new ASTREE::OperatorNode("&", ASTREE::get_address);
		RootNode* temp = new ASTREE::CallVarNode((yyvsp[0].str));
		getAddressNode -> addChildNode(temp);
		(yyval.astree) = temp;
	}
#line 2119 "./parser.tab.cpp"
    break;

  case 51:
#line 384 "./grammar.y"
                    {yyerrok;}
#line 2125 "./parser.tab.cpp"
    break;

  case 52:
#line 388 "./grammar.y"
                                     {										
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 2133 "./parser.tab.cpp"
    break;

  case 53:
#line 391 "./grammar.y"
                                                  {
		(yyvsp[-2].astree) -> getLastPeerNode() -> addPeerNode((yyvsp[0].astree));
		(yyval.astree) = (yyvsp[-2].astree);
	}
#line 2142 "./parser.tab.cpp"
    break;

  case 54:
#line 398 "./grammar.y"
                                       {
        RootNode* t= new ASTREE::StatementNode(ASTREE::compoundation);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2152 "./parser.tab.cpp"
    break;

  case 55:
#line 403 "./grammar.y"
                { yyerrok; }
#line 2158 "./parser.tab.cpp"
    break;

  case 56:
#line 406 "./grammar.y"
                                 {
        (yyvsp[-1].astree)->getLastPeerNode()->addPeerNode((yyvsp[0].astree));
    }
#line 2166 "./parser.tab.cpp"
    break;

  case 57:
#line 409 "./grammar.y"
                {
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 2174 "./parser.tab.cpp"
    break;

  case 58:
#line 415 "./grammar.y"
                                                    {
        if ((yyvsp[0].astree)->getASTNodeType() == ASTREE::op) {								/* 有初始化的声明 */				
            ASTREE::OperatorNode* t = (ASTREE::OperatorNode*)(yyvsp[0].astree);
            t->setAllSymbolType((yyvsp[-1].str));
        } else {
            ASTREE::DefineVarNode* t= (ASTREE::DefineVarNode*)(yyvsp[0].astree);
            t->setAllSymbolType((yyvsp[-1].str));
        }
        (yyval.astree) = (yyvsp[0].astree);
    }
#line 2189 "./parser.tab.cpp"
    break;

  case 59:
#line 425 "./grammar.y"
                { yyerrok; }
#line 2195 "./parser.tab.cpp"
    break;

  case 60:
#line 428 "./grammar.y"
                              { (yyval.astree) = (yyvsp[0].astree); }
#line 2201 "./parser.tab.cpp"
    break;

  case 61:
#line 429 "./grammar.y"
                                       {
        (yyvsp[-2].astree)->getLastPeerNode()->addPeerNode((yyvsp[0].astree));
        (yyval.astree) = (yyvsp[-2].astree);
    }
#line 2210 "./parser.tab.cpp"
    break;

  case 62:
#line 435 "./grammar.y"
                                { (yyval.astree) = (yyvsp[0].astree); }
#line 2216 "./parser.tab.cpp"
    break;

  case 63:
#line 436 "./grammar.y"
                                         {
        (yyval.astree) = new ASTREE::OperatorNode("=", ASTREE::assign);
        (yyval.astree)->addChildNode((yyvsp[-2].astree));
        (yyvsp[-2].astree)->addPeerNode((yyvsp[0].astree));
    }
#line 2226 "./parser.tab.cpp"
    break;

  case 64:
#line 443 "./grammar.y"
                           { (yyval.astree) = (yyvsp[0].astree);}
#line 2232 "./parser.tab.cpp"
    break;

  case 65:
#line 444 "./grammar.y"
                     {(yyval.astree) = (yyvsp[0].astree);}
#line 2238 "./parser.tab.cpp"
    break;

  case 66:
#line 448 "./grammar.y"
                          { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::expression);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2248 "./parser.tab.cpp"
    break;

  case 67:
#line 453 "./grammar.y"
                     { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::definition);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2258 "./parser.tab.cpp"
    break;

  case 68:
#line 458 "./grammar.y"
                       { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::definition);
        RootNode* structDefinitionNode = new ASTREE::DefineVarNode((yyvsp[-1].str), (yyvsp[-2].str));
        t->addChildNode(structDefinitionNode);
        (yyval.astree) = t; }
#line 2268 "./parser.tab.cpp"
    break;

  case 69:
#line 463 "./grammar.y"
                         { (yyval.astree)=(yyvsp[0].astree);}
#line 2274 "./parser.tab.cpp"
    break;

  case 70:
#line 464 "./grammar.y"
                            {
        RootNode* t= new ASTREE::StatementNode(ASTREE::return_stmt);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2284 "./parser.tab.cpp"
    break;

  case 71:
#line 469 "./grammar.y"
                 {
        RootNode* t= new ASTREE::StatementNode(ASTREE::return_stmt);
        (yyval.astree) = t;
    }
#line 2293 "./parser.tab.cpp"
    break;

  case 72:
#line 473 "./grammar.y"
                                      {  
        ASTREE::SelectNode* t= new ASTREE::SelectNode(ASTREE::if_stmt);
        t->setBodyNode((yyvsp[0].astree));
        t->setCondNode((yyvsp[-2].astree));
        (yyval.astree) = t;
    }
#line 2304 "./parser.tab.cpp"
    break;

  case 73:
#line 479 "./grammar.y"
                                                                          {
        ASTREE::SelectNode* t= new ASTREE::SelectNode(ASTREE::if_stmt);
        t->setBodyNode((yyvsp[-2].astree));
        t->setCondNode((yyvsp[-4].astree));
        t->setElseNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2316 "./parser.tab.cpp"
    break;

  case 74:
#line 486 "./grammar.y"
                                         {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::while_loop, (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2326 "./parser.tab.cpp"
    break;

  case 75:
#line 491 "./grammar.y"
                                   {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, NULL, NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2336 "./parser.tab.cpp"
    break;

  case 76:
#line 496 "./grammar.y"
                                                  {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, (yyvsp[-4].astree), NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2346 "./parser.tab.cpp"
    break;

  case 77:
#line 501 "./grammar.y"
                                              { 
        RootNode* t = new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-3].astree), NULL, NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2356 "./parser.tab.cpp"
    break;

  case 78:
#line 506 "./grammar.y"
                                              {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, NULL, (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2366 "./parser.tab.cpp"
    break;

  case 79:
#line 511 "./grammar.y"
                                                                         {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-4].astree), (yyvsp[-6].astree), (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2376 "./parser.tab.cpp"
    break;

  case 80:
#line 516 "./grammar.y"
                                                               {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-3].astree), (yyvsp[-5].astree), NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2386 "./parser.tab.cpp"
    break;

  case 81:
#line 521 "./grammar.y"
                                                               {
        RootNode* t = new ASTREE::LoopNode("", ASTREE::for_loop, NULL, (yyvsp[-5].astree), (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2396 "./parser.tab.cpp"
    break;

  case 82:
#line 526 "./grammar.y"
                                                          {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-4].astree), NULL, (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2406 "./parser.tab.cpp"
    break;

  case 83:
#line 531 "./grammar.y"
                { yyerrok; }
#line 2412 "./parser.tab.cpp"
    break;


#line 2416 "./parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 534 "./grammar.y"


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
	if(root) delete root;
	return 0;
}
