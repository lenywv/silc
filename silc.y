%{
#include <stdio.h>
#include "operators.h"
int yytext(void);
void yyerror(char *);
int sym[26];
typedef struct treenode
{
	int op;
	struct treenode *left,*right;
	int value;
}node;
node* make_node(int op,node *left,node *right,int value);
%}

%union
{
		int i;
//		char c;
		struct treenode *nptr;
};

%token <i> INTEGER
%token <i> VARIABLE
%token IF ELSE PRINT WHILE READ

%type <nptr> expr
%left RELOP
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

program:
	program statement '\n'	
	|
	;

statement:
	expr	{ printf("%d\n",evaluate($1)); }
	|
	VARIABLE '=' expr {sym[$1] = evaluate($3);}
	;
	
condition:
	expr RELOP expr { $$ = make_node(CH_RELOP,$1,$3,$2);
	;
expr: 
	INTEGER		{ $$ =make_node(CH_CONST,NULL,NULL,$1);}
	|
	VARIABLE	{ $$ = make_node(CH_CONST,NULL,NULL,sym[$1]);}
	|
	expr '+' expr	{ $$ = make_node(CH_ADD,$1, $3, 0); }
	|
	expr '-' expr	{ $$ = make_node(CH_SUB,$1, $3, 0); }
	|
	expr '*' expr	{ $$ = make_node(CH_MUL,$1, $3, 0); }
	|
	expr '/' expr	{ $$ = make_node(CH_DIV,$1, $3, 0); }
	|
	'(' expr ')' 	{ $$ = $2; }
	|
	'-' expr %prec UMINUS { $$ = make_node(CH_UMINUS, $2, NULL,0); }
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

node* make_node(int op,node *left,node *right,int value)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->op=op;
	ptr->left=left;
	ptr->right=right;
	ptr->value=value;
	return ptr;
}

int evaluate(node *ptr)
{
	int op=ptr->op;
	
	switch(op)
	{
		case CH_CONST:
			return ptr->value;
		case CH_ADD:
			return evaluate(ptr->left)+evaluate(ptr->right);
		case CH_SUB:
			return evaluate(ptr->left)-evaluate(ptr->right);
		case CH_MUL:
			return evaluate(ptr->left)*evaluate(ptr->right);
		case CH_DIV:
			return evaluate(ptr->left)/evaluate(ptr->right);
		case CH_UMINUS:
			return -evaluate(ptr->left);
		default:
			yyerror("Syntax error");		
	}
}
