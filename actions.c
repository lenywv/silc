#include "actions.h"
extern symnode *root,*Lroot;
extern int lineno;
int silc_on_func_header(int type,char *name,argnode *args)
{

	Ldestruct(Lroot);
	symnode *entry=lookup(name,root);
	if(entry==NULL||entry->args==NULL)
		function_not_declared_error(name);
	if(compare_arglist(entry,args))
		function_arglist_different(name);
	while(args!=NULL)
	{
		makeLSymEntry(args->name,Lroot,args->type);
		args=args->next;
	}
	return 0;
}
int return_type_check(char *name,node* rtrn)
{
	Ldestruct(Lroot);
	return typeCheckReturnStmt(getVarType(name,root),rtrn);
}

int check_func_sign(char *name,node *args)
{
	symnode *entry=lookup(name,root);
	if(entry==NULL||entry->args==NULL)
		function_not_declared_error(name);
	
}

int compare_arglist(argnode* decl,argnode *def)
{
	if(decl==NULL&&def==NULL)
		return 0;
	if(decl!=NULL&&def==NULL)
		return 1;
	if(decl==NULL&&def!=NULL)
		return 1;
	if(strcmp(decl->name,def->name)!=0||decl->type!=def->type)
		return 1;
	return compare_arglist(decl->next,def->next);
}

int compare_arglist2(argnode* decl,node *act)
{
	if(decl==NULL&&act==NULL)
		return 0;
	if(decl!=NULL&&act==NULL)
		return 1;
	if(decl==NULL&&act!=NULL)
		return 1;
	if(decl->type!=act->type)
		return 1;
	if(decl->refer==1&&act->op!=CH_ADDR)
		return 1;
	return compare_arglist2(decl->next,act->right);
}

int function_not_declared_error(char *name)
{
	char buf[50];
	sprintf(buf,"Error ar line %d \nFunction %s was not declared ",lineno,name);
	yyerror(buf);
}

int function_arglist_different(char *name)
{
	char buf[50];
	sprintf(buf,"Error ar line %d \nThe argument list of function %s is different from its declaration ",lineno,name);
	yyerror(buf);
}
int arraydeclerror()
{
	char buf[50];
	sprintf(buf,"Error ar line %d \nSize of array should be greater than zero",lineno);			
	yyerror(buf);
}
