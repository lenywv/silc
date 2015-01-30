%{
#include<stdio.h>
int yytext(void);
void yyerror(char *);
int sym[26];
%}

%union
{
		int i;
		char c;
		node *nptr;
};

%token <i> INTEGER
%token <c> VARIABLE


%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
/*%nonassoc UMINUS*/
%%

program:
	program statement '\n'	
	|
	;

statement:
	expr	{ printf("%d\n",$1); }
	|
	VARIABLE '=' expr {sym[$1] = $3;}
	;
	
expr: 
	INTEGER		{ $$ = $1; }
	|
	VARIABLE		{ $$ = sym[$1];}
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
	'-' expr %prec UMINUS { $$ = node(UMINUS, 1 , $2); }
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

node* makenode
{
	
}

