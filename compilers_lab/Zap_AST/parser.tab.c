/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "ast.h"
#include "SemanticAnalyzer.h"
#include <iostream>
#include <string>

extern int yylex();
extern int yylineno;
void yyerror(const char *s);

Node* root; // Raíz del AST

#line 84 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TRUE_LIT = 3,                   /* TRUE_LIT  */
  YYSYMBOL_FALSE_LIT = 4,                  /* FALSE_LIT  */
  YYSYMBOL_INT_LIT = 5,                    /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 6,                  /* FLOAT_LIT  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_STRING_LIT = 8,                 /* STRING_LIT  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_BOOL = 13,                      /* BOOL  */
  YYSYMBOL_FUNCTION = 14,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MULT = 20,                      /* MULT  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSIF = 24,                     /* ELSIF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_READ = 29,                      /* READ  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_GEQ = 32,                       /* GEQ  */
  YYSYMBOL_LEQ = 33,                       /* LEQ  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_LBRACE = 35,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 36,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 38,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 39,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 40,                    /* RBRACK  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_SEMI = 42,                      /* SEMI  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_mixed_list = 45,                /* mixed_list  */
  YYSYMBOL_mixed_item = 46,                /* mixed_item  */
  YYSYMBOL_function_definition = 47,       /* function_definition  */
  YYSYMBOL_parameter_list = 48,            /* parameter_list  */
  YYSYMBOL_parameter = 49,                 /* parameter  */
  YYSYMBOL_type = 50,                      /* type  */
  YYSYMBOL_statement_list = 51,            /* statement_list  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_assignment = 54,                /* assignment  */
  YYSYMBOL_if_statement = 55,              /* if_statement  */
  YYSYMBOL_elsif_list = 56,                /* elsif_list  */
  YYSYMBOL_for_loop = 57,                  /* for_loop  */
  YYSYMBOL_block = 58,                     /* block  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_argument_list = 60              /* argument_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    56,    60,    67,    68,    72,    80,    81,
      85,    97,   104,   105,   106,   107,   108,   112,   116,   123,
     124,   125,   126,   127,   132,   133,   140,   145,   152,   159,
     165,   177,   178,   193,   205,   206,   210,   211,   212,   213,
     214,   215,   216,   220,   224,   228,   233,   238,   243,   248,
     253,   258,   263,   268,   273,   278,   283,   287,   288,   292
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TRUE_LIT",
  "FALSE_LIT", "INT_LIT", "FLOAT_LIT", "ID", "STRING_LIT", "INT", "FLOAT",
  "STRING", "ARRAY", "BOOL", "FUNCTION", "RETURN", "GT", "LT", "PLUS",
  "MINUS", "MULT", "DIV", "MOD", "IF", "ELSIF", "ELSE", "WHILE", "FOR",
  "PRINT", "READ", "EQ", "NEQ", "GEQ", "LEQ", "ASSIGN", "LBRACE", "RBRACE",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "COMMA", "SEMI", "$accept",
  "program", "mixed_list", "mixed_item", "function_definition",
  "parameter_list", "parameter", "type", "statement_list", "statement",
  "declaration", "assignment", "if_statement", "elsif_list", "for_loop",
  "block", "expression", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -98,   -98,   -98,   -98,   -30,   -98,   -98,   -98,   -98,
     -98,   -98,    -4,    25,   -32,    20,    23,    24,    30,    25,
      21,    76,   -98,   -98,    48,   -98,    26,    28,   -98,   -98,
     168,    25,    25,    37,    38,   175,    25,    25,    59,    25,
      25,   209,   -98,   -98,    44,   -98,   -98,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,   -98,   324,
     324,   -21,     3,   -98,   232,   255,    58,    51,   -16,   278,
     -98,    25,    29,    29,    43,    43,   -98,   -98,   -98,   331,
     331,    29,    29,   -98,    25,    18,   -98,    87,    60,    60,
      25,   -98,   -98,   324,   324,    60,     3,   -98,   111,   -98,
     -98,   202,   -98,   -98,   -98,   146,   -98,   -15,    59,   -98,
     -98,    61,    60,    62,    25,   -98,    60,   301,   -98,    60,
     -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    36,    37,    38,    39,    41,    40,    12,    13,    14,
      16,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     5,     0,     6,     0,     0,    22,    24,
       0,     0,    57,     0,    41,     0,     0,     0,     0,    57,
       0,     0,     1,     4,    27,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    28,
      58,     0,     8,    25,     0,     0,     0,     0,     0,     0,
      56,     0,    54,    55,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    42,     0,     0,     9,     0,     0,     0,
       0,    43,    44,    26,    59,     0,     0,    11,     0,    31,
      23,     0,     7,    10,    35,     0,    17,    29,     0,    34,
      18,     0,     0,     0,     0,    30,     0,     0,    33,     0,
      32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,    75,   -98,   -98,     1,   -51,   -98,   -97,
     -98,   -36,   -98,   -98,   -98,   -43,   -13,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    20,    21,    22,    23,    85,    86,    24,   105,    25,
      26,    27,    28,   107,    29,    99,    30,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,   106,    67,    33,    31,    36,    41,    32,   110,   111,
     112,    87,     7,     8,     9,    10,    11,    83,    59,    60,
      84,    42,    91,    64,    65,    84,    60,    69,     1,     2,
       3,     4,    34,     6,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    87,   100,    49,    50,    51,
      52,    53,   102,    17,    18,    44,    95,    37,    93,    96,
      38,    39,    19,    51,    52,    53,    66,    40,    45,   115,
      46,    94,   113,   118,    62,    32,   120,   101,    71,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    31,    90,    97,    98,    43,   103,   114,    14,
     116,   117,    15,    16,    17,    18,    68,     0,     0,     0,
       0,     0,     0,    19,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    13,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,   104,    19,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    13,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,   109,    19,    47,    48,    49,    50,    51,    52,
      53,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    54,    55,    56,    57,     0,
      58,     0,     0,     0,     0,     0,     0,    63,    47,    48,
      49,    50,    51,    52,    53,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    54,
      55,    56,    57,     0,   108,     0,     0,    70,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,    54,    55,    56,    57,     0,     0,     0,     0,
      88,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,     0,
       0,     0,     0,    89,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,     0,     0,     0,     0,    92,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,    54,    55,    56,    57,     0,     0,     0,     0,   119,
      47,    48,    49,    50,    51,    52,    53,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,    56,    57
};

static const yytype_int8 yycheck[] =
{
      13,    98,    38,     7,    34,    37,    19,    37,   105,    24,
      25,    62,     9,    10,    11,    12,    13,    38,    31,    32,
      41,     0,    38,    36,    37,    41,    39,    40,     3,     4,
       5,     6,     7,     8,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    96,    89,    18,    19,    20,
      21,    22,    95,    28,    29,     7,    38,    37,    71,    41,
      37,    37,    37,    20,    21,    22,     7,    37,    42,   112,
      42,    84,   108,   116,    37,    37,   119,    90,    34,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    34,    42,     7,    35,    21,    96,    37,    23,
      38,   114,    26,    27,    28,    29,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    37,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    16,    17,    18,    19,    20,    21,
      22,    16,    17,    18,    19,    20,    21,    22,    30,    31,
      32,    33,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    42,    16,    17,
      18,    19,    20,    21,    22,    16,    17,    18,    19,    20,
      21,    22,    30,    31,    32,    33,    -1,    -1,    -1,    30,
      31,    32,    33,    -1,    42,    -1,    -1,    38,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      16,    17,    18,    19,    20,    21,    22,    16,    17,    18,
      19,    20,    21,    22,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    23,    26,    27,    28,    29,    37,
      44,    45,    46,    47,    50,    52,    53,    54,    55,    57,
      59,    34,    37,     7,     7,    59,    37,    37,    37,    37,
      37,    59,     0,    46,     7,    42,    42,    16,    17,    18,
      19,    20,    21,    22,    30,    31,    32,    33,    42,    59,
      59,    60,    37,    42,    59,    59,     7,    54,    60,    59,
      38,    34,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    38,    41,    48,    49,    50,    38,    38,
      42,    38,    38,    59,    59,    38,    41,     7,    35,    58,
      58,    59,    58,    49,    36,    51,    52,    56,    42,    36,
      52,    24,    25,    54,    37,    58,    38,    59,    58,    38,
      58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    48,    48,
      48,    49,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     0,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     5,     1,     3,     4,     2,     3,     6,
       8,     0,     6,     9,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: mixed_list  */
#line 51 "parser.y"
               { root = (yyvsp[0].nptr); }
#line 1524 "parser.tab.c"
    break;

  case 3: /* mixed_list: mixed_item  */
#line 56 "parser.y"
               { 
        (yyval.nptr) = new Node("Program"); 
        (yyval.nptr)->add_child((yyvsp[0].nptr)); 
    }
#line 1533 "parser.tab.c"
    break;

  case 4: /* mixed_list: mixed_list mixed_item  */
#line 60 "parser.y"
                            { 
        (yyvsp[-1].nptr)->add_child((yyvsp[0].nptr)); 
        (yyval.nptr) = (yyvsp[-1].nptr); 
    }
#line 1542 "parser.tab.c"
    break;

  case 5: /* mixed_item: function_definition  */
#line 67 "parser.y"
                        { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1548 "parser.tab.c"
    break;

  case 6: /* mixed_item: statement  */
#line 68 "parser.y"
                { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1554 "parser.tab.c"
    break;

  case 7: /* function_definition: FUNCTION ID LPAREN parameter_list RPAREN block  */
#line 72 "parser.y"
                                                   {
        (yyval.nptr) = new Node("Function", "fn " + std::string((yyvsp[-4].sval)), yylineno);
        if ((yyvsp[-2].nptr)) (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1564 "parser.tab.c"
    break;

  case 8: /* parameter_list: %empty  */
#line 80 "parser.y"
           { (yyval.nptr) = nullptr; }
#line 1570 "parser.tab.c"
    break;

  case 9: /* parameter_list: parameter  */
#line 81 "parser.y"
                { 
        (yyval.nptr) = new Node("Parameters");
        (yyval.nptr)->add_child((yyvsp[0].nptr)); 
    }
#line 1579 "parser.tab.c"
    break;

  case 10: /* parameter_list: parameter_list COMMA parameter  */
#line 85 "parser.y"
                                     {
        if ((yyvsp[-2].nptr)) {
            (yyvsp[-2].nptr)->add_child((yyvsp[0].nptr));
            (yyval.nptr) = (yyvsp[-2].nptr);
        } else {
            (yyval.nptr) = new Node("Parameters");
            (yyval.nptr)->add_child((yyvsp[0].nptr));
        }
    }
#line 1593 "parser.tab.c"
    break;

  case 11: /* parameter: type ID  */
#line 97 "parser.y"
            {
        (yyval.nptr) = new Node("Parameter", std::string((yyvsp[0].sval)), yylineno);
        (yyval.nptr)->add_child((yyvsp[-1].nptr));
    }
#line 1602 "parser.tab.c"
    break;

  case 12: /* type: INT  */
#line 104 "parser.y"
        { (yyval.nptr) = new Node("Type", "int"); }
#line 1608 "parser.tab.c"
    break;

  case 13: /* type: FLOAT  */
#line 105 "parser.y"
            { (yyval.nptr) = new Node("Type", "flt"); }
#line 1614 "parser.tab.c"
    break;

  case 14: /* type: STRING  */
#line 106 "parser.y"
              { (yyval.nptr) = new Node("Type", "str"); }
#line 1620 "parser.tab.c"
    break;

  case 15: /* type: BOOL  */
#line 107 "parser.y"
           { (yyval.nptr) = new Node("Type", "bl"); }
#line 1626 "parser.tab.c"
    break;

  case 16: /* type: ARRAY  */
#line 108 "parser.y"
            { (yyval.nptr) = new Node("Type", "arr");}
#line 1632 "parser.tab.c"
    break;

  case 17: /* statement_list: statement  */
#line 112 "parser.y"
              { 
        (yyval.nptr) = new Node("Statement List"); 
        (yyval.nptr)->add_child((yyvsp[0].nptr)); 
    }
#line 1641 "parser.tab.c"
    break;

  case 18: /* statement_list: statement_list statement  */
#line 116 "parser.y"
                               { 
        (yyvsp[-1].nptr)->add_child((yyvsp[0].nptr)); 
        (yyval.nptr) = (yyvsp[-1].nptr); 
    }
#line 1650 "parser.tab.c"
    break;

  case 19: /* statement: declaration SEMI  */
#line 123 "parser.y"
                     { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1656 "parser.tab.c"
    break;

  case 20: /* statement: assignment SEMI  */
#line 124 "parser.y"
                      { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1662 "parser.tab.c"
    break;

  case 21: /* statement: expression SEMI  */
#line 125 "parser.y"
                      { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1668 "parser.tab.c"
    break;

  case 22: /* statement: if_statement  */
#line 126 "parser.y"
                   { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1674 "parser.tab.c"
    break;

  case 23: /* statement: WHILE LPAREN expression RPAREN block  */
#line 127 "parser.y"
                                           {
        (yyval.nptr) = new Node("Loop", "wh", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1684 "parser.tab.c"
    break;

  case 24: /* statement: for_loop  */
#line 132 "parser.y"
               { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1690 "parser.tab.c"
    break;

  case 25: /* statement: RETURN expression SEMI  */
#line 133 "parser.y"
                             {
        (yyval.nptr) = new Node("Return", "rt", yylineno);
        (yyval.nptr)->add_child((yyvsp[-1].nptr));
    }
#line 1699 "parser.tab.c"
    break;

  case 26: /* declaration: type ID ASSIGN expression  */
#line 140 "parser.y"
                              {
        (yyval.nptr) = new Node("Declaration", std::string((yyvsp[-2].sval)), yylineno);
        (yyval.nptr)->add_child((yyvsp[-3].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1709 "parser.tab.c"
    break;

  case 27: /* declaration: type ID  */
#line 145 "parser.y"
              {
        (yyval.nptr) = new Node("Declaration", std::string((yyvsp[0].sval)), yylineno); 
        (yyval.nptr)->add_child((yyvsp[-1].nptr));
    }
#line 1718 "parser.tab.c"
    break;

  case 28: /* assignment: ID ASSIGN expression  */
#line 152 "parser.y"
                         {
        (yyval.nptr) = new Node("Assignment", std::string((yyvsp[-2].sval)), yylineno); 
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1727 "parser.tab.c"
    break;

  case 29: /* if_statement: IF LPAREN expression RPAREN block elsif_list  */
#line 159 "parser.y"
                                                 {
        (yyval.nptr) = new Node("Conditional", "if", (yyvsp[-3].nptr)->linea);
        (yyval.nptr)->add_child((yyvsp[-3].nptr));
        (yyval.nptr)->add_child((yyvsp[-1].nptr));
        if ((yyvsp[0].nptr)) (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1738 "parser.tab.c"
    break;

  case 30: /* if_statement: IF LPAREN expression RPAREN block elsif_list ELSE block  */
#line 165 "parser.y"
                                                              {
        (yyval.nptr) = new Node("Conditional", "if", (yyvsp[-5].nptr)->linea);
        (yyval.nptr)->add_child((yyvsp[-5].nptr));
        (yyval.nptr)->add_child((yyvsp[-3].nptr));
        if ((yyvsp[-2].nptr)) (yyval.nptr)->add_child((yyvsp[-2].nptr));
        Node* else_node = new Node("Else", "el");
        else_node->add_child((yyvsp[0].nptr));
        (yyval.nptr)->add_child(else_node);
    }
#line 1752 "parser.tab.c"
    break;

  case 31: /* elsif_list: %empty  */
#line 177 "parser.y"
           { (yyval.nptr) = nullptr; }
#line 1758 "parser.tab.c"
    break;

  case 32: /* elsif_list: elsif_list ELSIF LPAREN expression RPAREN block  */
#line 178 "parser.y"
                                                      {
        Node* elsif_node = new Node("Else-If", "ei", yylineno);
        elsif_node->add_child((yyvsp[-2].nptr));
        elsif_node->add_child((yyvsp[0].nptr));
        if ((yyvsp[-5].nptr)) {
            (yyvsp[-5].nptr)->add_child(elsif_node);
            (yyval.nptr) = (yyvsp[-5].nptr);
        } else {
            (yyval.nptr) = new Node("Else-If Branches");
            (yyval.nptr)->add_child(elsif_node);
        }
    }
#line 1775 "parser.tab.c"
    break;

  case 33: /* for_loop: FOR LPAREN assignment SEMI expression SEMI assignment RPAREN block  */
#line 193 "parser.y"
                                                                       {
        (yyval.nptr) = new Node("Loop", "for", yylineno);
        Node* header = new Node("FOR Header");
        header->add_child((yyvsp[-6].nptr));
        header->add_child((yyvsp[-4].nptr));
        header->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child(header);
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1789 "parser.tab.c"
    break;

  case 34: /* block: LBRACE statement_list RBRACE  */
#line 205 "parser.y"
                                 { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1795 "parser.tab.c"
    break;

  case 35: /* block: LBRACE RBRACE  */
#line 206 "parser.y"
                    { (yyval.nptr) = new Node("Empty Block"); }
#line 1801 "parser.tab.c"
    break;

  case 36: /* expression: TRUE_LIT  */
#line 210 "parser.y"
             { (yyval.nptr) = new Node("True", std::to_string((yyvsp[0].ival))); }
#line 1807 "parser.tab.c"
    break;

  case 37: /* expression: FALSE_LIT  */
#line 211 "parser.y"
                { (yyval.nptr) = new Node("False", std::to_string((yyvsp[0].ival))); }
#line 1813 "parser.tab.c"
    break;

  case 38: /* expression: INT_LIT  */
#line 212 "parser.y"
               { (yyval.nptr) = new Node("Integer", std::to_string((yyvsp[0].ival))); }
#line 1819 "parser.tab.c"
    break;

  case 39: /* expression: FLOAT_LIT  */
#line 213 "parser.y"
                { (yyval.nptr) = new Node("Float",  std::to_string((yyvsp[0].fval))); }
#line 1825 "parser.tab.c"
    break;

  case 40: /* expression: STRING_LIT  */
#line 214 "parser.y"
                 { (yyval.nptr) = new Node("String", (yyvsp[0].sval)); }
#line 1831 "parser.tab.c"
    break;

  case 41: /* expression: ID  */
#line 215 "parser.y"
         { (yyval.nptr) = new Node("Identifier", (yyvsp[0].sval), yylineno); }
#line 1837 "parser.tab.c"
    break;

  case 42: /* expression: ID LPAREN argument_list RPAREN  */
#line 216 "parser.y"
                                     {
        (yyval.nptr) = new Node("Call", std::string((yyvsp[-3].sval)), yylineno); 
        if ((yyvsp[-1].nptr)) (yyval.nptr)->add_child((yyvsp[-1].nptr));
    }
#line 1846 "parser.tab.c"
    break;

  case 43: /* expression: PRINT LPAREN argument_list RPAREN  */
#line 220 "parser.y"
                                        {
        (yyval.nptr) = new Node("Print", "", yylineno);
        if ((yyvsp[-1].nptr)) (yyval.nptr)->add_child((yyvsp[-1].nptr));
    }
#line 1855 "parser.tab.c"
    break;

  case 44: /* expression: READ LPAREN expression RPAREN  */
#line 224 "parser.y"
                                    {
        (yyval.nptr) = new Node("Read", "", yylineno);
        (yyval.nptr) -> add_child((yyvsp[-1].nptr));
    }
#line 1864 "parser.tab.c"
    break;

  case 45: /* expression: expression PLUS expression  */
#line 228 "parser.y"
                                 {
        (yyval.nptr) = new Node("Operation", "+", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1874 "parser.tab.c"
    break;

  case 46: /* expression: expression MINUS expression  */
#line 233 "parser.y"
                                  {
        (yyval.nptr) = new Node("Operation", "-", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1884 "parser.tab.c"
    break;

  case 47: /* expression: expression MULT expression  */
#line 238 "parser.y"
                                 {
        (yyval.nptr) = new Node("Operation", "*", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1894 "parser.tab.c"
    break;

  case 48: /* expression: expression DIV expression  */
#line 243 "parser.y"
                                {
        (yyval.nptr) = new Node("Operation", "/", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1904 "parser.tab.c"
    break;

  case 49: /* expression: expression MOD expression  */
#line 248 "parser.y"
                                {
        (yyval.nptr) = new Node("Operation", "%", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1914 "parser.tab.c"
    break;

  case 50: /* expression: expression EQ expression  */
#line 253 "parser.y"
                               {
        (yyval.nptr) = new Node("Comparison", "==", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1924 "parser.tab.c"
    break;

  case 51: /* expression: expression NEQ expression  */
#line 258 "parser.y"
                                {
        (yyval.nptr) = new Node("Comparison", "!=", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1934 "parser.tab.c"
    break;

  case 52: /* expression: expression GEQ expression  */
#line 263 "parser.y"
                                {
        (yyval.nptr) = new Node("Comparison", ">=", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1944 "parser.tab.c"
    break;

  case 53: /* expression: expression LEQ expression  */
#line 268 "parser.y"
                                {
        (yyval.nptr) = new Node("Comparison", "<=", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1954 "parser.tab.c"
    break;

  case 54: /* expression: expression GT expression  */
#line 273 "parser.y"
                               {
        (yyval.nptr) = new Node("Comparison", ">", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1964 "parser.tab.c"
    break;

  case 55: /* expression: expression LT expression  */
#line 278 "parser.y"
                               {
        (yyval.nptr) = new Node("Comparison", "<", yylineno);
        (yyval.nptr)->add_child((yyvsp[-2].nptr));
        (yyval.nptr)->add_child((yyvsp[0].nptr));
    }
#line 1974 "parser.tab.c"
    break;

  case 56: /* expression: LPAREN expression RPAREN  */
#line 283 "parser.y"
                               { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1980 "parser.tab.c"
    break;

  case 57: /* argument_list: %empty  */
#line 287 "parser.y"
           { (yyval.nptr) = nullptr; }
#line 1986 "parser.tab.c"
    break;

  case 58: /* argument_list: expression  */
#line 288 "parser.y"
                 { 
        (yyval.nptr) = new Node("Arguments");
        (yyval.nptr)->add_child((yyvsp[0].nptr)); 
    }
#line 1995 "parser.tab.c"
    break;

  case 59: /* argument_list: argument_list COMMA expression  */
#line 292 "parser.y"
                                     {
        if ((yyvsp[-2].nptr)) {
            (yyvsp[-2].nptr)->add_child((yyvsp[0].nptr));
            (yyval.nptr) = (yyvsp[-2].nptr);
        } else {
            (yyval.nptr) = new Node("Arguments");
            (yyval.nptr)->add_child((yyvsp[0].nptr));
        }
    }
#line 2009 "parser.tab.c"
    break;


#line 2013 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

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
                      yytoken, &yylval);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 303 "parser.y"


void yyerror(const char *s) {
    std::string msg(s);
    const std::string prefix = "syntax error, ";
    if (msg.rfind(prefix, 0) == 0)
        msg = msg.substr(prefix.size());

    std::cerr << "\033[1;31mSyntax error:\033[0m "
              << msg
              << " at linea " << yylineno
              << std::endl;
}

int main() {
    std::cout << "--- Iniciando Zap Parser ---" << std::endl;
    if (yyparse() == 0) {
        if (root) {
            std::cout << "\n--- Analisis Sintactico Exitoso. Iniciando Analisis Semnatico... ---" << std::endl;
            
            SemanticAnalyzer analyzer;
            analyzer.analyze(root);
            
            analyzer.print_results();
            
            if (!analyzer.has_errors()) { 
                std::cout << "\n--- Decorado AST: ---" << std::endl;
                root->print();
                root->gen_dot("ast.dot");
            }
        }
    }
    return 0;
}
