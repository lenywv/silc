%{
#include "operators.h"
#include "symbol.h"
#include "types.h"
#include "tree.h"
#include "evaluate.h"
#include "actions.h"

int yytext(void);
void yyerror(char *);
int type;
extern int lineno;
extern Lbind_base;
symnode *root,*Lroot;
%}

%union
{
		int i;
		char *name;
		struct treenode *nptr;
		struct argumentnode *aptr;
};

%token CONSTANT IDENT END MAIN
%token INTEGER BOOLEAN DECL ENDDECL RETURN
%token IF ELSE WHILE READ ENDIF WRITE TRUE FALSE DO ENDWHILE

%type <nptr> expr statement statementlist CONSTANT condition functiondefs function mainfunction returnstmt actualarglist nonemptyactualarglist actualarg
%type <aptr> arg arglist
%type <i> RELOP LOGOP
%type <name> IDENT functionheader
%left LOGOP
%left RELOP 
%left '+' '-'
%left '%' '*' '/'
%nonassoc UMINUS
%%

program:
	declarations functiondefs mainfunction	{ execute($3);}
	//|
	//statementlist  END	{ execute($1); exit(1);}
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
	|
	vartype IDENT '(' arglist ')' {makeSymEntry($2,root,0,type,$4);}
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
	IDENT {makeSymEntry($1,root,1,type,NULL);}
	|
	IDENT '[' CONSTANT ']' {if($3->value>0) makeSymEntry($1,root,$3->value,type,NULL); else arraydeclerror();}
	;	
	
functiondefs:
	functiondefs function	{Ldestruct(Lroot);}
	|
	{$$=NULL;}
	//function	{Ldestruct(Lroot);}
	;

function:
	 functionheader '{' Ldeclarations statementlist  returnstmt '}' {return_type_check($1,$5);$$=node_func($1,$4,$5);execute($$);}

functionheader:
	vartype IDENT '(' arglist ')' {silc_on_func_header(type,$2,$4); $$=$2;}

returnstmt:
	RETURN expr ';' {$$=$2;}

mainfunction:
	INTEGER MAIN '(' ')' '{' Ldeclarations statementlist '}' {$$=node_mainfunc($7);}
	
arglist:
	arglist ',' arg	{ linkArgs($1,$3);}
	|
	arg
	;

arg:
	vartype IDENT { $$=makeArgNode(type,$2,ATYPENORM);}
	|
	vartype '&' IDENT { $$=makeArgNode(type,$3,ATYPEADDR);}
	;
	
Ldeclarations:
	DECL Ldecllist ENDDECL
	|
	;

Ldecllist:
	Ldecllist Ldeclaration ';' 
	|
	Ldeclaration ';'
	;

Ldeclaration:
	vartype Lvarlist
	;
Lvarlist:
	Lvarlist ',' Lvariable
	|
	Lvariable
	;
	
Lvariable:
	IDENT {makeLSymEntry($1,Lroot,type,0,0); }
	;


statement:
	IDENT '=' expr 			{if(isType($3,getVarType($1,Lroot)))			$$=node_assign($3,$1);}
	|
	IDENT '[' expr ']' '=' expr 	{if(isType($6,getVarType($1,Lroot))&&isInt($3))	$$=node_assignArray($3,$6,$1);}
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
	'&' IDENT			{ $$ = node_addressof($2);}
	|
	IDENT '(' actualarglist ')'	{check_func_sign($1,$3); $$=node_funccall($1,$3);}
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
	
actualarglist:
		{$$=NULL;}	
	|
	nonemptyactualarglist	{$$=$1;}
	;

nonemptyactualarglist:
	nonemptyactualarglist ',' actualarg	{$$=node_actualarglist($3,$1);}
	|
	actualarg	{$$=$1;}
	;
actualarg:
	expr {$$=node_actualarg($1);}
	;
%%

void yyerror (char *s)
{
	fprintf(stderr,"%s at line no %d \n",s,lineno);
}

int main(void)
{
	root=construct();
	Lroot=Lconstruct();
	initialiseCodeGen();
	yyparse();
	completeCodeGen();
	return 0;
}

int execute(node* nptr)
{
	codegen(nptr);
	return 0;
}


