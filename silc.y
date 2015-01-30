%{
#include<stdio.h>
int yytext(void);
void yyerror(char *);
int sym[26];
typedef struct treenode
{
	char op;
	struct treenode *left,*right;
	int value;
}node;
node* make_node(char op,node *left,node *right,int value);
%}

%union
{
		int i;
		char c;
		struct treenode *nptr;
};

%token <i> INTEGER
%token <c> VARIABLE
%token IF ELSE PRINT WHILE

%type <nptr> expr
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
	expr	{ printf("%d\n",evaluate($1)); }
	|
	VARIABLE '=' expr {sym[$1] = evaluate($3);}
	;
	
expr: 
	INTEGER		{ $$ =make_node(' ',NULL,NULL,$1);}
	|
	VARIABLE	{ $$ = make_node(' ',NULL,NULL,sym[$1]);}
	|
	expr '+' expr	{ $$ = make_node('+',$1, $3, 0); }
	|
	expr '-' expr	{ $$ = make_node('-',$1, $3, 0); }
	|
	expr '*' expr	{ $$ = make_node('*',$1, $3, 0); }
	|
	expr '/' expr	{ $$ = make_node('/',$1, $3, 0); }
	|
	'(' expr ')' 	{ $$ = $2; }
/*	|
	'-' expr %prec UMINUS { $$ = makenode(UMINUS, 1 , $2); }*/
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

node* make_node(char op,node *left,node *right,int value)
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
	char op=ptr->op;
	
	switch(op)
	{
		case ' ':
			return ptr->value;
		case '+':
			return evaluate(ptr->left)+evaluate(ptr->right);
		case '-':
			return evaluate(ptr->left)-evaluate(ptr->right);
		case '*':
			return evaluate(ptr->left)*evaluate(ptr->right);
		case '/':
			return evaluate(ptr->left)/evaluate(ptr->right);
		
	}
}
