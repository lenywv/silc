%{
#include<stdio.h>
int yytext(void);
void yyerror(char *);
%}

%token INTEGER

%left '+' '-'
%left '*' '/'

%%

program:
	program statement '\n'	
	|
	;

statement:
	expr	{ printf("%d\n",$1); }
	;
	
expr: 
	INTEGER		{ $$ = $1; }
	|
	expr '+' expr	{ $$ = $1 + $3; }
	|
	expr '-' expr	{ $$ = $1 - $3; }
	|
	expr '*' expr	{ $$ = $1 * $3; }
	|
	expr '/' expr	{ $$ = $1 / $3; }
	|
	'(' expr ')' 	{ $$ = $2; }
	|	
	;
%%

void yyerror (char *s)
{
	fprintf(stderr,"%s\n",s);
}

int main(void)
{
	yyparse();
	return 0;
}


