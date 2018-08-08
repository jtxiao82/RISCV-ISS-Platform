/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 16 "archc_grammar.y" /* yacc.c:339  */

/*! \file archc_parser.c
 * \brief ArchC parser
 *
 * This file contains the generated bison grammar rules for
 * the ArchC language.
*/

/*! \defgroup bison_group Bison generated parser
 * \ingroup acpp_group
 *
 * The ArchC parser is generated using the GNU tools Bison and Flex.
 * The ArchC grammar for the parser and regular expressions for
 * the lexical analyser are stored into archc_grammar.y and
 * archc_lex.l files, respectively.
 *
 * @{
*/
#include <stdarg.h>
#include <stdlib.h>
#include "ac_tools_common.h"
#include "core_actions.h"
#include "asm_actions.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE
#define ADD_DEBUG 1

/*!type used to identify which unit is being used for storage devices */
enum _sto_unit {BYTE = 1, KBYTE = 1024, MBYTE = 1048576, GBYTE = 1073741824};
typedef enum _sto_unit sto_unit;

/*!type used to identify the kind of list being declared */
enum _commalist {INSTR_L, STAGE_L, REG_L, PIPE_L, REGBANK_L, CACHE_L, MEM_L, TLM_PORT_L, TLM2_PORT_L, TLM2_NB_PORT_L, TLM_INTR_PORT_L, TLM2_INTR_PORT_L, INSTR_REF_L};
typedef enum _commalist commalist;

/*!type used to identify which description is being parsed */
enum _descr {ISA_D, ARCH_D};
typedef enum _descr description;

/* buffer variables */

static char* current_type;             //!< The name of the insn type/format associated to the object currently being parsed.
static ac_dec_instr* current_instr;    //!< Pointer to the current instruction
static ac_dec_format* current_format;  //!< Pointer to the current format
static ac_grp_list* current_group;     //!< Pointer to the current group
static sto_unit current_unit;          //!< Indicates what storage unit is being used.
static ac_pipe_list* current_pipe;     //!< Pointer to the current pipelinel;
static ac_pipe_list* anonymous_pipe = NULL;
static ac_sto_types cache_type;        //!< Indicates the type of cache being declared.

static commalist list_type;            //!< Indicates what type of list of declarations is being parsed.
static char error_msg[500];
static int is_in_old_setasm_mode;

static description descrp;             //!< Indicates what type of description is being parsed.

static int parse_error = 0;            //!< Indicates parse error occurred.

/* global */
char* project_name;                   //!< Name of the ArchC project being processed.
char* upper_project_name;             //!< Name of the ArchC project being processed, converted to uppercase.
char* isa_filename;                   //!< Name for the isa class file.
char* helper_contents;                //!< Contents of the ac_helper declaration.
int wordsize;                         //!< Size of the word type in bits for the current project.
int fetchsize;                        //!< Size of the fetch word type in bits for the current project.
int fetchbuffersize;                  //!< Size of the fetch buffer in bytes for the current project.
int ac_tgt_endian;                    //!< Indicate the endianness of the target architecture.
int force_setasm_syntax;              //!< tools should set this flag if the new set_asm syntax is required

/* lexer interface variable */
int line_num;                         //!< Input file line counter.

/*! Error reporting function
 * \param[in] format A string to be used as error message.
 */
static void yyerror(const char* format, ...)
{
 va_list args;
 va_start(args, format);
 parse_error++;
 fprintf(stderr, "ArchC ERROR: Line %d: ", line_num);
 vfprintf(stderr, format, args);
 fprintf (stderr, ".\n");
 va_end(args);
}

/*! Warning reporting function
 * \param[in] format A string to be used as warning message.
 */
static void yywarn(const char* format, ...)
{
 va_list args;
 va_start(args, format);
 fprintf(stderr, "ArchC WARNING: Line %d: ", line_num);
 vfprintf(stderr, format, args);
 fprintf(stderr, ".\n");
 va_end(args);
}

/*@}*/


#line 170 "archc_grammar.c" /* yacc.c:339  */

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
#ifndef YY_YY_ARCHC_GRAMMAR_H_INCLUDED
# define YY_YY_ARCHC_GRAMMAR_H_INCLUDED
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
    INT = 258,
    STR = 259,
    BLOCK = 260,
    DOT = 261,
    COMMA = 262,
    SEMICOLON = 263,
    COLON = 264,
    PLUS = 265,
    LT = 266,
    GT = 267,
    EQ = 268,
    RPAREN = 269,
    LPAREN = 270,
    LBRACK = 271,
    RBRACK = 272,
    LBRACE = 273,
    RBRACE = 274,
    PP = 275,
    SET_DECODER = 276,
    SET_ASM = 277,
    SET_CYCLES = 278,
    ID = 279,
    AC_ISA_UPPER = 280,
    ISA_CTOR = 281,
    AC_FORMAT = 282,
    AC_INSTR = 283,
    CYCLE_RANGE = 284,
    IS_JUMP = 285,
    IS_BRANCH = 286,
    COND = 287,
    DELAY = 288,
    DELAY_COND = 289,
    BEHAVIOR = 290,
    AC_ASM_MAP = 291,
    PSEUDO_INSTR = 292,
    AC_ASM_ASSEMBLER = 293,
    MAP_TO = 294,
    AC_ASM_COMMENT = 295,
    AC_ASM_LINE_COMMENT = 296,
    AC_GROUP = 297,
    AC_HELPER = 298,
    AC_ARCH = 299,
    AC_TLM_PORT = 300,
    AC_TLM_INTR_PORT = 301,
    AC_TLM2_PORT = 302,
    AC_TLM2_NB_PORT = 303,
    AC_TLM2_INTR_PORT = 304,
    AC_CACHE = 305,
    AC_ICACHE = 306,
    AC_DCACHE = 307,
    AC_MEM = 308,
    AC_PC = 309,
    AC_REGBANK = 310,
    AC_REG = 311,
    AC_STAGE = 312,
    AC_PIPE = 313,
    ARCH_CTOR = 314,
    AC_ISA = 315,
    AC_WORDSIZE = 316,
    AC_FETCHSIZE = 317,
    SET_ENDIAN = 318,
    BIND_TO = 319
  };
#endif
/* Tokens.  */
#define INT 258
#define STR 259
#define BLOCK 260
#define DOT 261
#define COMMA 262
#define SEMICOLON 263
#define COLON 264
#define PLUS 265
#define LT 266
#define GT 267
#define EQ 268
#define RPAREN 269
#define LPAREN 270
#define LBRACK 271
#define RBRACK 272
#define LBRACE 273
#define RBRACE 274
#define PP 275
#define SET_DECODER 276
#define SET_ASM 277
#define SET_CYCLES 278
#define ID 279
#define AC_ISA_UPPER 280
#define ISA_CTOR 281
#define AC_FORMAT 282
#define AC_INSTR 283
#define CYCLE_RANGE 284
#define IS_JUMP 285
#define IS_BRANCH 286
#define COND 287
#define DELAY 288
#define DELAY_COND 289
#define BEHAVIOR 290
#define AC_ASM_MAP 291
#define PSEUDO_INSTR 292
#define AC_ASM_ASSEMBLER 293
#define MAP_TO 294
#define AC_ASM_COMMENT 295
#define AC_ASM_LINE_COMMENT 296
#define AC_GROUP 297
#define AC_HELPER 298
#define AC_ARCH 299
#define AC_TLM_PORT 300
#define AC_TLM_INTR_PORT 301
#define AC_TLM2_PORT 302
#define AC_TLM2_NB_PORT 303
#define AC_TLM2_INTR_PORT 304
#define AC_CACHE 305
#define AC_ICACHE 306
#define AC_DCACHE 307
#define AC_MEM 308
#define AC_PC 309
#define AC_REGBANK 310
#define AC_REG 311
#define AC_STAGE 312
#define AC_PIPE 313
#define ARCH_CTOR 314
#define AC_ISA 315
#define AC_WORDSIZE 316
#define AC_FETCHSIZE 317
#define SET_ENDIAN 318
#define BIND_TO 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 214 "archc_grammar.y" /* yacc.c:355  */

 char* text;
 int value;

#line 343 "archc_grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ARCHC_GRAMMAR_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 360 "archc_grammar.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  420

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   225,   225,   229,   234,   245,   244,   252,   259,   269,
     276,   277,   280,   306,   307,   311,   310,   331,   332,   336,
     335,   362,   369,   379,   380,   384,   383,   391,   392,   396,
     395,   405,   412,   419,   429,   428,   434,   441,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   461,   460,   521,   520,   528,   527,   535,   534,
     542,   541,   546,   549,   554,   562,   561,   576,   591,   589,
     606,   605,   620,   621,   624,   631,   640,   648,   649,   652,
     660,   673,   683,   696,   711,   721,   735,   734,   764,   772,
     773,   774,   775,   776,   780,   781,   789,   802,   808,   809,
     810,   811,   812,   813,   821,   820,   834,   833,   849,   848,
     863,   862,   880,   879,   894,   893,   909,   908,   914,   913,
     919,   918,   927,   926,   942,   953,   954,   958,   966,   975,
     974,   988,   987,  1011,  1076,  1081,  1090,  1097,  1105,  1111,
    1121,  1120,  1158,  1157,  1184,  1191,  1209,  1212,  1217,  1228,
    1248,  1256,  1255,  1319
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STR", "BLOCK", "\".\"", "\",\"",
  "\";\"", "\":\"", "\"+\"", "\"<\"", "\">\"", "\"=\"", "\")\"", "\"(\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "PP", "SET_DECODER", "SET_ASM",
  "SET_CYCLES", "ID", "AC_ISA_UPPER", "ISA_CTOR", "AC_FORMAT", "AC_INSTR",
  "CYCLE_RANGE", "IS_JUMP", "IS_BRANCH", "COND", "DELAY", "DELAY_COND",
  "BEHAVIOR", "AC_ASM_MAP", "PSEUDO_INSTR", "AC_ASM_ASSEMBLER", "MAP_TO",
  "AC_ASM_COMMENT", "AC_ASM_LINE_COMMENT", "AC_GROUP", "AC_HELPER",
  "AC_ARCH", "AC_TLM_PORT", "AC_TLM_INTR_PORT", "AC_TLM2_PORT",
  "AC_TLM2_NB_PORT", "AC_TLM2_INTR_PORT", "AC_CACHE", "AC_ICACHE",
  "AC_DCACHE", "AC_MEM", "AC_PC", "AC_REGBANK", "AC_REG", "AC_STAGE",
  "AC_PIPE", "ARCH_CTOR", "AC_ISA", "AC_WORDSIZE", "AC_FETCHSIZE",
  "SET_ENDIAN", "BIND_TO", "$accept", "input", "isadec", "$@1",
  "isadecbody", "helperdec", "formatdeclist", "formatdec", "groupdeclist",
  "groupdec", "$@2", "instrdeclist", "instrdec", "$@3", "asmcomdec",
  "asmlcomdec", "asmmaplist", "asmmapdec", "$@4", "mapbodylist", "mapbody",
  "$@5", "symbollist", "$@6", "ctordec", "ctordecbody", "asmdec", "$@7",
  "id_list", "$@8", "$@9", "$@10", "$@11", "concatfields_list",
  "decoderdec", "$@12", "cyclesdec", "rangedec", "$@13", "pseudodec",
  "$@14", "pseudobodylist", "pseudobody", "interval", "fieldinitlist",
  "fieldinit", "is_jumpdec", "is_branchdec", "conddec", "delaydec",
  "delayconddec", "behaviordec", "archdec", "$@15", "archdecbody",
  "declist", "unit", "storagedec", "memdec", "$@16", "portdec", "$@17",
  "$@18", "$@19", "intrportdec", "$@20", "$@21", "cachedec", "$@22",
  "$@23", "$@24", "cacheobjdec", "$@25", "cacheobjdec1", "cachenparm",
  "cachesparm", "regbankdec", "$@26", "regdec", "$@27", "storagelist",
  "assignregparm", "assignwidth", "stagedec", "$@28", "pipedec", "$@29",
  "worddec", "fetchdec", "archctordec", "archctordecbody", "commalist",
  "$@30", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -377

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-377)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    22,    37,    53,  -377,  -377,    30,    35,  -377,    49,
      50,    48,    51,  -377,  -377,    24,    52,    68,    57,  -377,
      54,    56,    61,    62,    63,    65,  -377,  -377,  -377,    66,
      84,    95,    87,    88,    74,   114,    52,   110,    71,    52,
    -377,  -377,  -377,  -377,  -377,  -377,    52,    52,    52,    52,
     123,   124,   106,   121,   126,  -377,   127,   128,  -377,   115,
     115,   115,   129,   137,   117,     9,   118,  -377,   130,   136,
     138,  -377,   139,   133,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,   122,   141,   146,   144,   149,   150,   144,
       8,  -377,  -377,  -377,   151,   143,   147,   145,   148,  -377,
     152,   140,  -377,  -377,  -377,   142,   153,   119,  -377,   154,
     155,   156,   157,   155,   155,   159,   160,   164,   155,  -377,
     166,  -377,  -377,   152,   158,   162,   161,   163,   165,   167,
    -377,    -6,  -377,  -377,  -377,   169,  -377,  -377,  -377,  -377,
     155,  -377,   168,  -377,  -377,   173,  -377,  -377,  -377,   170,
     171,   172,   177,   174,  -377,  -377,   144,   181,   144,   144,
    -377,   183,   144,   144,  -377,   152,   152,   -17,   175,   176,
     178,  -377,   179,  -377,   185,   186,   144,  -377,   188,   189,
     193,  -377,   184,   190,   191,   192,   194,  -377,  -377,   195,
     187,  -377,  -377,  -377,   196,   183,  -377,  -377,   200,   107,
     206,   207,   204,   152,   152,   197,    12,  -377,   209,  -377,
     199,   203,   205,  -377,   210,   201,     3,   208,   218,    20,
    -377,   164,   198,   215,   217,  -377,   219,     0,   211,   222,
       3,     3,   212,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,   226,   223,   213,  -377,  -377,   225,
     220,   -17,   -17,  -377,    27,   230,   232,   -22,  -377,  -377,
     229,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,   221,   234,   227,   236,   164,   235,  -377,  -377,
     231,   233,   237,   238,   239,   240,   242,   244,   245,   243,
     228,   241,   246,  -377,   251,  -377,   252,   247,    58,   -17,
     248,   253,   255,   256,   254,   257,   258,   259,   260,  -377,
    -377,   265,   266,   261,   223,   263,   269,   164,   267,  -377,
    -377,   250,  -377,   262,  -377,  -377,  -377,  -377,  -377,  -377,
     264,   270,   271,    34,  -377,  -377,   268,   272,  -377,   274,
     273,   275,   280,   284,   281,   282,   278,   276,   277,   286,
    -377,   279,   283,  -377,   292,   285,   288,    10,  -377,  -377,
    -377,   289,   295,   297,  -377,   294,   291,   296,   299,  -377,
     300,  -377,  -377,  -377,   306,   290,   293,   287,   298,     7,
     301,   273,  -377,  -377,   302,   311,   312,   303,   294,   309,
    -377,  -377,   313,  -377,  -377,   315,   304,   307,   317,  -377,
    -377,   273,   273,   134,   310,   318,   320,  -377,  -377,  -377,
     308,   321,  -377,  -377,   326,  -377,   319,  -377,   273,  -377
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     3,     4,     0,     0,     1,     0,
       0,     0,     0,     5,    86,     9,    95,     0,     0,    11,
       0,     0,     0,     0,     0,     0,   116,   118,   120,     0,
     139,   137,     0,     0,     0,     0,    95,     0,     0,    95,
      99,   102,   103,    98,   100,   101,    95,    95,    95,    95,
       0,     0,    18,     0,     0,   112,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
       0,    90,     0,     0,    88,    89,    91,    94,    92,    93,
       8,     6,    10,    14,     0,     0,   134,     0,     0,   134,
       0,   117,   119,   121,     0,     0,     0,     0,     0,   131,
     153,     0,   144,   145,    87,     0,     0,    24,    17,     0,
      97,     0,     0,    97,    97,     0,     0,     0,    97,   138,
       0,   136,   135,   153,     0,     0,     0,     0,     0,     0,
      13,     0,    12,    96,   106,     0,   113,   108,   110,   115,
      97,   128,     0,   104,   129,     0,   151,   141,   142,     0,
       0,     0,     0,     0,    23,     7,   134,     0,   134,   134,
     122,     0,   134,   134,   132,   153,   153,   150,     0,     0,
       0,    25,     0,   133,     0,     0,   134,   127,     0,     0,
       0,   152,     0,     0,     0,     0,     0,    19,    15,     0,
       0,   107,   109,   111,     0,     0,   105,   130,     0,     0,
       0,     0,     0,   153,   153,     0,     0,   123,     0,   143,
       0,     0,     0,   146,     0,     0,    51,    29,     0,     0,
      28,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      51,    51,     0,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,     0,    36,     0,    26,    27,     0,
       0,   150,   150,    16,     0,     0,     0,     0,    49,    50,
       0,    38,    39,    40,    41,    48,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,     0,     0,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    34,     0,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      70,     0,     0,     0,    36,     0,     0,     0,     0,   124,
     149,     0,    52,     0,    68,    80,    81,    83,    84,    85,
       0,     0,     0,     0,    35,    30,     0,     0,   126,     0,
      62,     0,    76,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,    67,     0,     0,     0,     0,    73,    21,
      22,     0,     0,     0,   125,    78,    64,    60,     0,    75,
       0,    74,    71,    72,     0,     0,     0,     0,     0,     0,
       0,    62,    53,    69,     0,     0,     0,     0,    78,     0,
      54,    58,     0,    63,    61,     0,     0,     0,     0,    77,
      66,    62,    62,     0,     0,     0,     0,    79,    55,    59,
       0,     0,    31,    32,     0,    33,     0,    56,    62,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,  -377,  -377,  -377,  -377,  -377,   120,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
     -45,  -377,  -138,  -377,  -377,  -115,  -377,  -377,  -376,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,   -97,  -377,  -114,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,    45,  -105,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,   -39,  -377,  -377,   180,  -221,  -377,  -377,  -377,  -377,
     -88,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -248,  -121,  -377
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    15,    18,    19,    52,    36,   107,   130,
     204,    83,   108,   203,   230,   231,   131,   154,   190,   219,
     220,   245,   274,   314,   155,   232,   233,   340,   352,   401,
     418,   402,   381,   367,   234,   365,   235,   236,   342,   237,
     330,   357,   358,   355,   378,   388,   238,   239,   240,   241,
     242,   243,     5,    16,    37,    38,   134,    39,    40,   162,
      41,   156,   158,   159,    42,    86,    89,    43,    59,    60,
      61,    91,   176,   319,   178,   142,    44,   163,    45,   123,
     112,    66,    64,    46,   100,    47,   166,    48,    49,    74,
     186,   125,   165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     249,   115,   145,   278,   279,   394,   254,   183,   137,   138,
     390,   391,    97,   143,   356,     1,   217,   116,   291,   292,
     152,    92,    93,   117,   217,   408,   409,   227,   218,   372,
     153,   392,   255,    98,     2,   160,   218,     6,   346,   247,
     228,   229,   419,   184,   181,   182,   185,   347,   280,   281,
     282,   320,     7,     8,     9,   298,   283,   284,   285,    10,
     286,   287,   288,    11,    12,   317,    13,    17,   172,    14,
     174,   175,   318,    50,   179,   180,    51,    69,    53,    20,
      54,    71,   214,   215,    75,    55,    56,    57,   194,    58,
      62,    76,    77,    78,    79,    63,   337,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    65,    30,    31,    32,
      33,    67,    68,    34,    35,   258,   259,    70,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,    72,
      73,    80,    81,    20,    84,    85,    87,    88,    94,    90,
      95,    96,    99,   101,   102,   109,   103,   104,   105,   110,
     106,   111,   113,   114,   118,   119,   120,   121,   126,   124,
     122,   129,   132,   140,   128,   136,   127,   139,   141,   144,
     147,   210,    82,   410,   248,   161,   334,   149,   157,   133,
     135,   164,   146,   168,   173,   148,   177,   191,   167,   150,
     169,   151,   170,   192,   193,   195,   199,   196,   171,   187,
     188,   197,   189,   198,   207,   206,   200,   201,   209,   205,
     211,   212,   213,   202,   222,   216,   221,   223,   225,   224,
     226,   246,   250,   251,   244,   252,   256,   253,   257,   272,
     273,   260,   276,   275,   277,   289,   290,   293,   295,   297,
     296,   294,   310,   299,   304,   305,   300,   306,   301,   307,
     308,   309,   302,   303,   313,   315,   311,   322,   323,   324,
     373,   312,   325,   339,   316,   326,   327,   328,   329,   331,
     332,   335,   321,   336,   399,   338,   341,   350,   333,     0,
     351,   348,   343,   353,   344,   345,   349,   354,   356,   359,
     360,   361,   362,   363,   364,   369,   371,   368,   375,   370,
     376,   377,     0,   366,   379,   374,   380,   382,   383,   384,
     385,   387,   389,   386,   396,   397,   398,   400,   404,   403,
     407,   405,   395,   414,   406,   393,   412,   411,   413,   415,
     416,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208
};

static const yytype_int16 yycheck[] =
{
     221,    89,   123,   251,   252,   381,     6,    24,   113,   114,
       3,     4,     3,   118,     4,    25,     4,     9,    40,    41,
      26,    60,    61,    15,     4,   401,   402,    24,    16,    19,
      36,    24,    32,    24,    44,   140,    16,    15,     4,    19,
      37,    38,   418,    60,   165,   166,    63,    13,    21,    22,
      23,   299,    15,     0,    24,   276,    29,    30,    31,    24,
      33,    34,    35,    14,    14,     7,    18,    43,   156,    18,
     158,   159,    14,     5,   162,   163,    19,     3,    24,    27,
      24,    36,   203,   204,    39,    24,    24,    24,   176,    24,
      24,    46,    47,    48,    49,    11,   317,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    11,    55,    56,    57,
      58,    24,    24,    61,    62,   230,   231,     3,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    19,
      59,     8,     8,    27,    13,     9,     9,     9,     9,    24,
       3,    24,    24,    13,     8,     4,     8,     8,    15,     3,
      28,     7,     3,     3,     3,    12,     9,    12,    18,     7,
      12,    42,     8,     3,    11,     8,    24,     8,     4,     3,
       8,    64,    52,    39,   219,     7,   314,    14,     9,    24,
      24,     8,    24,    12,     3,    24,     3,     8,    18,    24,
      18,    24,    15,     8,     8,     7,     6,     8,    24,    24,
      24,     8,    24,    19,     8,    18,    15,    15,     8,    14,
       4,     4,     8,    19,    15,    18,     7,    14,     8,    14,
      19,     3,    24,     8,    16,     8,    15,     8,     6,     3,
       7,    19,     7,    20,    14,     5,     4,     8,     4,     3,
      13,    20,    14,     8,     5,     5,    15,     5,    15,     5,
       5,     8,    15,    15,     3,     3,    15,     4,     3,     3,
     357,    15,     8,    13,    17,     8,     8,     8,     8,     4,
       4,     8,    24,     4,   388,     8,    14,     3,    17,    -1,
       7,    13,    18,     8,    14,    14,    14,     7,     4,     8,
       8,    13,    16,    16,     8,     3,     8,    14,     3,    14,
       3,     7,    -1,    24,    13,    16,    10,     8,     8,     3,
      20,    24,    14,    20,     3,     3,    13,     8,     3,     6,
       3,    17,    20,    15,    17,    24,     8,    17,     8,     8,
       4,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    44,    66,    67,   117,    15,    15,     0,    24,
      24,    14,    14,    18,    18,    68,   118,    43,    69,    70,
      27,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      55,    56,    57,    58,    61,    62,    72,   119,   120,   122,
     123,   125,   129,   132,   141,   143,   148,   150,   152,   153,
       5,    19,    71,    24,    24,    24,    24,    24,    24,   133,
     134,   135,    24,    11,   147,    11,   146,    24,    24,     3,
       3,   120,    19,    59,   154,   120,   120,   120,   120,   120,
       8,     8,    72,    76,    13,     9,   130,     9,     9,   131,
      24,   136,   136,   136,     9,     3,    24,     3,    24,    24,
     149,    13,     8,     8,     8,    15,    28,    73,    77,     4,
       3,     7,   145,     3,     3,   145,     9,    15,     3,    12,
       9,    12,    12,   144,     7,   156,    18,    24,    11,    42,
      74,    81,     8,    24,   121,    24,     8,   121,   121,     8,
       3,     4,   140,   121,     3,   156,    24,     8,    24,    14,
      24,    24,    26,    36,    82,    89,   126,     9,   127,   128,
     121,     7,   124,   142,     8,   157,   151,    18,    12,    18,
      15,    24,   145,     3,   145,   145,   137,     3,   139,   145,
     145,   156,   156,    24,    60,    63,   155,    24,    24,    24,
      83,     8,     8,     8,   145,     7,     8,     8,    19,     6,
      15,    15,    19,    78,    75,    14,    18,     8,   139,     8,
      64,     4,     4,     8,   156,   156,    18,     4,    16,    84,
      85,     7,    15,    14,    14,     8,    19,    24,    37,    38,
      79,    80,    90,    91,    99,   101,   102,   104,   111,   112,
     113,   114,   115,   116,    16,    86,     3,    19,    85,   140,
      24,     8,     8,     8,     6,    32,    15,     6,    90,    90,
      19,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,     3,     7,    87,    20,     7,    14,   155,   155,
      21,    22,    23,    29,    30,    31,    33,    34,    35,     5,
       4,    40,    41,     8,    20,     4,    13,     3,   140,     8,
      15,    15,    15,    15,     5,     5,     5,     5,     5,     8,
      14,    15,    15,     3,    88,     3,    17,     7,    14,   138,
     155,    24,     4,     3,     3,     8,     8,     8,     8,     8,
     105,     4,     4,    17,    87,     8,     4,   140,     8,    13,
      92,    14,   103,    18,    14,    14,     4,    13,    13,    14,
       3,     7,    93,     8,     7,   108,     4,   106,   107,     8,
       8,    13,    16,    16,     8,   100,    24,    98,    14,     3,
      14,     8,    19,   107,    16,     3,     3,     7,   109,    13,
      10,    97,     8,     8,     3,    20,    20,    24,   110,    14,
       3,     4,    24,    24,    93,    20,     3,     3,    13,   109,
       8,    94,    96,     6,     3,    17,    17,     3,    93,    93,
      39,    17,     8,     8,    15,     8,     4,    14,    95,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    68,    67,    69,    70,    70,
      71,    71,    72,    73,    73,    75,    74,    76,    76,    78,
      77,    79,    80,    81,    81,    83,    82,    84,    84,    86,
      85,    85,    85,    85,    88,    87,    87,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    92,    91,    94,    93,    95,    93,    96,    93,
      97,    93,    93,    98,    98,   100,    99,   101,   103,   102,
     105,   104,   106,   106,   107,   108,   108,   109,   109,   110,
     111,   112,   113,   114,   115,   116,   118,   117,   119,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   124,   123,   126,   125,   127,   125,
     128,   125,   130,   129,   131,   129,   133,   132,   134,   132,
     135,   132,   137,   136,   136,   138,   138,   139,   140,   142,
     141,   144,   143,   145,   145,   146,   146,   146,   147,   147,
     149,   148,   151,   150,   152,   153,   154,   155,   155,   155,
     155,   157,   156,   156
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     0,     9,     6,     3,     0,
       2,     0,     5,     2,     0,     0,     8,     2,     0,     0,
       8,     7,     7,     2,     0,     0,     6,     2,     1,     0,
       6,    13,    13,    14,     0,     4,     0,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     0,     9,     0,     6,     0,    11,     0,     6,
       0,     4,     0,     3,     1,     0,    11,     7,     0,     9,
       0,     8,     2,     1,     2,     2,     0,     3,     0,     3,
       5,     5,     4,     5,     5,     5,     0,     9,     2,     2,
       2,     2,     2,     2,     2,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     0,     8,     0,     8,     0,     8,
       0,     8,     0,     5,     0,     5,     0,     3,     0,     3,
       0,     3,     0,     7,    12,     4,     2,     1,     1,     0,
       8,     0,     6,     4,     0,     3,     3,     0,     3,     0,
       0,     5,     0,     9,     3,     3,     8,     6,     6,     8,
       0,     0,     4,     0
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
#line 225 "archc_grammar.y" /* yacc.c:1646  */
    {
       yyerror("No valid declaration provided");
       YYERROR;
      }
#line 1726 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 230 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (parse_error)
        YYERROR;
      }
#line 1735 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 235 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (parse_error)
        YYERROR;
      }
#line 1744 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 245 "archc_grammar.y" /* yacc.c:1646  */
    {
       descrp = ISA_D;
      }
#line 1752 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 248 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1758 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 8:
#line 260 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (helper_contents)
        yywarn("Multiple ac_helper declarations. Ignored");
       else
       {
        helper_contents = (yyvsp[-1].text);/*(char*) malloc(sizeof(char) * (1 + strlen($2)));*/
        /*strcpy(helper_contents, $2);*/
       }
      }
#line 1772 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 269 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1778 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 277 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1784 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 281 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (descrp == ISA_D)
       {
        if (!add_format(&format_ins_list, &format_ins_list_tail, (yyvsp[-3].text), (yyvsp[-1].text), error_msg, 1))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-3].text), INSTR_FMT, (void*) format_ins_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-3].text));
        format_num++;
       }
       else if (descrp == ARCH_D)
       {
        if (!add_format(&format_reg_list, &format_reg_list_tail, (yyvsp[-3].text), (yyvsp[-1].text), error_msg, 0))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-3].text), REG_FMT, (void*) format_reg_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-3].text));
       }
       else
        yyerror("Internal Bug. Invalid description type. It should be ISA_D or ARCH_D");
      }
#line 1808 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 307 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1814 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 311 "archc_grammar.y" /* yacc.c:1646  */
    {
       int retval;

       current_group = add_group((yyvsp[-2].text));
       if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) group_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-2].text));
       retval = add_instr_ref((yyvsp[0].text), &current_group->instrs, error_msg);
       if (!retval)
        yyerror(error_msg);
       else if (retval == 2)
        yywarn(error_msg);
       list_type = INSTR_REF_L;
      }
#line 1832 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 332 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1838 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 336 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Add to the instruction declaration list. */
       current_type = (char*) malloc(sizeof(char) * (strlen((yyvsp[-2].text)) + 1));
       strcpy(current_type,(yyvsp[-2].text));
       if (find_instr((yyvsp[0].text)))
	 yyerror("Redefinition of %s", (yyvsp[0].text));
       else {
	 if (!add_instr((yyvsp[0].text), current_type, &current_instr, error_msg))
	   yyerror(error_msg);
	 else {
	   if (!add_symbol((yyvsp[0].text), INSTR, (void*) instr_list_tail))
	     yyerror("Internal Bug. find_instr should have caught this");
	 }
       }
       list_type = INSTR_L;
      }
#line 1859 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 353 "archc_grammar.y" /* yacc.c:1646  */
    {
       free(current_type);
      }
#line 1867 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 363 "archc_grammar.y" /* yacc.c:1646  */
    {
	if (!acpp_set_assembler_comment_chars((yyvsp[-2].text), error_msg))
	  yyerror(error_msg);
      }
#line 1876 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 370 "archc_grammar.y" /* yacc.c:1646  */
    {
	if (!acpp_set_assembler_line_comment_chars((yyvsp[-2].text), error_msg))
	  yyerror(error_msg);
      }
#line 1885 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 380 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1891 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 384 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_create_mapping_block((yyvsp[0].text), error_msg))
        yyerror(error_msg);
      }
#line 1900 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 396 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_mapping_symbol((yyvsp[0].text), error_msg))
        yyerror(error_msg);
      }
#line 1909 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 401 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_symbol_value((yyvsp[-1].value), (yyvsp[-1].value), error_msg))
        yyerror(error_msg);
      }
#line 1918 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 406 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_mapping_symbol_range((yyvsp[-12].text), NULL, (yyvsp[-10].value), (yyvsp[-8].value),  error_msg))
        yyerror(error_msg);
       if (!acpp_asm_add_symbol_value((yyvsp[-4].value), (yyvsp[-2].value), error_msg))
        yyerror(error_msg);
      }
#line 1929 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 413 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_mapping_symbol_range(NULL, (yyvsp[-7].text), (yyvsp[-11].value), (yyvsp[-9].value),  error_msg))
        yyerror(error_msg);
       if (!acpp_asm_add_symbol_value((yyvsp[-4].value), (yyvsp[-2].value), error_msg))
        yyerror(error_msg);
      }
#line 1940 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 420 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_mapping_symbol_range((yyvsp[-13].text), (yyvsp[-7].text), (yyvsp[-11].value), (yyvsp[-9].value),  error_msg))
        yyerror(error_msg);
       if (!acpp_asm_add_symbol_value((yyvsp[-4].value), (yyvsp[-2].value), error_msg))
        yyerror(error_msg);
      }
#line 1951 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 429 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_mapping_symbol((yyvsp[0].text), error_msg))
        yyerror(error_msg);
      }
#line 1960 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 434 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1966 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 457 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 1972 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 461 "archc_grammar.y" /* yacc.c:1646  */
    {
       // search for the instruction and store it in 'current_instr' for future use
       current_instr = find_instr((yyvsp[-4].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
       {
        if (current_instr->asm_str == NULL)
        {
         current_instr->asm_str = (char*) malloc(sizeof(char) * (strlen((yyvsp[0].text)) + 1));
         strcpy(current_instr->asm_str, (yyvsp[0].text));
        }
        if (current_instr->mnemonic == NULL)
        {
         char* aux = (yyvsp[0].text);
         while (*aux != ' ' && *aux != '\0')
          aux++;
         current_instr->mnemonic =(char*) malloc(sizeof(char) * (aux - (yyvsp[0].text) + 1));
         memcpy(current_instr->mnemonic, (yyvsp[0].text), aux - (yyvsp[0].text));
         current_instr->mnemonic[aux - (yyvsp[0].text)] = '\0';
        }
        // search for the insn format and store it in 'current_format' for future use
        current_format = find_format(current_instr->format);
        if (current_format == NULL)
         yyerror("Invalid format");
        acpp_asm_new_insn();
        if (!acpp_asm_parse_asm_string((yyvsp[0].text), 0, error_msg))
        {
         if (!force_setasm_syntax)
         {
          if (!is_in_old_setasm_mode)
          {
           yywarn("Entering old set_asm() syntax compatible mode");
           is_in_old_setasm_mode = 1;
          }
         }
         else
          yyerror(error_msg);
        }
       }
      }
#line 2018 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 503 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_end_insn(current_instr, error_msg))
       {
        if (!force_setasm_syntax)
        {
         if (!is_in_old_setasm_mode)
         {
          yywarn("Entering old set_asm() syntax compatible mode");
          is_in_old_setasm_mode = 1;
         }
        }
        else
         yyerror(error_msg);
       }
      }
#line 2038 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 521 "archc_grammar.y" /* yacc.c:1646  */
    {
       force_setasm_syntax = 1;
       if (!acpp_asm_parse_const_asm_argument(current_format, (yyvsp[-2].text), NULL, (yyvsp[0].value), NULL, error_msg))
        yyerror(error_msg);
      }
#line 2048 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 528 "archc_grammar.y" /* yacc.c:1646  */
    {
       force_setasm_syntax = 1;
       if (!acpp_asm_parse_const_asm_argument(current_format, (yyvsp[-7].text), (yyvsp[-5].text), 0, (yyvsp[-1].text), error_msg))
        yyerror(error_msg);
      }
#line 2058 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 535 "archc_grammar.y" /* yacc.c:1646  */
    {
       force_setasm_syntax = 1;
       if (!acpp_asm_parse_const_asm_argument(current_format, (yyvsp[-2].text), NULL, 0, (yyvsp[0].text), error_msg))
        yyerror(error_msg);
      }
#line 2068 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 542 "archc_grammar.y" /* yacc.c:1646  */
    {
       force_setasm_syntax = 1;
      }
#line 2076 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 546 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2082 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 550 "archc_grammar.y" /* yacc.c:1646  */
    {	
        if (!acpp_asm_parse_asm_argument(current_format, (yyvsp[0].text), 1, error_msg))
	  yyerror(error_msg);
      }
#line 2091 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 555 "archc_grammar.y" /* yacc.c:1646  */
    {	
        if (!acpp_asm_parse_asm_argument(current_format, (yyvsp[0].text), 0, error_msg))
	   yyerror(error_msg);
      }
#line 2100 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 562 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Middle rule action to look for the instr. */
       current_instr = find_instr((yyvsp[-6].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-6].text));
       else
       {
        if (!add_dec_list(current_instr, (yyvsp[-2].text), (yyvsp[0].value), error_msg))
         yyerror(error_msg);
       }
      }
#line 2116 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 577 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-6].text));
       if (current_instr == NULL)
        yyerror("undeclared instruction: %s", (yyvsp[-6].text));
       else
       {
        current_instr->cycles = (yyvsp[-2].value);
        HaveMultiCycleIns = 1;
       }
      }
#line 2131 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 591 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-4].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
       {
        current_instr->min_latency = (yyvsp[0].value);
       }
       HaveCycleRange = 1;
      }
#line 2146 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 606 "archc_grammar.y" /* yacc.c:1646  */
    {
       acpp_asm_new_insn();
       if (!acpp_asm_parse_asm_string((yyvsp[-1].text), 0, error_msg))
        yyerror(error_msg);
       // don't change the order
       acpp_asm_new_pseudo();
      }
#line 2158 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 614 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_end_insn(NULL, error_msg))
        yyerror(error_msg);
      }
#line 2167 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 625 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!acpp_asm_add_pseudo_member((yyvsp[-1].text), error_msg))
        yyerror(error_msg);
      }
#line 2176 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 633 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-1].text));
       else
        current_instr->max_latency = (yyvsp[0].value);
      }
#line 2187 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 640 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (current_instr == NULL)
        yyerror("Internal error");
       else
        current_instr->max_latency = current_instr->min_latency;
      }
#line 2198 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 648 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2204 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 649 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2210 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 653 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Adding field to the end of the decoding sequence list */
       if (!add_dec_list(current_instr, (yyvsp[-2].text), (yyvsp[0].value), error_msg))
        yyerror(error_msg);
      }
#line 2220 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 661 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-4].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
       {
        get_control_flow_struct(current_instr)->target = (yyvsp[-1].text);
        get_control_flow_struct(current_instr)->cond = "1";
       }
      }
#line 2235 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 674 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-4].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
        get_control_flow_struct(current_instr)->target = (yyvsp[-1].text);
      }
#line 2247 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 684 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-3].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-3].text));
       else
       {
        get_control_flow_struct(current_instr)->cond = (yyvsp[-1].text);
        ControlInstrInfoLevel = 2;
       }
      }
#line 2262 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 697 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-4].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
       {
        get_control_flow_struct(current_instr)->delay_slot = strtol((yyvsp[-1].text),0,0);
        get_control_flow_struct(current_instr)->delay_slot_cond = "1";
        if (ControlInstrInfoLevel == 0)
         ControlInstrInfoLevel = 1;
       }
      }
#line 2279 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 712 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-4].text));
       if (current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
        get_control_flow_struct(current_instr)->delay_slot_cond = (yyvsp[-1].text);
      }
#line 2291 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 722 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_instr = find_instr((yyvsp[-4].text));
       if(current_instr == NULL)
        yyerror("Undeclared instruction: %s", (yyvsp[-4].text));
       else
        get_control_flow_struct(current_instr)->action = (yyvsp[-1].text);
      }
#line 2303 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 735 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Middle rule action to start emitting ARCH module declaration. */
       project_name = (char*) malloc(sizeof(char) * (strlen((yyvsp[-2].text)) + 1));
       upper_project_name = (char*) malloc(sizeof(char) * (strlen((yyvsp[-2].text)) + 1));
       strcpy(project_name, (yyvsp[-2].text));
       strcpy(upper_project_name, (yyvsp[-2].text));
       str_upper(upper_project_name);
       descrp = ARCH_D;
       helper_contents = NULL;
       /* Initialisation section */
       /* local variables */
       current_type = NULL;
       current_instr = NULL;
       current_format = NULL;
       current_unit = BYTE;
       current_pipe = NULL;
       cache_type = CACHE;
       list_type = MEM_L; /* it does not matter */
       error_msg[0] = '\0';
       is_in_old_setasm_mode = 0;
       parse_error = 0;
       init_core_actions();
      }
#line 2331 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 759 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Closing module declaration. */
      }
#line 2339 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 781 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2345 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 790 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Identifying unit */
       if (!strcmp((yyvsp[0].text), "K") || !strcmp((yyvsp[0].text), "k"))
        current_unit = KBYTE;
       else if (!strcmp((yyvsp[0].text), "M") || !strcmp((yyvsp[0].text), "m"))
        current_unit = MBYTE;
       else if (!strcmp((yyvsp[0].text), "G") || !strcmp((yyvsp[0].text), "g"))
        current_unit = GBYTE;
       else
        yyerror("Invalid storage unit. It should be \"K\", \"M\", \"G\"");
      }
#line 2361 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 802 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_unit = BYTE;
      }
#line 2369 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 821 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including device in storage list. */
       if (!add_storage((yyvsp[-3].text), ((yyvsp[-1].value) * current_unit), (ac_sto_types) MEM, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-3].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-3].text));
       list_type = MEM_L;
      }
#line 2382 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 106:
#line 834 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including port in storage list */
       if (!add_storage((yyvsp[-3].text), ((yyvsp[-1].value) * current_unit), (ac_sto_types) TLM_PORT, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-3].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-3].text));
       list_type = TLM_PORT_L;
       HaveTLMPorts = 1;
      }
#line 2396 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 108:
#line 849 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including port in storage list */
       if (!add_storage((yyvsp[-3].text), ((yyvsp[-1].value) * current_unit), (ac_sto_types) TLM2_PORT, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-3].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-3].text));
       list_type = TLM2_PORT_L;
       HaveTLM2Ports = 1;
      }
#line 2410 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 110:
#line 863 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including port in storage list */
       if (!add_storage((yyvsp[-3].text), ((yyvsp[-1].value) * current_unit), (ac_sto_types) TLM2_NB_PORT, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-3].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-3].text));
       list_type = TLM2_PORT_L;
       HaveTLM2NBPorts = 1;
      }
#line 2424 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 112:
#line 880 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including port in storage list */
       if (!add_storage((yyvsp[0].text), 0, (ac_sto_types) TLM_INTR_PORT, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[0].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[0].text));
       list_type = TLM_INTR_PORT_L;
       HaveTLMIntrPorts = 1;
      }
#line 2438 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 894 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including port in storage list */
       if (!add_storage((yyvsp[0].text), 0, (ac_sto_types) TLM2_INTR_PORT, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[0].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[0].text));
       list_type = TLM2_INTR_PORT_L;
       HaveTLM2IntrPorts = 1;
      }
#line 2452 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 116:
#line 909 "archc_grammar.y" /* yacc.c:1646  */
    {
       cache_type = (ac_sto_types) CACHE;
      }
#line 2460 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 118:
#line 914 "archc_grammar.y" /* yacc.c:1646  */
    {
       cache_type = (ac_sto_types) ICACHE;
      }
#line 2468 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 120:
#line 919 "archc_grammar.y" /* yacc.c:1646  */
    {
       cache_type = (ac_sto_types) DCACHE;
      }
#line 2476 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 122:
#line 927 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including device in storage list. */
       if (!add_storage((yyvsp[-3].text), ((yyvsp[-1].value) * current_unit), cache_type, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-3].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-3].text));
       list_type = CACHE_L;
      }
#line 2489 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 124:
#line 943 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!add_storage((yyvsp[-11].text), 0, cache_type, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-11].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-11].text));
      }
#line 2500 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 127:
#line 959 "archc_grammar.y" /* yacc.c:1646  */
    {
       add_parms(NULL, (yyvsp[0].value));
      }
#line 2508 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 128:
#line 967 "archc_grammar.y" /* yacc.c:1646  */
    {
       add_parms((yyvsp[0].text), 0);
      }
#line 2516 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 129:
#line 975 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including device in storage list. */
       if (!add_storage((yyvsp[-2].text), (yyvsp[0].value), (ac_sto_types) REGBANK, NULL, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[-2].text));
       list_type = REGBANK_L;
      }
#line 2529 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 131:
#line 988 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including device in storage list. */
       if (!add_storage((yyvsp[0].text), 0, (ac_sto_types) REG, current_type, error_msg))
        yyerror(error_msg);
       if (!add_symbol((yyvsp[0].text), GEN_ID, (void*) storage_list_tail))
        yyerror("Redefinition of %s", (yyvsp[0].text));
       list_type = REG_L;
      }
#line 2542 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 132:
#line 997 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (current_type)
        free(current_type);
       current_type = NULL;
      }
#line 2552 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1012 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Including device in storage list. */
       if (list_type == CACHE_L)
       {
        if (!add_storage((yyvsp[-2].text), ((yyvsp[0].value) * current_unit), (ac_sto_types) CACHE, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else if (list_type == REGBANK_L)
       {
        if (!add_storage((yyvsp[-2].text), (yyvsp[0].value), (ac_sto_types) REGBANK, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else if (list_type == MEM_L)
       {
        if (!add_storage((yyvsp[-2].text), ((yyvsp[0].value) * current_unit), (ac_sto_types) MEM, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else if (list_type == TLM_PORT_L)
       {
        if (!add_storage((yyvsp[-2].text), ((yyvsp[0].value) * current_unit), (ac_sto_types) TLM_PORT, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else if (list_type == TLM2_PORT_L)
       {
        if (!add_storage((yyvsp[-2].text), ((yyvsp[0].value) * current_unit), (ac_sto_types) TLM2_PORT, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else if (list_type == TLM2_NB_PORT_L)
       {
        if (!add_storage((yyvsp[-2].text), ((yyvsp[0].value) * current_unit), (ac_sto_types) TLM2_NB_PORT, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else if (list_type == TLM_INTR_PORT_L)
       {
        if (!add_storage((yyvsp[-2].text), (yyvsp[0].value), (ac_sto_types) TLM_INTR_PORT, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
        else if (list_type == TLM2_INTR_PORT_L)
       {
        if (!add_storage((yyvsp[-2].text), (yyvsp[0].value), (ac_sto_types) TLM2_INTR_PORT, NULL, error_msg))
         yyerror(error_msg);
        if (!add_symbol((yyvsp[-2].text), GEN_ID, (void*) storage_list_tail))
         yyerror("Redefinition of %s", (yyvsp[-2].text));
       }
       else
       {
        /* Should never enter here. */
        yyerror("Internal Bug. Invalid list type. It should be CACHE_L, REGBANK_L, MEM_L, TLM_PORT_L, TLM2_INTR_PORT_L or TLM_INTR_PORT_L");
       }
      }
#line 2621 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1076 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2627 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1082 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Assign a format to storage device. */
       /* capturing format name */
       current_type = (char*) malloc(sizeof(char) * (strlen((yyvsp[-1].text)) + 1));
       strcpy(current_type, (yyvsp[-1].text));
       HaveFormattedRegs = 1;
       reg_width = 0;
      }
#line 2640 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1091 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Assign a width to a register, instead of a format. */
       current_type = NULL;
       reg_width = (yyvsp[-1].value);
      }
#line 2650 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1097 "archc_grammar.y" /* yacc.c:1646  */
    {
       current_type = NULL;
       reg_width = 0;
      }
#line 2659 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1106 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Getting register width. */
       reg_width = (yyvsp[-1].value);
      }
#line 2668 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1111 "archc_grammar.y" /* yacc.c:1646  */
    {
       reg_width = 0;
      }
#line 2676 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1121 "archc_grammar.y" /* yacc.c:1646  */
    {
       ac_stg_list* current_stage;
       char* curr_stg_name;

       /* Create an anonymous pipe if it does not already exist. */
       if (!anonymous_pipe)
       {
        anonymous_pipe = add_pipe("");
        current_stage = add_stage((yyvsp[0].text), &anonymous_pipe->stages);
        curr_stg_name = (char*) malloc(sizeof(char) * (2 + strlen((yyvsp[0].text))));
        strcpy(curr_stg_name, "_");
        strcat(curr_stg_name, (yyvsp[0].text));
        if (!add_symbol(curr_stg_name, GEN_ID, (void*) current_stage))
         yyerror("Redefinition of %s", (yyvsp[0].text));
        free(curr_stg_name);
        stage_list = anonymous_pipe->stages;
       }
       else
       {
        current_stage = add_stage((yyvsp[0].text), &anonymous_pipe->stages);
        curr_stg_name = (char*) malloc(sizeof(char) * (2 + strlen((yyvsp[0].text))));
        strcpy(curr_stg_name, "_");
        strcat(curr_stg_name, (yyvsp[0].text));
        if (!add_symbol(curr_stg_name, GEN_ID, (void*) current_stage))
         yyerror("Redefinition of %s", (yyvsp[0].text));
        free(curr_stg_name);
       }
       /* Add to the stage list. */
       list_type = STAGE_L;
      }
#line 2711 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1158 "archc_grammar.y" /* yacc.c:1646  */
    {
       ac_stg_list* current_stage;
       char* curr_stg_name;

       /* Indicating to commalist that this is a pipe declaration */
       list_type = PIPE_L;
       /* Adding to the pipe list */
       current_pipe = add_pipe((yyvsp[-3].text));
       if (!add_symbol((yyvsp[-3].text), GEN_ID, (void*) current_pipe))
        yyerror("Redefinition of %s", (yyvsp[-3].text));
       /* Adding the first stage to the pipe's stage list */
       current_stage = add_stage((yyvsp[0].text), &current_pipe->stages);
       curr_stg_name = (char*) malloc(sizeof(char) * (2 + strlen((yyvsp[-3].text)) + strlen((yyvsp[0].text))));
       strcpy(curr_stg_name, (yyvsp[-3].text));
       strcat(curr_stg_name, "_");
       strcat(curr_stg_name, (yyvsp[0].text));
       if (!add_symbol(curr_stg_name, GEN_ID, (void*) current_stage))
        yyerror("Redefinition of %s inside pipeline %s", (yyvsp[0].text), (yyvsp[-3].text));
       free(curr_stg_name);
      }
#line 2736 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1185 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Declaring wordsize for the architecture */
       wordsize = (yyvsp[-1].value);
      }
#line 2745 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1192 "archc_grammar.y" /* yacc.c:1646  */
    {
       /* Declaring fetchsize for the architecture */
       fetchsize = (yyvsp[-1].value);
      }
#line 2754 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1213 "archc_grammar.y" /* yacc.c:1646  */
    {
       isa_filename = (char*) malloc(sizeof(char) * (strlen((yyvsp[-3].text)) + 1));
       strcpy(isa_filename ,(yyvsp[-3].text));
      }
#line 2763 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1218 "archc_grammar.y" /* yacc.c:1646  */
    {
       if (!strcmp((yyvsp[-3].text), "little") || !strcmp((yyvsp[-3].text), "LITTLE"))
        ac_tgt_endian = 0;
       else if (!strcmp((yyvsp[-3].text), "big") || !strcmp((yyvsp[-3].text), "BIG"))
        ac_tgt_endian = 1;
       else
       {
        yyerror("Invalid endian: \"%s\"", (yyvsp[-3].text));
       }
      }
#line 2778 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1229 "archc_grammar.y" /* yacc.c:1646  */
    {
        ac_sto_list* plow;
        ac_sto_list* pstorage;

        /* Warning acpp that a memory hierarchy was declared */
        HaveMemHier = 1;
        /* Looking for the low level device */
        plow = find_storage((yyvsp[-7].text));
        if (plow == NULL)
         yyerror("Undeclared storage device: %s", (yyvsp[-7].text));
        /* Looking for the high level device */
        pstorage = find_storage((yyvsp[-3].text));
        if (pstorage == NULL)
         yyerror("Undeclared storage device: %s", (yyvsp[-3].text));
        plow->higher = pstorage;
        // Updating hierarchy level, from this level to the top.
        for (pstorage = plow; pstorage->higher != NULL; pstorage = pstorage->higher)
         pstorage->higher->level = pstorage->level + 1;
      }
#line 2802 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1248 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2808 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1256 "archc_grammar.y" /* yacc.c:1646  */
    {
       ac_stg_list* current_stage;
       char* curr_stg_name;
       int retval;

       switch (list_type)
       {
        case INSTR_L:
	 if (find_instr((yyvsp[0].text)))
	  yyerror("Redefinition of %s", (yyvsp[0].text));
	 else {
          if (!add_instr((yyvsp[0].text), current_type, &current_instr, error_msg)) /* Add to instruction list. */
           yyerror(error_msg);
	  else {
           if (!add_symbol((yyvsp[0].text), INSTR, (void*) instr_list_tail))
            yyerror("Internal Bug. find_instr should have caught this");
          }
	 }
	 break;
        case STAGE_L:
         /* This case is reached when a pipe declaration like
            ac_stages ST1, ST2, ST3;
            is used. So, add stage to the anonymous pipe's stage list */
         current_stage = add_stage((yyvsp[0].text), &anonymous_pipe->stages);
         curr_stg_name = (char*) malloc(sizeof(char) * (2 + strlen((yyvsp[0].text))));
         strcpy(curr_stg_name, "_");
         strcat(curr_stg_name, (yyvsp[0].text));
         if (!add_symbol(curr_stg_name, GEN_ID, (void*) current_stage))
          yyerror("Redefinition of %s", (yyvsp[0].text));
         free(curr_stg_name);
         break;
        case REG_L:
         if (!add_storage((yyvsp[0].text), 0, (ac_sto_types) REG, current_type, error_msg)) /* Add to reg list. */
          yyerror(error_msg);
         if (!add_symbol((yyvsp[0].text), GEN_ID, (void*) storage_list_tail))
          yyerror("Redefinition of %s", (yyvsp[0].text));
         break;
        case PIPE_L:
         /* In this case, IDs represent stage names, so
            add stage to the pipe's stage list. */
         current_stage = add_stage((yyvsp[0].text), &current_pipe->stages);
         curr_stg_name = (char*) malloc(sizeof(char) * (2 + strlen(current_pipe->name) + strlen((yyvsp[0].text))));
         strcpy(curr_stg_name, current_pipe->name);
         strcat(curr_stg_name, "_");
         strcat(curr_stg_name, (yyvsp[0].text));
         if (!add_symbol(curr_stg_name, GEN_ID, (void*) current_stage))
          yyerror("Redefinition of %s inside pipeline %s", (yyvsp[0].text), current_pipe->name);
         free(curr_stg_name);
         break;
        case INSTR_REF_L:
         retval = add_instr_ref((yyvsp[0].text), &current_group->instrs, error_msg);
         if (!retval)
          yyerror(error_msg);
         else if (retval == 2)
          yywarn(error_msg);
         break;
        default:
         /* Should never enter here. */
         yyerror("Internal Bug. Unidentified list type");
         break;
       }
      }
#line 2875 "archc_grammar.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1319 "archc_grammar.y" /* yacc.c:1646  */
    {}
#line 2881 "archc_grammar.c" /* yacc.c:1646  */
    break;


#line 2885 "archc_grammar.c" /* yacc.c:1646  */
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
#line 1322 "archc_grammar.y" /* yacc.c:1906  */


/**********************

   File Structure
   ==============
%{
C declarations
%}

Bison declarations

%%
Grammar rules
%%

Additional C code
***********************/
