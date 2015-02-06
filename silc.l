%{
#include <stdlib.h>
#include "y.tab.h"
#include "operators.h"
%}

%%
	/* integers */
[0-9]+	{ yylval.nptr = make_node(CH_CONST,NULL,NULL,NULL,atoi(yytext));	return INTEGER; }

	/* variables */
[a-z]		{ yylval.nptr = make_node(CH_IDENT,NULL,NULL,NULL,*yytext - 'a');	return VARIABLE; }


	/* operators */
[-()=+*/;]	{ return *yytext;}

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
"write" return WRITE;

	/* others */
.	yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}



