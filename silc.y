%{
#include <stdio.h>
#include <stdlib.h>
#include "operators.h"
#include "symbol.h"
#include "types.h"
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
};

%token CONSTANT IDENT END
%token INTEGER BOOLEAN DECL ENDDECL
%token IF ELSE PRINT WHILE READ ENDIF WRITE TRUE FALSE DO ENDWHILE

%type <nptr> expr statement statementlist CONSTANT
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

declaration:
	vartype varlist 
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
	IDENT '[' CONSTANT ']' {makeSymEntry($1,root,$3->value,type);}
	;

statement:
	IDENT '=' expr 			{if(isType($3,getVarType($1,root)))			$$=make_node(CH_ASSIGN,NULL,$3,NULL,$1,TYPE_VOID,0);	else typeerror2(getVarType($1,root),getType($3));}
	|
	IDENT '[' expr ']' '=' expr 	{if(isType($6,getVarType($1,root))&&isInt($3))	$$=make_node(CH_ASSIGNARR,$3,$6,NULL,$1,TYPE_VOID,0); else 	typeerror();}
	|
	WRITE '(' expr ')' 		{if(isInt($3))					$$=make_node(CH_WRITE,$3,NULL,NULL,NULL,TYPE_VOID,0); else  typeerror();}
	|
	IF '(' expr ')' statementlist ENDIF 				{if(isBool($3))	$$=make_node(CH_IF,$3,$5,NULL,NULL,TYPE_VOID,0);	else typeerror();}
	|
	IF '(' expr ')' statementlist ELSE statementlist ENDIF 	{if(isBool($3))	$$=make_node(CH_IFELSE,$3,$5,$7,NULL,TYPE_VOID,0);	else typeerror();}
	|
	WHILE '(' expr ')' DO statementlist ENDWHILE 			{if(isBool($3))	$$=make_node(CH_WHILE,$3,$6,NULL,NULL,TYPE_VOID,0);	else typeerror(); }
	;

statementlist:
	statement ';' {$$=$1;}
	|
	statementlist statement ';' {$$=make_node(CH_STMNT,$1,$2,NULL,NULL,TYPE_VOID,0);}
	;
	
	
expr: 
	CONSTANT	{ $$ = $1; }
	|
	IDENT		{ $$ =make_node(CH_IDENT,NULL,NULL,NULL,$1,getVarType($1,root),0);}
	|
	IDENT '[' expr ']'	{ if(isInt($3))	$$ =make_node(CH_IDENTARR,$3,NULL,NULL,$1,getVarType($1,root),0); else typeerror();}
	|
	READ '(' ')'	{ $$ = make_node(CH_READ,NULL,NULL,NULL,NULL,TYPE_INT,0); }
	|
	expr '+' expr	{ if(isInt($1)&&isInt($3))	$$ = make_node(CH_ADD,$1, $3,NULL,NULL,TYPE_INT, 0); else typeerror();}
	|
	expr '-' expr	{ if(isInt($1)&&isInt($3))	$$ = make_node(CH_SUB,$1, $3,NULL,NULL,TYPE_INT, 0); else typeerror();}
	|
	expr '*' expr	{ if(isInt($1)&&isInt($3))	$$ = make_node(CH_MUL,$1, $3,NULL,NULL,TYPE_INT, 0); else typeerror();}
	|
	expr '/' expr	{ if(isInt($1)&&isInt($3))	$$ = make_node(CH_DIV,$1, $3,NULL,NULL,TYPE_INT, 0); else typeerror();}
	|
	expr '%' expr	{ if(isInt($1)&&isInt($3))	$$ = make_node(CH_MOD,$1, $3,NULL,NULL,TYPE_INT, 0); else typeerror();}
	|
	'(' expr ')' 	{ $$ = $2; }
	|
	'-' expr %prec UMINUS { $$ = make_node(CH_UMINUS, $2, NULL,NULL,NULL,TYPE_INT,0); }
	|
	TRUE			{ $$ = make_node(CH_CONST,NULL,NULL,NULL,NULL,TYPE_BOOL,1);}
	|
	FALSE			{ $$ = make_node(CH_CONST,NULL,NULL,NULL,NULL,TYPE_BOOL,0);}
	|
	expr RELOP expr  	{ if(isInt($1)&&isInt($3))	$$ = make_node(CH_RELOP,$1,$3,NULL,NULL,TYPE_BOOL,$2);	else typeerror3(TYPE_INT,getType($1),getType($1));}
	|
	expr LOGOP expr 	{ if(isBool($1)&&isBool($3))	$$ = make_node(CH_LOGOP,$1,$3,NULL,NULL,TYPE_BOOL,$2);	else typeerror();}
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

int typeerror()
{
	char buf[30];
	sprintf(buf,"Type error at line %d",lineno);			
	yyerror(buf);
	exit(1);
}

int typeerror2(int type1,int type2)
{
	char buf[50];
	sprintf(buf,"Type error at line %d expected type %s found %s",lineno,type1==TYPE_INT?"integer":"boolean",type2==TYPE_INT?"integer":"boolean");			
	yyerror(buf);
	exit(1);
}

int typeerror3(int type1,int type2,int type3)
{
	char buf[50];
	sprintf(buf,"Type error at line %d expected type %s found %s and %s",lineno,type1==TYPE_INT?"integer":"boolean",type2==TYPE_INT?"integer":"boolean",type3==TYPE_INT?"integer":"boolean");			
	yyerror(buf);
	exit(1);
}
