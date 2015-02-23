%{
#include <stdio.h>
#include "operators.h"
#include "symbol.h"
int yytext(void);
void yyerror(char *);
int type;
symnode *root;
%}

%union
{
		int i;
		char *name;
		struct treenode *nptr;
};

%token CONSTANT IDENT 
%token INTEGER BOOLEAN DECL ENDDECL
%token IF ELSE PRINT WHILE READ ENDIF WRITE TRUE FALSE DO ENDWHILE

%type <nptr> expr statement statementlist condition CONSTANT
%type <i> RELOP
%type <name> IDENT
%left RELOP
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

program:
	declarations program statement ';'	{ evaluate($3); }
	|
	;
	
declarations:
	DECL	declist ENDDECL 
	;

declist:
	declist declaration ';' 
	|
	declaration ';'
	;

declaration:
	vartype varlist ';'
	;

vartype:
	INTEGER {type=1;}
	|
	BOOLEAN {type=0;}
	;
	
varlist:
	varlist ',' variable
	|
	variable 
	;

variable:
	IDENT {makeSymEntry($1,root,1,type);}
	;
statement:
	expr	{ $$=$1; }
	|
	IDENT '=' expr {$$=make_node(CH_ASSIGN,NULL,$3,NULL,$1,TYPE_VOID,0);}
	|
	IF '(' condition ')' statementlist ENDIF {$$=make_node(CH_IF,$3,$5,NULL,NULL,TYPE_VOID,0);}
	|
	IF '(' condition ')' statementlist ELSE statementlist ENDIF {$$=make_node(CH_IFELSE,$3,$5,$7,NULL,TYPE_VOID,0);}
	|
	WHILE '(' condition ')' DO statementlist ENDWHILE { $$=make_node(CH_WHILE,$3,$6,NULL,NULL,TYPE_VOID,0);}
	;

statementlist:
	statement ';' {$$=$1;}
	|
	statementlist statement ';' {$$=make_node(CH_STMNT,$1,$2,NULL,NULL,TYPE_VOID,0);}
	;
	
condition:
	TRUE			{ $$ = make_node(CH_CONST,NULL,NULL,NULL,NULL,TYPE_BOOL,1);}
	|
	FALSE			{ $$ = make_node(CH_CONST,NULL,NULL,NULL,NULL,TYPE_BOOL,0);}
	|
	expr RELOP expr  { $$ = make_node(CH_RELOP,$1,$3,NULL,NULL,TYPE_BOOL,$2);}
	;
	
expr: 
	CONSTANT		{ $$ = $1; }
	|
	IDENT			{ $$ =make_node(CH_IDENT,NULL,NULL,NULL,$1,TYPE_INT,0);}
	|
	READ '(' ')'	{ $$ = make_node(CH_READ,NULL,NULL,NULL,NULL,TYPE_INT,0); }
	|
	WRITE '(' expr ')' { $$ = make_node(CH_WRITE,$3,NULL,NULL,NULL,TYPE_INT,0); }
	|
	expr '+' expr	{ $$ = make_node(CH_ADD,$1, $3,NULL,NULL,TYPE_INT, 0); }
	|
	expr '-' expr	{ $$ = make_node(CH_SUB,$1, $3,NULL,NULL,TYPE_INT, 0); }
	|
	expr '*' expr	{ $$ = make_node(CH_MUL,$1, $3,NULL,NULL,TYPE_INT, 0); }
	|
	expr '/' expr	{ $$ = make_node(CH_DIV,$1, $3,NULL,NULL,TYPE_INT, 0); }
	|
	'(' expr ')' 	{ $$ = $2; }
	|
	'-' expr %prec UMINUS { $$ = make_node(CH_UMINUS, $2, NULL,NULL,NULL,TYPE_INT,0); }
	;
%%

void yyerror (char *s)
{
	fprintf(stderr,"%s\n",s);
}

int main(void)
{
	root=construct();
	yyparse();
	return 0;
}

int evaluate(node *ptr)
{
	int op=ptr->op,temp;
	char buf[30];
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
		case CH_IDENT:
			return sym[ptr->value];
		case CH_IF:
			if(evaluate(ptr->left)!=0)
				return evaluate(ptr->right);
			return 0;
		case CH_IFELSE:
			if(evaluate(ptr->left)!=0)
				return evaluate(ptr->right);
			else
				return evaluate(ptr->middle);
		
		case CH_STMNT:
			evaluate(ptr->left);
			return evaluate(ptr->right);
		case CH_READ:
			scanf("%d",&temp);
			return temp;	
		case CH_WRITE:
			printf("%d\n",evaluate(ptr->left));	
			return 0;
		case CH_ASSIGN:
			sym[ptr->left->value]=evaluate(ptr->right);
			return 0;
		case CH_RELOP:
			switch(ptr->value)
			{
				case CH_GE:
					if(evaluate(ptr->left)>=evaluate(ptr->right))
						return 1;
					return 0;
				case CH_LE:
					if(evaluate(ptr->left)<=evaluate(ptr->right))
						return 1;
					return 0;
				case CH_EQ:
					if(evaluate(ptr->left)==evaluate(ptr->right))
						return 1;
					return 0;
				case CH_NE:
					if(evaluate(ptr->left)!=evaluate(ptr->right))
						return 1;
					return 0;
				case CH_GT:
					if(evaluate(ptr->left)>evaluate(ptr->right))
						return 1;
					return 0;
				case CH_LT:
					if(evaluate(ptr->left)<evaluate(ptr->right))
						return 1;
					return 0;
				default:
					return 0;
			}
		
		case CH_WHILE:
			while(evaluate(ptr->left)!=0)
			{
				evaluate(ptr->right);
			}
			return 0;
			
		default:
			sprintf(buf,"Syntax error %d",op);			
			yyerror(buf);		
	}
}
