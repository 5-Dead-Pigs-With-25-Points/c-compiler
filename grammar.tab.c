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
#line 1 "grammar.y"

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "./grammar/Nodes.h"  

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

#line 88 "grammar.tab.c"

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
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
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
    ERROID = 262,
    ID = 263,
    INT = 264,
    TYPE = 265,
    STRUCT = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    FOR = 270,
    CONTINUE = 271,
    RETURN = 272,
    ERRORCHAR = 273,
    GETMEMBER = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "grammar.y"

    ASTREE: Node* astree;
    char* str;

#line 165 "grammar.tab.c"

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

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */



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
#define YYLAST   475

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


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
      15,    16,    10,     8,    24,     9,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    17,     2,    18,    13,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
       7,    19,    20,    21,    22,    23,    26,    27,    28,    29,
      30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    63,    66,    87,    94,    95,   101,   106,
     109,   113,   116,   127,   130,   156,   159,   164,   179,   182,
     199,   208,   211,   220,   223,   229,   233,   239,   244,   253,
     267,   273,   279,   285,   291,   297,   303,   309,   315,   321,
     327,   330,   335,   340,   343,   346,   353,   361,   364,   370,
     376,   380,   383,   390,   395,   398,   401,   407,   417,   420,
     421,   427,   428,   436,   441,   446,   451,   452,   457,   461,
     467,   474,   479,   484,   489,   494,   499,   504,   509,   514,
     519
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'&'", "OR", "AND", "RELOP",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'!'", "'('", "')'", "'['",
  "']'", "LOWER_THAN_ELSE", "ERROID", "ID", "INT", "TYPE", "','", "';'",
  "STRUCT", "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "RETURN",
  "ERRORCHAR", "GETMEMBER", "'{'", "'}'", "$accept", "program",
  "translation_unit", "external_declaration", "declarators_init",
  "declarator_init", "declaration_specifier", "struct_definition",
  "struct_parameters", "struct_parameter", "variable_declarator",
  "function_declarator", "parameter_list", "parameter_declaration",
  "expression", "argument_expression_list", "compound_statement",
  "block_list", "definition", "declaration_list", "declaration",
  "statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,    61,    38,   258,   259,   260,    43,    45,
      42,    47,    37,    94,    33,    40,    41,    91,    93,   261,
     262,   263,   264,   265,    44,    59,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   123,   125
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    18,    11,    34,    61,     8,   -56,    -2,    42,   -56,
     -56,    30,   -56,   -56,     5,   -56,    57,   -56,    66,     0,
     -56,    52,     1,    56,    70,   -56,    63,    60,   -56,   130,
     -56,    70,    -9,   -56,   -56,    72,    38,   -56,    81,    84,
     -56,   -56,   -56,   -10,    83,   331,    90,   331,   331,    -4,
     -56,    92,   102,   103,   104,    62,    70,   194,   -56,   106,
      80,   -56,    64,   -56,   -56,   -56,   -56,    52,   -56,   -56,
      97,   -56,   107,    47,   -56,   -56,   365,   251,   331,   105,
     109,   331,   331,    17,   -56,   205,   121,   -56,   101,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   449,    40,   351,
     -56,   112,   377,   389,   118,   154,   122,   -56,   331,    70,
     449,   214,   456,   462,    47,    47,   133,   133,   133,   133,
     -56,   331,   -56,   -56,   130,   130,   -56,   267,   226,   173,
     449,   -56,   449,   120,   -56,   130,   401,   283,   299,   237,
     130,   -56,   130,   130,   413,   130,   425,   315,   -56,   -56,
     -56,   130,   -56,   130,   130,   437,   -56,   -56,   -56,   130,
     -56
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
      12,    14,    54,     0,     0,     0,     0,     0,     0,    44,
      47,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,    56,     0,    17,    19,    27,    23,     0,    22,    50,
      80,    49,     0,    41,    48,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,    61,    57,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      53,    55,    64,    20,    25,    40,    43,    51,     0,     0,
      46,     0,     0,     0,     0,     0,     0,    67,     0,     0,
      29,    31,    30,    32,    33,    34,    35,    36,    37,    38,
      42,     0,    45,    65,     0,     0,    58,     0,     0,     0,
      62,    60,    52,    69,    71,     0,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,     0,    70,    75,
      74,     0,    73,     0,     0,     0,    79,    78,    77,     0,
      76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -56,   144,   119,   137,     7,   -56,   -56,   134,
     -51,   -56,   -56,    87,   -45,   -56,   148,   -56,    88,    51,
     -56,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    16,    17,    56,     8,    32,    33,
      18,    19,    36,    37,    57,   108,    58,    59,    60,    87,
      88,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    27,    75,    76,   101,    86,    69,     7,    -2,     1,
      85,    77,     7,    78,     2,    70,     1,    34,   114,    14,
      22,    10,    23,    15,     2,    28,    42,    63,    31,    35,
      79,     2,   107,   109,     3,    29,   112,   113,     2,    31,
       2,     3,   115,     9,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    66,    11,   130,    95,    96,    97,
      98,    12,    67,    72,   131,    21,    44,    20,    86,    26,
     138,    45,    46,   140,    35,     2,    47,    48,    38,   143,
     144,    24,    25,    49,    50,    41,   142,    84,    24,   103,
     151,    39,   146,    65,   149,   158,    42,   159,   160,    68,
     162,    23,   154,   156,    71,   102,   166,    43,   167,   168,
      44,    74,   165,    80,   170,    45,    46,    81,    82,    83,
      47,    48,   -58,    69,   118,   119,   110,    49,    50,     2,
     111,    43,    51,    52,    44,    53,    54,   133,    55,    45,
      46,    29,   100,   136,    47,    48,    98,   139,   150,    13,
      62,    49,    50,     2,   104,    72,    51,    52,    44,    53,
      54,    40,    55,    45,    46,    29,    64,    30,    47,    48,
     141,   116,     0,     0,    72,    49,    50,    44,     0,   137,
       0,     0,    45,    46,     0,     0,     0,    47,    48,     0,
       0,     0,     0,     0,    49,    50,     0,    89,   148,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    89,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    89,
     117,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   147,    72,     0,     0,    44,     0,     0,     0,     0,
      45,    46,   157,     0,     0,    47,    48,   106,    72,     0,
       0,    44,    49,    50,     0,     0,    45,    46,     0,     0,
       0,    47,    48,   145,    72,     0,     0,    44,    49,    50,
       0,     0,    45,    46,     0,     0,     0,    47,    48,   153,
      72,     0,     0,    44,    49,    50,     0,     0,    45,    46,
       0,     0,     0,    47,    48,   155,    72,     0,     0,    44,
      49,    50,     0,     0,    45,    46,     0,     0,     0,    47,
      48,   164,    72,     0,     0,    44,    49,    50,     0,     0,
      45,    46,     0,     0,     0,    47,    48,     0,     0,     0,
       0,     0,    49,    50,    89,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,     0,     0,    89,   132,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      89,   105,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    89,   134,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,    89,   135,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    89,   152,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    89,   161,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      89,   163,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    89,   169,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    92,    93,    94,    95,    96,    97,    98,
      93,    94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      45,     1,    47,    48,    59,    56,    16,     0,     0,     1,
      55,    15,     5,    17,    23,    25,     1,    16,     1,    21,
      15,    10,    17,    25,    23,    25,    36,    36,    21,    22,
      34,    23,    77,    78,    26,    35,    81,    82,    23,    32,
      23,    26,    25,    25,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    16,    21,    16,    10,    11,    12,
      13,     0,    24,     1,    24,    35,     4,    25,   119,     3,
     115,     9,    10,   118,    67,    23,    14,    15,    22,   134,
     135,    24,    25,    21,    22,    22,   131,    25,    24,    25,
     145,    21,   137,    21,   139,   150,    36,   152,   153,    18,
     155,    17,   147,   148,    21,    25,   161,     1,   163,   164,
       4,    21,   157,    21,   169,     9,    10,    15,    15,    15,
      14,    15,    25,    16,     3,    24,    21,    21,    22,    23,
      21,     1,    26,    27,     4,    29,    30,    25,    32,     9,
      10,    35,    36,    25,    14,    15,    13,    25,    28,     5,
      31,    21,    22,    23,    67,     1,    26,    27,     4,    29,
      30,    24,    32,     9,    10,    35,    32,    19,    14,    15,
     119,    83,    -1,    -1,     1,    21,    22,     4,    -1,    25,
      -1,    -1,     9,    10,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,     3,    25,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    25,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,     3,
      25,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    25,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
       9,    10,    25,    -1,    -1,    14,    15,    16,     1,    -1,
      -1,     4,    21,    22,    -1,    -1,     9,    10,    -1,    -1,
      -1,    14,    15,    16,     1,    -1,    -1,     4,    21,    22,
      -1,    -1,     9,    10,    -1,    -1,    -1,    14,    15,    16,
       1,    -1,    -1,     4,    21,    22,    -1,    -1,     9,    10,
      -1,    -1,    -1,    14,    15,    16,     1,    -1,    -1,     4,
      21,    22,    -1,    -1,     9,    10,    -1,    -1,    -1,    14,
      15,    16,     1,    -1,    -1,     4,    21,    22,    -1,    -1,
       9,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    21,    22,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,     3,    18,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       3,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     3,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     3,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,     3,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,     3,    16,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       3,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     3,    16,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     7,     8,     9,    10,    11,    12,    13,
       8,     9,    10,    11,    12,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    23,    26,    38,    39,    40,    43,    44,    25,
      10,    21,     0,    40,    21,    25,    41,    42,    47,    48,
      25,    35,    15,    17,    24,    25,     3,     1,    25,    35,
      53,    43,    45,    46,    16,    43,    49,    50,    22,    21,
      42,    22,    36,     1,     4,     9,    10,    14,    15,    21,
      22,    26,    27,    29,    30,    32,    43,    51,    53,    54,
      55,    58,    41,    36,    46,    21,    16,    24,    18,    16,
      25,    21,     1,    51,    21,    51,    51,    15,    17,    34,
      21,    15,    15,    15,    25,    51,    47,    56,    57,     3,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    25,
      36,    58,    25,    25,    50,    16,    16,    51,    52,    51,
      21,    21,    51,    51,     1,    25,    55,    25,     3,    24,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      16,    24,    18,    25,    16,    16,    25,    25,    51,    25,
      51,    56,    51,    58,    58,    16,    51,    25,    25,    51,
      28,    58,    16,    16,    51,    16,    51,    25,    58,    58,
      58,    16,    58,    16,    16,    51,    58,    58,    58,    16,
      58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    45,    45,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     2,
       2,     1,     3,     1,     3,     1,     2,     5,     1,     2,
       3,     1,     4,     4,     3,     3,     1,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     4,     3,     1,     4,     3,     1,     2,     2,
       2,     1,     3,     3,     2,     2,     1,     2,     2,     1,
       3,     1,     3,     2,     2,     4,     1,     3,     2,     5,
       7,     5,     6,     7,     7,     7,     9,     8,     8,     8,
       2
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
#line 56 "grammar.y"
                          {
		root = new RootNode("begin", ASTREE::root);
		root -> addChildNode((yyvsp[0].astree));
	}
#line 1630 "grammar.tab.c"
    break;

  case 3:
#line 63 "grammar.y"
                                       {
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 1638 "grammar.tab.c"
    break;

  case 4:
#line 66 "grammar.y"
                                            {
        if ((yyvsp[-1].astree) == NULL) {
			(yyval.astree) = (yyvsp[0].astree);
        } else {
			if ((yyvsp[0].astree) != NULL) {
				(yyvsp[-1].astree) -> getFinalCousinNode() -> addCousinNode((yyvsp[0].astree));
			}
			(yyval.astree) = (yyvsp[-1].astree);
		}
	}
#line 1653 "grammar.tab.c"
    break;

  case 5:
#line 87 "grammar.y"
                                                                 {
		ASTREE:: RootNode* statement = new ASTREE::StatementNode(ASTREE::definition);
		ASTREE::DefineVarNode* variable = (ASTREE::DefineVarNode*)(yyvsp[-1].astree);
		variable -> setAllSymbolType((yyvsp[-2].str));
		statement -> addChildNode(variable);
		(yyval.astree) = statement; 
	}
#line 1665 "grammar.tab.c"
    break;

  case 6:
#line 94 "grammar.y"
                                    {}
#line 1671 "grammar.tab.c"
    break;

  case 7:
#line 95 "grammar.y"
                                                                       {
		ASTREE::DefineFunctionNode* func = (ASTREE::DefineFunctionNode*) (yyvsp[-1].astree);
		func -> addChildNode((yyvsp[0].astree));
		func -> setReturnSymbolType((yyvsp[-2].str));
		(yyval.astree) = func;
	}
#line 1682 "grammar.tab.c"
    break;

  case 8:
#line 101 "grammar.y"
                                                        {
		ASTREE::DefineFunctionNode* func = (ASTREE::DefineFunctionNode*) (yyvsp[-1].astree);
		func -> setReturnSymbolType((yyvsp[-2].str));
		(yyval.astree) = func;
	}
#line 1692 "grammar.tab.c"
    break;

  case 9:
#line 106 "grammar.y"
                                {
		(yyval.astree) = (yyvsp[-1].astree);
	}
#line 1700 "grammar.tab.c"
    break;

  case 10:
#line 109 "grammar.y"
                    { yyerrok; (yyval.astree) = NULL; }
#line 1706 "grammar.tab.c"
    break;

  case 11:
#line 113 "grammar.y"
                                  {
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 1714 "grammar.tab.c"
    break;

  case 12:
#line 116 "grammar.y"
                                               {
		(yyvsp[-2].astree) -> getFinalCousinNode() -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = (yyvsp[-2].astree);
	}
#line 1723 "grammar.tab.c"
    break;

  case 13:
#line 127 "grammar.y"
                                     {
      (yyval.astree) = (yyvsp[0].astree);
    }
#line 1731 "grammar.tab.c"
    break;

  case 14:
#line 130 "grammar.y"
                                  {
        ASTREE::RootNode* operator = new ASTREE::OperatorNode("=", ASTREE::assign);
        ASTREE::RootNode* t = new ASTREE::LiteralNode((yyvsp[0].str));
        operator -> addChildNode((yyvsp[-2].astree))
        (yyvsp[-2].astree) -> addCousinNode(t);
        (yyval.astree) = operator;
    }
#line 1743 "grammar.tab.c"
    break;

  case 15:
#line 156 "grammar.y"
                            {
		(yyval.str) = strdup(yytext);
	}
#line 1751 "grammar.tab.c"
    break;

  case 16:
#line 159 "grammar.y"
                   {
		(yyval.str) = strdup(strcat(yytext, " pointer");
	}
#line 1759 "grammar.tab.c"
    break;

  case 17:
#line 164 "grammar.y"
                                                       {
		if(struct_table == NULL) {
			struct_table = new SMB:StructTable();
		}
		SMB::StructSymbol* current_struct = new SMB::StructSymbol((yyvsp[-3].str), (yyvsp[-1].astree));
		struct_table -> addStruct(current_struct);
		(yyval.astree) = NULL;
    }
#line 1772 "grammar.tab.c"
    break;

  case 18:
#line 179 "grammar.y"
                                    {
        (yyval.astree) = (yyvsp[0].astree);
    }
#line 1780 "grammar.tab.c"
    break;

  case 19:
#line 182 "grammar.y"
                                         {
        (yyvsp[-1].astree) -> getFinalCousinNode() -> addCousinNode((yyvsp[0].astree));
        (yyval.astree) = (yyvsp[-1].astree);
    }
#line 1789 "grammar.tab.c"
    break;

  case 20:
#line 199 "grammar.y"
                                                             {
	ASTREE::RootNode* statement = new ASTREE::StatementNode(ASTREE::definition);
	ASTREE::DefineVarNode* variable = (ASTREE::DefineVarNode*)(yyvsp[-1].astree);
	variable -> setAllSymbolType((yyvsp[-2].str));
	statement -> addChildNode(variable);
	(yyval.astree) = statement;
}
#line 1801 "grammar.tab.c"
    break;

  case 21:
#line 208 "grammar.y"
                        {
		(yyval.astree) = new ASTREE::DefineVarNode((yyvsp[0].str));
    }
#line 1809 "grammar.tab.c"
    break;

  case 22:
#line 211 "grammar.y"
                     {
        ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode((yyvsp[-3].str));
        var -> setALLSymbolType("array");
        var -> setArrayLength((yyvsp[-1].str));
        (yyval.astree) = var; 
    }
#line 1820 "grammar.tab.c"
    break;

  case 23:
#line 220 "grammar.y"
                                               {
		(yyval.astree) = new ASTREE::DefineFunctionNode((yyvsp[-3].str), (yyvsp[-1].astree));
    }
#line 1828 "grammar.tab.c"
    break;

  case 24:
#line 223 "grammar.y"
                 {
		(yyval.astree) = new ASTREE::DefineFunctionNode((yyvsp[-2].str));
    }
#line 1836 "grammar.tab.c"
    break;

  case 25:
#line 229 "grammar.y"
                                                         {
		(yyvsp[-2].astree) -> getFinalCousinNode() -> addCousinNode((yyvsp[0].astree));
        (yyval.astree)  =(yyvsp[-2].astree);
    }
#line 1845 "grammar.tab.c"
    break;

  case 26:
#line 233 "grammar.y"
                            {
		(yyval.astree) = (yyvsp[0].astree);
    }
#line 1853 "grammar.tab.c"
    break;

  case 27:
#line 239 "grammar.y"
                                                {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode((yyvsp[0].str));
		var -> setAllSymbolType((yyvsp[-1].str));
		(yyval.astree) = var;
	}
#line 1863 "grammar.tab.c"
    break;

  case 28:
#line 244 "grammar.y"
                                {
		ASTREE::DefineVarNode* var = new ASTREE::DefineVarNode("");
		var -> setAllSymbolType((yyvsp[0].str));
	    (yyval.astree) = var;
	}
#line 1873 "grammar.tab.c"
    break;

  case 29:
#line 253 "grammar.y"
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
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = assignOpNode;
	}
#line 1892 "grammar.tab.c"
    break;

  case 30:
#line 267 "grammar.y"
                                    {										/* 与运算 */
		RootNode* andOpNode = new ASTREE::OperatorNode("&&", ASTREE:and_op);
		andOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = andOpNode;
	}
#line 1903 "grammar.tab.c"
    break;

  case 31:
#line 273 "grammar.y"
                                   {
		RootNode* orOpNode = new ASTREE::OperatorNode("||", ASTREE::or_op);
		orOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = temp;
	}
#line 1914 "grammar.tab.c"
    break;

  case 32:
#line 279 "grammar.y"
                                      {										/* 比较运算 */
		RootNode* relopNode = new ASTREE::OperatorNode((yyvsp[-1].astree), ASTREE::relop);
		relopNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = relopNode;
	}
#line 1925 "grammar.tab.c"
    break;

  case 33:
#line 285 "grammar.y"
                                    {										/* 加运算 */
		RootNode* addOpNode = new ASTREE::OperatorNode("+", ASTREE::add);
		addOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = addOpNode;
	}
#line 1936 "grammar.tab.c"
    break;

  case 34:
#line 291 "grammar.y"
                                    {										/* 减运算 */
		RootNode* minusOpNode = new ASTREE::OperatorNode("-", ASTREE::minus);
		minusOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = minusOpNode;
	}
#line 1947 "grammar.tab.c"
    break;

  case 35:
#line 297 "grammar.y"
                                    {										/* 乘运算 */
		RootNode* multiOpNode = new ASTREE::OperatorNode("*", ASTREE::multi);
		multiOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = multiOpNode;
	}
#line 1958 "grammar.tab.c"
    break;

  case 36:
#line 303 "grammar.y"
                                    {										/* 除运算 */
		RootNode* divOpNode = new ASTREE::OperatorNode("/", ASTREE::div);
		divOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = divOpNode;
	}
#line 1969 "grammar.tab.c"
    break;

  case 37:
#line 309 "grammar.y"
                                    {										/* 取模运算 */
		RootNode* modOpNode = new ASTREE::OperatorNode("%", ASTREE::mod);
		modOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = modOpNode;
	}
#line 1980 "grammar.tab.c"
    break;

  case 38:
#line 315 "grammar.y"
                                    {										/* 幂运算 */
		RootNode* powOpNode = new ASTREE::OperatorNode("^", ASTREE::pow);
		powOpNode -> addChildNode((yyvsp[-2].astree));
		(yyvsp[-2].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = powOpNode;
	}
#line 1991 "grammar.tab.c"
    break;

  case 39:
#line 321 "grammar.y"
                         {													/* 非运算（单目） */
		RootNode* notOpNode = new ASTREE::OperatorNode("!", ASTREE::not_op);
		notOpNode -> addChildNode((yyvsp[-1].astree));
		(yyvsp[-1].astree) -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = notOpNode;
	}
#line 2002 "grammar.tab.c"
    break;

  case 40:
#line 327 "grammar.y"
                             {												/**/
		(yyval.astree) = (yyvsp[-1].astree);
	}
#line 2010 "grammar.tab.c"
    break;

  case 41:
#line 330 "grammar.y"
                         {													/* 负值 */
		RootNode* negNode = new ASTREE::OperatorNode("-", ASTREE::negative);
		negNode -> addChildNode((yyvsp[0].astree));
		(yyval.astree) = temp;
	}
#line 2020 "grammar.tab.c"
    break;

  case 42:
#line 335 "grammar.y"
                                              {								/* 调用函数 */
		RootNode* callNode = new ASTREE::CallFuncNode((yyvsp[-3].str));
		callNode -> setVarList((yyvsp[-1].astree));
		(yyval.astree) = temp;
	}
#line 2030 "grammar.tab.c"
    break;

  case 43:
#line 340 "grammar.y"
                     {														/* 调用无参数函数 */
		(yyval.astree) = new ASTREE::CallFuncNode((yyvsp[-2].str));
	}
#line 2038 "grammar.tab.c"
    break;

  case 44:
#line 343 "grammar.y"
             {
		(yyval.astree) = new ASTREE::AssignVarNode((yyvsp[0].str));
	}
#line 2046 "grammar.tab.c"
    break;

  case 45:
#line 346 "grammar.y"
                                {											/* 取数组元素，[]内可为expression */
		RootNode* getVarNode = new ASTREE::OperatorNode("[]", ASTREE::get_arr_var);
		RootNode* temp = new ASTREE::AssignVarNode((yyvsp[-3].str));
		getVarNode -> addChildNode(temp);
		temp -> addCousinNode((yyvsp[-1].astree));
		(yyval.astree) = getVarNode;
	}
#line 2058 "grammar.tab.c"
    break;

  case 46:
#line 353 "grammar.y"
                          {													/* 获取对象成员属性 */
		RootNode* getMemberNode = new ASTREE::OperatorNode(".", ASTREE::get_member);
		ASTREE::AssignVarNode* var1 = new ASTREE::AssignVarNode((yyvsp[-2].str));
		ASTREE::AssignVarNode* var2 = new ASTREE::AssignVarNode((yyvsp[0].str));
		getMemberNode -> addChildNode(var1);
		var1 -> addCousinNode(var2);
		(yyval.astree) = getMemberNode;
	}
#line 2071 "grammar.tab.c"
    break;

  case 47:
#line 361 "grammar.y"
              {																/* 字面量节点 */
		(yyval.astree) = new ASTREE::LiteralNode((yyvsp[0].str));
	}
#line 2079 "grammar.tab.c"
    break;

  case 48:
#line 364 "grammar.y"
                 {															/* 指针取值 */
		RootNode* starNode = new ASTREE::OperatorNode("*", ASTREE::get_var);
		ASTREE::AssignVarNode* var = new ASTREE::AssignVarNode((yyvsp[0].str));
		starNode -> addChildNode(var);
		(yyval.astree) = starNode;
	}
#line 2090 "grammar.tab.c"
    break;

  case 49:
#line 370 "grammar.y"
                 {															/* 取地址 */
		RootNode* getAddressNode = new ASTREE::OperatorNode("&", ASTREE::get_address);
		RootNode* temp = new ASTREE::AssignVarNode((yyvsp[0].str));
		getAddressNode -> addChildNode(temp);
		(yyval.astree) = getAddressNode;
	}
#line 2101 "grammar.tab.c"
    break;

  case 50:
#line 376 "grammar.y"
                    {yyerrok;}
#line 2107 "grammar.tab.c"
    break;

  case 51:
#line 380 "grammar.y"
                                     {										
		(yyval.astree) = (yyvsp[0].astree);
	}
#line 2115 "grammar.tab.c"
    break;

  case 52:
#line 383 "grammar.y"
                                                  {
		(yyvsp[-2].astree) -> getFinalCousionNode() -> addCousinNode((yyvsp[0].astree));
		(yyval.astree) = (yyvsp[-2].astree);
	}
#line 2124 "grammar.tab.c"
    break;

  case 53:
#line 390 "grammar.y"
                                       {
        RootNode* t= new ASTREE::StatementNode(ASTREE::compoundation);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2134 "grammar.tab.c"
    break;

  case 54:
#line 395 "grammar.y"
                { yyerrok; }
#line 2140 "grammar.tab.c"
    break;

  case 55:
#line 398 "grammar.y"
                                 {
        (yyvsp[-1].astree)->getFinalCousinNode()->addCousinNode((yyvsp[0].astree));
    }
#line 2148 "grammar.tab.c"
    break;

  case 56:
#line 401 "grammar.y"
                {
		(yyval.astree) = (yyvsp[0].astree)
	}
#line 2156 "grammar.tab.c"
    break;

  case 57:
#line 407 "grammar.y"
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
#line 2171 "grammar.tab.c"
    break;

  case 58:
#line 417 "grammar.y"
                { yyerrok; }
#line 2177 "grammar.tab.c"
    break;

  case 59:
#line 420 "grammar.y"
                              { (yyval.astree) = (yyvsp[0].astree); }
#line 2183 "grammar.tab.c"
    break;

  case 60:
#line 421 "grammar.y"
                                       {
        (yyvsp[-2].astree)->getFinalCousinNode()->addCousinNode((yyvsp[0].astree));
        (yyval.astree) = (yyvsp[-2].astree);
    }
#line 2192 "grammar.tab.c"
    break;

  case 61:
#line 427 "grammar.y"
                                { (yyval.astree) = (yyvsp[0].astree); }
#line 2198 "grammar.tab.c"
    break;

  case 62:
#line 428 "grammar.y"
                                         {
        (yyval.astree) = new ASTREE::OperatorNode("=", ASTREE::assign);
        (yyval.astree)->addChildNode((yyvsp[-2].astree));
        (yyvsp[-2].astree)->addCousinNode((yyvsp[0].astree));
    }
#line 2208 "grammar.tab.c"
    break;

  case 63:
#line 436 "grammar.y"
                          { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::expression);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2218 "grammar.tab.c"
    break;

  case 64:
#line 441 "grammar.y"
                     { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::definition);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2228 "grammar.tab.c"
    break;

  case 65:
#line 446 "grammar.y"
                       { 
        RootNode* t= new ASTREE::StatementNode(ASTREE::definition);
        RootNode* structDefinitionNode = new ASTREE::DefineVarNode((yyvsp[-1].str), (yyvsp[-2].str));
        t->addChildNode(structDefinitionNode);
        (yyval.astree) = t; }
#line 2238 "grammar.tab.c"
    break;

  case 66:
#line 451 "grammar.y"
                         { (yyval.astree)=(yyvsp[0].astree);}
#line 2244 "grammar.tab.c"
    break;

  case 67:
#line 452 "grammar.y"
                            {
        RootNode* t= new ASTREE::StatementNode(ASTREE::return_stmt);
        t->addChildNode((yyvsp[-1].astree));
        (yyval.astree) = t;
    }
#line 2254 "grammar.tab.c"
    break;

  case 68:
#line 457 "grammar.y"
                 {
        RootNode* t= new ASTREE::StatementNode(ASTREE::return_stmt);
        (yyval.astree) = t;
    }
#line 2263 "grammar.tab.c"
    break;

  case 69:
#line 461 "grammar.y"
                                      {  
        ASTREE::SelectNode* t= new ASTREE::SelectNode(ASTREE::if_stmt);
        t->setBodyNode((yyvsp[0].astree));
        t->setCondNode((yyvsp[-2].astree));
        (yyval.astree) = t;
    }
#line 2274 "grammar.tab.c"
    break;

  case 70:
#line 467 "grammar.y"
                                                                          {
        ASTREE::SelectNode* t= new ASTREE::SelectNode(ASTREE::if_stmt);
        t->setBodyNode((yyvsp[-2].astree));
        t->setCondNode((yyvsp[-4].astree));
        t->setElseNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2286 "grammar.tab.c"
    break;

  case 71:
#line 474 "grammar.y"
                                         {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::while_loop, (yyvsp[-2].astree));
        temp->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2296 "grammar.tab.c"
    break;

  case 72:
#line 479 "grammar.y"
                                   {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, NULL, NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2306 "grammar.tab.c"
    break;

  case 73:
#line 484 "grammar.y"
                                              {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, (yyvsp[-4].astree), NULL);
        temp->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2316 "grammar.tab.c"
    break;

  case 74:
#line 489 "grammar.y"
                                              { 
        RootNode* t = new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-3].astree), NULL, NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2326 "grammar.tab.c"
    break;

  case 75:
#line 494 "grammar.y"
                                              {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, NULL, NULL, (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2336 "grammar.tab.c"
    break;

  case 76:
#line 499 "grammar.y"
                                                                     {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-4].astree), (yyvsp[-6].astree), (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2346 "grammar.tab.c"
    break;

  case 77:
#line 504 "grammar.y"
                                                           {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-3].astree), (yyvsp[-5].astree), NULL);
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2356 "grammar.tab.c"
    break;

  case 78:
#line 509 "grammar.y"
                                                           {
        RootNode* t = new ASTREE::LoopNode("", ASTREE::for_loop, NULL, (yyvsp[-5].astree), (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2366 "grammar.tab.c"
    break;

  case 79:
#line 514 "grammar.y"
                                                          {
        RootNode* t= new ASTREE::LoopNode("", ASTREE::for_loop, (yyvsp[-4].astree), NULL, (yyvsp[-2].astree));
        t->addChildNode((yyvsp[0].astree));
        (yyval.astree) = t;
    }
#line 2376 "grammar.tab.c"
    break;

  case 80:
#line 519 "grammar.y"
                { yyerrok; }
#line 2382 "grammar.tab.c"
    break;


#line 2386 "grammar.tab.c"

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
#line 522 "grammar.y"


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
	
	if(root) delete root;
	return 0;
}
