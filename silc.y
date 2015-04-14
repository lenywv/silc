%{
#include "operators.h"
#include "symbol.h"
#include "types.h"
#include "tree.h"
#include "evaluate.h"

int yytext(void);
void yyerror(char *);
int type;
extern int lineno;
symnode *root;
%}

%union
{
		int i;
		char *name;
		struct treenode *nptr;
//		argnode *aptr;
};

%token CONSTANT IDENT END
%token INTEGER BOOLEAN DECL ENDDECL
%token IF ELSE PRINT WHILE READ ENDIF WRITE TRUE FALSE DO ENDWHILE

%type <nptr> expr statement statementlist CONSTANT condition
//%type <aptr> arg arglist
%type <i> RELOP LOGOP
%type <name> IDENT
%left LOGOP
%left RELOP 
%left '+' '-'
%left '%' '*' '/'
%nonassoc UMINUS
%%

program:
	declarations statementlist  END { execute($2); exit(1);}
	|
	statementlist  END { execute($1); exit(1);}
	|
	;
	
declarations:
	DECL declist ENDDECL 
	;

declist:
	declist declaration ';' 
	|
	declaration ';'
	;
/*
arglist:
	agrlist ',' arg
	|
	arg
	;

arg:
	vartype IDENT { $$=makeArgNode(type,$2)};
	;
*/
declaration:
	vartype varlist
	/*|
	vartype IDENT '(' arglist ')' {makeSymEntry($2,root,0,type,$4);}*/
	;

vartype:
	INTEGER {type=TYPE_INT;}
	|
	BOOLEAN {type=TYPE_BOOL;}
	;
	
varlist:
	varlist ',' variable
	|
	variable 
	;

variable:
	IDENT {makeSymEntry($1,root,1,type);}
	|
	IDENT '[' CONSTANT ']' {if($3->value>0) makeSymEntry($1,root,$3->value,type); else arraydeclerror();}
	;

statement:
	IDENT '=' expr 			{if(isType($3,getVarType($1,root)))			$$=node_assign($3,$1);}
	|
	IDENT '[' expr ']' '=' expr 	{if(isType($6,getVarType($1,root))&&isInt($3))	$$=node_assignArray($3,$6,$1);}
	|
	WRITE '(' expr ')' 		{if(isInt($3))						$$=node_write($3);}
	|
	IF '(' condition ')' statementlist ENDIF 						{	$$=node_if($3,$5);}
	|
	IF '(' condition ')' statementlist ELSE statementlist ENDIF 		{	$$=node_ifElse($3,$5,$7);}
	|
	WHILE '(' condition ')' DO statementlist ENDWHILE 				{	$$=node_while($3,$6);}
	;

statementlist:
	statement ';' {$$=$1;}
	|
	statementlist statement ';' {$$=node_stmt($1,$2);}
	;
	
	
condition:
	expr {if(isBool($1)) $$=$1;}
	;
	
expr: 
	CONSTANT			{ $$ = $1; }
	|
	IDENT				{ $$ = node_var($1);}
	|
	IDENT '[' expr ']'	{ if(isInt($3))	$$ = node_derefArray($1,$3);}
	|
	READ '(' ')'		{ $$ = node_read(); }
	|
	expr '+' expr		{ typeCheckArith($1,$3);	$$ = node_arithmetic(CH_ADD,$1, $3);}
	|
	expr '-' expr		{ typeCheckArith($1,$3);	$$ = node_arithmetic(CH_SUB,$1, $3);}
	|
	expr '*' expr		{ typeCheckArith($1,$3);	$$ = node_arithmetic(CH_MUL,$1, $3);}
	|
	expr '/' expr		{ typeCheckArith($1,$3);	$$ = node_arithmetic(CH_DIV,$1, $3);}
	|
	expr '%' expr		{ typeCheckArith($1,$3);	$$ = node_arithmetic(CH_MOD,$1, $3);}
	|
	'(' expr ')' 		{ $$ = $2; }
	|
	'-' expr %prec UMINUS	{ if(isInt($2))	$$ = node_arithmetic(CH_UMINUS, $2,NULL);}
	|
	TRUE				{ $$ = node_const(TYPE_BOOL,1);}
	|
	FALSE				{ $$ = node_const(TYPE_BOOL,1);}
	|
	expr RELOP expr 	 	{ typeCheckRelop($1,$3);	$$ = node_relOp($1,$3,$2);	}
	|
	expr LOGOP expr 		{ typeCheckLogop($1,$3);	$$ = node_logOp($1,$3,$2);	}
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

int execute(node* nptr)
{
	initialiseCodeGen();
	codegen(nptr);
	completeCodeGen();
	return 0;
}

int arraydeclerror()
{
	char buf[50];
	sprintf(buf,"Error ar line %d \nSize of array should be greater than zero",lineno);			
	yyerror(buf);
}

