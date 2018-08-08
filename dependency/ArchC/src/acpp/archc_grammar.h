/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 214 "archc_grammar.y" /* yacc.c:1909  */

 char* text;
 int value;

#line 187 "archc_grammar.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ARCHC_GRAMMAR_H_INCLUDED  */
