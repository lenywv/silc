%{
#include <stdlib.h>
#include "y.tab.h"
#include "operators.h"
#include "types.h"
int lineno=1;
%}

%%
	/* whitespace */
[ \t]	;
[\n]	{lineno++;}


">="	{	yylval.i=CH_GE;	return RELOP; }
"<="	{	yylval.i=CH_LE;	return RELOP; }
"=="	{	yylval.i=CH_EQ;	return RELOP; }
"!="	{	yylval.i=CH_NE;	return RELOP; }
">"	{	yylval.i=CH_GT;	return RELOP; }
"<"	{	yylval.i=CH_LT;	return RELOP; }

"&&"	{	yylval.i=CH_LOGAND;	return LOGOP; }
"||"	{	yylval.i=CH_LOGOR;	return LOGOP; }

"while"	return WHILE;
"do"		return DO;
"endwhile"	return ENDWHILE;
"if"		return IF;
"else"	return ELSE;
"endif"	return ENDIF;
"print"	return PRINT;
"read"	return READ;
"write"	return WRITE;
"decl"	return DECL;
"true"	return TRUE;
"false"	return FALSE;
"enddecl"	return ENDDECL;
"integer"	return INTEGER;
"boolean"	return BOOLEAN;
"end"		return END;
	/* integers constant*/
[0-9]+	{ yylval.nptr = node_const(TYPE_INT,atoi(yytext));	return CONSTANT; }

	/* variables */
[a-zA-Z][A-Za-z0-9]*	{yylval.name=strdup(yytext);return IDENT; }


	/* operators */
[-()=+*/;,\[\]]	{ return *yytext;}

	/* others */
.	yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}



