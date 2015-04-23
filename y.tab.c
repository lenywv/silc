/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "silc.y" /* yacc.c:339  */

#include "operators.h"
#include "symbol.h"
#include "types.h"
#include "tree.h"
#include "evaluate.h"
#include "actions.h"

int yytext(void);
void yyerror(char *);
int type;
extern int lineno;
extern Lbind_base;
symnode *root,*Lroot;

#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONSTANT = 258,
    IDENT = 259,
    END = 260,
    MAIN = 261,
    INTEGER = 262,
    BOOLEAN = 263,
    DECL = 264,
    ENDDECL = 265,
    RETURN = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    READ = 270,
    ENDIF = 271,
    WRITE = 272,
    TRUE = 273,
    FALSE = 274,
    DO = 275,
    ENDWHILE = 276,
    LOGOP = 277,
    RELOP = 278,
    UMINUS = 279
  };
#endif
/* Tokens.  */
#define CONSTANT 258
#define IDENT 259
#define END 260
#define MAIN 261
#define INTEGER 262
#define BOOLEAN 263
#define DECL 264
#define ENDDECL 265
#define RETURN 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define READ 270
#define ENDIF 271
#define WRITE 272
#define TRUE 273
#define FALSE 274
#define DO 275
#define ENDWHILE 276
#define LOGOP 277
#define RELOP 278
#define UMINUS 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "silc.y" /* yacc.c:355  */

		int i;
		char *name;
		struct treenode *nptr;
		struct argumentnode *aptr;

#line 177 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 192 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    26,    38,     2,
      31,    32,    27,    24,    33,    25,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    47,    51,    53,    57,    59,    63,    65,
      69,    71,    75,    77,    81,    83,    88,    91,    94,    97,
     100,   102,   106,   108,   112,   113,   117,   119,   123,   126,
     128,   132,   137,   139,   141,   143,   145,   147,   151,   153,
     158,   162,   164,   166,   168,   170,   172,   174,   176,   178,
     180,   182,   184,   186,   188,   190,   192,   194,   198,   200,
     204,   206,   209
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "IDENT", "END", "MAIN",
  "INTEGER", "BOOLEAN", "DECL", "ENDDECL", "RETURN", "IF", "ELSE", "WHILE",
  "READ", "ENDIF", "WRITE", "TRUE", "FALSE", "DO", "ENDWHILE", "LOGOP",
  "RELOP", "'+'", "'-'", "'%'", "'*'", "'/'", "UMINUS", "';'", "'('",
  "')'", "','", "'['", "']'", "'{'", "'}'", "'&'", "'='", "$accept",
  "program", "declarations", "declist", "declaration", "vartype",
  "varlist", "variable", "functiondefs", "function", "functionheader",
  "returnstmt", "mainfunction", "arglist", "arg", "Ldeclarations",
  "Ldecllist", "Ldeclaration", "Lvarlist", "Lvariable", "statement",
  "statementlist", "condition", "expr", "actualarglist",
  "nonemptyactualarglist", "actualarg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    37,    42,    47,   279,
      59,    40,    41,    44,    91,    93,   123,   125,    38,    61
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,    25,    57,   -74,   -74,   -74,    43,   -17,    50,   -74,
      80,   -74,    29,   -74,   -22,    33,   -74,    63,    81,   -74,
      53,   -74,   -74,    25,   110,   119,    90,    96,   121,    11,
     106,   -74,   105,   126,   -74,   137,    25,    25,    14,   -74,
     147,   -74,    25,   -74,   134,   117,   167,   107,   142,   -10,
     143,   144,   145,   148,   108,   -74,   -74,   121,   -74,   -74,
     146,   -74,   -74,   150,   -74,    52,    52,    52,    52,    52,
     -74,    52,   136,   151,    14,   167,   -74,   -74,   -11,   152,
     -74,   -74,    52,    52,   173,    69,   140,   153,   140,   154,
     109,   131,   -74,   -74,     2,   -74,    52,    52,   155,   -74,
     120,   -74,    52,    52,    52,    52,    52,    52,    52,   149,
      14,   162,   -74,   -74,   -74,   140,   157,   158,   -74,    83,
     -74,   -74,    75,    54,    47,    47,   -74,   -74,   -74,    52,
      48,    14,   -74,    52,   -74,   140,    14,   -74,    13,   -74,
     112,   -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    15,     8,     9,     0,     0,     0,     1,
       0,     3,     0,     5,    12,     6,    11,     8,     0,    14,
       0,     2,     4,     0,     0,     0,     0,     0,    25,     0,
       0,    21,     0,    12,    10,     0,     0,     0,     0,    22,
       0,     7,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    20,    25,    17,    31,
      28,    30,    24,     0,    27,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,    26,    41,    42,     0,
      54,    55,     0,     0,     0,     0,    32,     0,    40,     0,
       0,     0,    16,    39,     0,    29,    58,     0,     0,    53,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    18,    19,    62,     0,    59,    61,     0,
      46,    52,    57,    56,    47,    48,    51,    49,    50,     0,
       0,     0,    44,     0,    45,    33,     0,    35,     0,    60,
       0,    37,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   178,     1,   -74,   165,   -74,   -74,
     -74,   -74,   -74,   156,   159,   138,   -74,   160,   -74,   118,
     -54,   -73,   128,   -61,   -74,   -74,    61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    29,    15,    16,    10,    19,
      20,    72,    21,    30,    31,    38,    47,    48,    60,    61,
      53,    54,    87,    88,   116,   117,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      73,    94,     8,     1,    85,    86,    49,     8,    90,    23,
      91,    18,    24,    13,    50,    39,    51,    49,    49,    52,
      96,    99,   100,    97,    65,    50,    50,    51,    51,    66,
      52,    52,     4,     5,   141,   115,   119,   130,    46,   114,
      73,   122,   123,   124,   125,   126,   127,   128,    46,    40,
       4,     5,    49,    11,    14,    77,    78,     9,   138,    22,
      50,   136,    51,   140,   137,    52,    25,    79,   135,    26,
      80,    81,   115,   106,   107,   108,    73,    82,   104,   105,
     106,   107,   108,    83,    73,    27,    73,    17,     5,    28,
      84,   102,   103,   104,   105,   106,   107,   108,   103,   104,
     105,   106,   107,   108,   109,   102,   103,   104,   105,   106,
     107,   108,    49,    32,     4,     5,    49,    62,   134,    71,
      50,    35,    51,    33,    50,    52,    51,    36,   142,    52,
      37,   102,   103,   104,   105,   106,   107,   108,    41,    42,
      43,   112,   102,   103,   104,   105,   106,   107,   108,    58,
      42,    55,   121,   102,   103,   104,   105,   106,   107,   108,
      24,   113,   102,   103,   104,   105,   106,   107,   108,    44,
      57,    59,    64,    92,    67,    68,    69,   101,    70,    75,
      76,    93,   131,    98,    12,   110,   111,   120,   129,   132,
      34,   133,    45,    95,   139,    74,    89,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      54,    74,     1,     9,    65,    66,     4,     6,    69,    31,
      71,    10,    34,    30,    12,     4,    14,     4,     4,    17,
      31,    82,    83,    34,    34,    12,    12,    14,    14,    39,
      17,    17,     7,     8,    21,    96,    97,   110,    37,    37,
      94,   102,   103,   104,   105,   106,   107,   108,    47,    38,
       7,     8,     4,    10,     4,     3,     4,     0,   131,    30,
      12,    13,    14,   136,    16,    17,    33,    15,   129,     6,
      18,    19,   133,    26,    27,    28,   130,    25,    24,    25,
      26,    27,    28,    31,   138,     4,   140,     7,     8,    36,
      38,    22,    23,    24,    25,    26,    27,    28,    23,    24,
      25,    26,    27,    28,    35,    22,    23,    24,    25,    26,
      27,    28,     4,     3,     7,     8,     4,    10,    35,    11,
      12,    31,    14,     4,    12,    17,    14,    31,    16,    17,
       9,    22,    23,    24,    25,    26,    27,    28,    32,    33,
      35,    32,    22,    23,    24,    25,    26,    27,    28,    32,
      33,     4,    32,    22,    23,    24,    25,    26,    27,    28,
      34,    30,    22,    23,    24,    25,    26,    27,    28,    32,
      36,     4,    30,    37,    31,    31,    31,     4,    30,    33,
      30,    30,    20,    31,     6,    32,    32,    32,    39,    32,
      25,    33,    36,    75,   133,    57,    68,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    41,    42,     7,     8,    43,    44,    45,     0,
      48,    10,    44,    30,     4,    46,    47,     7,    45,    49,
      50,    52,    30,    31,    34,    33,     6,     4,    36,    45,
      53,    54,     3,     4,    47,    31,    31,     9,    55,     4,
      38,    32,    33,    35,    32,    53,    45,    56,    57,     4,
      12,    14,    17,    60,    61,     4,    54,    36,    32,     4,
      58,    59,    10,    57,    30,    34,    39,    31,    31,    31,
      30,    11,    51,    60,    55,    33,    30,     3,     4,    15,
      18,    19,    25,    31,    38,    63,    63,    62,    63,    62,
      63,    63,    37,    30,    61,    59,    31,    34,    31,    63,
      63,     4,    22,    23,    24,    25,    26,    27,    28,    35,
      32,    32,    32,    30,    37,    63,    64,    65,    66,    63,
      32,    32,    63,    63,    63,    63,    63,    63,    63,    39,
      61,    20,    32,    33,    35,    63,    13,    16,    61,    66,
      61,    21,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    49,    50,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    58,
      58,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     2,     2,     5,     1,     1,
       3,     1,     1,     4,     2,     0,     6,     5,     3,     8,
       3,     1,     2,     3,     3,     0,     3,     2,     2,     3,
       1,     1,     3,     6,     4,     6,     8,     7,     2,     3,
       1,     1,     1,     2,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     3,     3,     0,     1,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 41 "silc.y" /* yacc.c:1646  */
    { execute((yyvsp[0].nptr));}
#line 1375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "silc.y" /* yacc.c:1646  */
    {makeSymEntry((yyvsp[-3].name),root,0,type,(yyvsp[-1].aptr));}
#line 1381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "silc.y" /* yacc.c:1646  */
    {type=TYPE_INT;}
#line 1387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "silc.y" /* yacc.c:1646  */
    {type=TYPE_BOOL;}
#line 1393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 75 "silc.y" /* yacc.c:1646  */
    {makeSymEntry((yyvsp[0].name),root,1,type,NULL);}
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 77 "silc.y" /* yacc.c:1646  */
    {if((yyvsp[-1].nptr)->value>0) makeSymEntry((yyvsp[-3].name),root,(yyvsp[-1].nptr)->value,type,NULL); else arraydeclerror();}
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 81 "silc.y" /* yacc.c:1646  */
    {Ldestruct(Lroot);}
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 83 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=NULL;}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 88 "silc.y" /* yacc.c:1646  */
    {return_type_check((yyvsp[-5].name),(yyvsp[-1].nptr));(yyval.nptr)=node_func((yyvsp[-5].name),(yyvsp[-2].nptr),(yyvsp[-1].nptr));execute((yyval.nptr));}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 91 "silc.y" /* yacc.c:1646  */
    {silc_on_func_header(type,(yyvsp[-3].name),(yyvsp[-1].aptr)); (yyval.name)=(yyvsp[-3].name);}
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 94 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=node_mainfunc((yyvsp[-1].nptr));}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 100 "silc.y" /* yacc.c:1646  */
    { linkArgs((yyvsp[-2].aptr),(yyvsp[0].aptr));}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "silc.y" /* yacc.c:1646  */
    { (yyval.aptr)=makeArgNode(type,(yyvsp[0].name),0);}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 108 "silc.y" /* yacc.c:1646  */
    { (yyval.aptr)=makeArgNode(type,(yyvsp[0].name),1);}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 132 "silc.y" /* yacc.c:1646  */
    {makeLSymEntry((yyvsp[0].name),Lroot,type,0); }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 137 "silc.y" /* yacc.c:1646  */
    {if(isType((yyvsp[0].nptr),getVarType((yyvsp[-2].name),Lroot)))			(yyval.nptr)=node_assign((yyvsp[0].nptr),(yyvsp[-2].name));}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "silc.y" /* yacc.c:1646  */
    {if(isType((yyvsp[0].nptr),getVarType((yyvsp[-5].name),Lroot))&&isInt((yyvsp[-3].nptr)))	(yyval.nptr)=node_assignArray((yyvsp[-3].nptr),(yyvsp[0].nptr),(yyvsp[-5].name));}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 141 "silc.y" /* yacc.c:1646  */
    {if(isInt((yyvsp[-1].nptr)))						(yyval.nptr)=node_write((yyvsp[-1].nptr));}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 143 "silc.y" /* yacc.c:1646  */
    {	(yyval.nptr)=node_if((yyvsp[-3].nptr),(yyvsp[-1].nptr));}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "silc.y" /* yacc.c:1646  */
    {	(yyval.nptr)=node_ifElse((yyvsp[-5].nptr),(yyvsp[-3].nptr),(yyvsp[-1].nptr));}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 147 "silc.y" /* yacc.c:1646  */
    {	(yyval.nptr)=node_while((yyvsp[-4].nptr),(yyvsp[-1].nptr));}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 151 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 153 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=node_stmt((yyvsp[-2].nptr),(yyvsp[-1].nptr));}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 158 "silc.y" /* yacc.c:1646  */
    {if(isBool((yyvsp[0].nptr))) (yyval.nptr)=(yyvsp[0].nptr);}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 162 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 164 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = node_var((yyvsp[0].name));}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 166 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = node_addressof((yyvsp[0].name));}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 168 "silc.y" /* yacc.c:1646  */
    {check_func_sign((yyvsp[-3].name),(yyvsp[-1].nptr)); (yyval.nptr)=node_funccall((yyvsp[-3].name),(yyvsp[-1].nptr));}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "silc.y" /* yacc.c:1646  */
    { if(isInt((yyvsp[-1].nptr)))	(yyval.nptr) = node_derefArray((yyvsp[-3].name),(yyvsp[-1].nptr));}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 172 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = node_read(); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 174 "silc.y" /* yacc.c:1646  */
    { typeCheckArith((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_arithmetic(CH_ADD,(yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 176 "silc.y" /* yacc.c:1646  */
    { typeCheckArith((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_arithmetic(CH_SUB,(yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 178 "silc.y" /* yacc.c:1646  */
    { typeCheckArith((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_arithmetic(CH_MUL,(yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 180 "silc.y" /* yacc.c:1646  */
    { typeCheckArith((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_arithmetic(CH_DIV,(yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 182 "silc.y" /* yacc.c:1646  */
    { typeCheckArith((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_arithmetic(CH_MOD,(yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 184 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 186 "silc.y" /* yacc.c:1646  */
    { if(isInt((yyvsp[0].nptr)))	(yyval.nptr) = node_arithmetic(CH_UMINUS, (yyvsp[0].nptr),NULL);}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 188 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = node_const(TYPE_BOOL,1);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 190 "silc.y" /* yacc.c:1646  */
    { (yyval.nptr) = node_const(TYPE_BOOL,1);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 192 "silc.y" /* yacc.c:1646  */
    { typeCheckRelop((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_relOp((yyvsp[-2].nptr),(yyvsp[0].nptr),(yyvsp[-1].i));	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 194 "silc.y" /* yacc.c:1646  */
    { typeCheckLogop((yyvsp[-2].nptr),(yyvsp[0].nptr));	(yyval.nptr) = node_logOp((yyvsp[-2].nptr),(yyvsp[0].nptr),(yyvsp[-1].i));	}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=NULL;}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 200 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 204 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=node_actualarglist((yyvsp[0].nptr),(yyvsp[-2].nptr));}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 206 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 209 "silc.y" /* yacc.c:1646  */
    {(yyval.nptr)=node_actualarg((yyvsp[0].nptr));}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1655 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
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
                  yystos[*yyssp], yyvsp);
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
#line 211 "silc.y" /* yacc.c:1906  */


void yyerror (char *s)
{
	fprintf(stderr,"%s at line no %d \n",s,lineno);
}

int main(void)
{
	root=construct();
	Lroot=Lconstruct();
	initialiseCodeGen();
	yyparse();
	completeCodeGen();
	return 0;
}

int execute(node* nptr)
{
	codegen(nptr);
	return 0;
}


