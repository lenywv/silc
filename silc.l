%{
#include <stdlib.h>
#include "y.tab.h"
#include "operators.h"
%}

%%
	/* whitespace */
[ \t\n]	;


">="	{	yylval.i=CH_GE;	return RELOP; }
"<="	{	yylval.i=CH_LE;	return RELOP; }
"=="	{	yylval.i=CH_EQ;	return RELOP; }
"!="	{	yylval.i=CH_NE;	return RELOP; }
">"	{	yylval.i=CH_GT;	return RELOP; }
"<"	{	yylval.i=CH_LT;	return RELOP; }

"while"	return WHILE;
"do"	return DO;
"endwhile"	return ENDWHILE;
"if"	return IF;
"else"	return ELSE;
"endif"	return ENDIF;
"print"	return PRINT;
"read"	return READ;
"write"	return WRITE;
"decl"	return DECL;
"enddecl"	return ENDDECL;
"integer"	return INTEGER;
"boolean"	return BOOLEAN;

	/* integers constant*/
[0-9]+	{ yylval.nptr = make_node(CH_CONST,NULL,NULL,NULL,NULL,TYPE_INT,atoi(yytext));	return CONSTANT; }

	/* variables */
[a-zA-Z][A-Za-z0-9]*	{yylval.name=strdup(yytext);return IDENT; }


	/* operators */
[-()=+*/;]	{ return *yytext;}

	/* others */
.	yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}



