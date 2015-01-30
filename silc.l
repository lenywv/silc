%{
#include <stdlib.h>
#include "y.tab.h"
#include "operators.h"
%}

%%
	/* integers */
[0-9]+ {
		yylval.i = atoi(yytext);
		return INTEGER;
  	}

	/* variables */
[a-z]	{
		yylval.i = *yytext - 'a' ;
		return VARIABLE;
	}

"read"	return READ;

	/* operators */
[-()=+*/\n]	{return *yytext;}

	/* whitespace */
[ \t]	;

">="	{
		yylval.i=CH_GE;
		return RELOP;
	}
"<="	{
		yylval.i=CH_LE;
		return RELOP;
	}
"=="	{
		yylval.i=CH_EQ;
		return RELOP;
	}
"!="	{
		yylval.i=CH_NE;
		return RELOP;
	}
">"	{
		yylval.i=CH_GT;
		return RELOP;
	}
"<"	{
		yylval.i=CH_LT;
		return RELOP;
	}

"while"	return WHILE;
"if"	return IF;
"else"	return ELSE;
"print"	return PRINT;

	/* others */
.	yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}



