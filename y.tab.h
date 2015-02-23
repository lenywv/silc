/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CONSTANT = 258,
    IDENT = 259,
    INTEGER = 260,
    BOOLEAN = 261,
    DECL = 262,
    ENDDECL = 263,
    IF = 264,
    ELSE = 265,
    PRINT = 266,
    WHILE = 267,
    READ = 268,
    ENDIF = 269,
    WRITE = 270,
    TRUE = 271,
    FALSE = 272,
    DO = 273,
    ENDWHILE = 274,
    RELOP = 275,
    UMINUS = 276
  };
#endif
/* Tokens.  */
#define CONSTANT 258
#define IDENT 259
#define INTEGER 260
#define BOOLEAN 261
#define DECL 262
#define ENDDECL 263
#define IF 264
#define ELSE 265
#define PRINT 266
#define WHILE 267
#define READ 268
#define ENDIF 269
#define WRITE 270
#define TRUE 271
#define FALSE 272
#define DO 273
#define ENDWHILE 274
#define RELOP 275
#define UMINUS 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "silc.y" /* yacc.c:1909  */

		int i;
		char *name;
		struct treenode *nptr;

#line 102 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
