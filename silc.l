%{
#include <stdlib.h>
#include "y.tab.h"
%}

%%
	/* integers */
[0-9]+ {
		yylval = atoi(yytext);
		return INTEGER;
  	}

	/* variables */
[a-z]	{
		yylval = *yytext - 'a' ;
		return VARIABLE;
	}

	/* operators */
[()=+\-*/\n]	{return *yytext;}

	/* whitespace */
[ \t]	;

	/* others */
.	yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}



