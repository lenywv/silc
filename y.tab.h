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
    END = 260,
    INTEGER = 261,
    BOOLEAN = 262,
    DECL = 263,
    ENDDECL = 264,
    IF = 265,
    ELSE = 266,
    PRINT = 267,
    WHILE = 268,
    READ = 269,
    ENDIF = 270,
    WRITE = 271,
    TRUE = 272,
    FALSE = 273,
    DO = 274,
    ENDWHILE = 275,
    RELOP = 276,
    LOGOP = 277,
    UMINUS = 278
  };
#endif
/* Tokens.  */
#define CONSTANT 258
#define IDENT 259
#define END 260
#define INTEGER 261
#define BOOLEAN 262
#define DECL 263
#define ENDDECL 264
#define IF 265
#define ELSE 266
#define PRINT 267
#define WHILE 268
#define READ 269
#define ENDIF 270
#define WRITE 271
#define TRUE 272
#define FALSE 273
#define DO 274
#define ENDWHILE 275
#define RELOP 276
#define LOGOP 277
#define UMINUS 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "silc.y" /* yacc.c:1909  */

		int i;
		char *name;
		struct treenode *nptr;

#line 106 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
