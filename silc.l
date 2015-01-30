%{
#include <stdlib.h>
#include "y.tab.h"
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

	/* operators */
[-()<>=+*/\n]	{return *yytext;}

	/* whitespace */
[ \t]	;

">="	return GE;
"<+"	return LE;
"=="	return EQ;
"!="	return NE;
"while"	return WHILE;
"if"		return IF;
"else"	return ELSE;
"print"	return PRINT;

	/* others */
.	yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}



