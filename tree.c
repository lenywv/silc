#include "tree.h"

node* make_node(int op,node *left,node *right,node *middle,char *name,int type,int value)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->op=op;
	ptr->left=left;
	ptr->right=right;
	ptr->middle=middle;
	ptr->value=value;
	ptr->type=type;
	if(name!=NULL)
		ptr->name=strdup(name);
	else
		ptr->name=NULL;
	return ptr;
}
node* node_func(char *name,node* body,node* rtrn)
{
	return make_node(CH_FUNC,body,rtrn,NULL,name,TYPE_VOID,0);
}

node* node_mainfunc(node* body)
{
	return make_node(CH_MAINFUNC,body,NULL,NULL,NULL,TYPE_VOID,0);
}

node* node_actualarg(node* expr)
{
	return make_node(CH_ACTARG,expr,NULL,NULL,NULL,expr->type,0);
}

node* node_addressof(char *name)
{
	return make_node(CH_ADDR,NULL,NULL,NULL,name,getVarType(name,root),0);
}

node* node_actualarglist(node *list,node *arg)
{
	list->right=arg;
	return list;
}

node* node_funccall(char *name,node *actarg)
{
	return make_node(CH_FUNCCALL,actarg,NULL,NULL,name,getVarType(name,root),0);
}

node* node_arithmetic(int op,node *left,node *right)
{
	return make_node(op,left, right,NULL,NULL,TYPE_INT, 0);
}

node* node_const(int type,int val)
{
	return make_node(CH_CONST,NULL,NULL,NULL,NULL,type,val);
}

node* node_logOp(node *left,node *right,int ops)//ops specifies which logop
{
	return make_node(CH_LOGOP,left,right,NULL,NULL,TYPE_BOOL,ops);
}

node* node_relOp(node *left,node *right,int ops)//ops specifies which relop 
{
	return make_node(CH_RELOP,left,right,NULL,NULL,TYPE_BOOL,ops);
}

node* node_read()
{
	return make_node(CH_READ,NULL,NULL,NULL,NULL,TYPE_INT,0); 
}

node* node_write(node* left)
{
	return make_node(CH_WRITE,left,NULL,NULL,NULL,TYPE_VOID,0);
}

node* node_if(node* left,node* right)
{
	return make_node(CH_IF,left,right,NULL,NULL,TYPE_VOID,0);
}

node* node_ifElse(node* left,node* right,node* middle)
{
	return make_node(CH_IFELSE,left,right,middle,NULL,TYPE_VOID,0);
}

node* node_while(node* left,node* right)
{
	return make_node(CH_WHILE,left,right,NULL,NULL,TYPE_VOID,0);
}

node* node_assign(node* right,char* name)
{
	return make_node(CH_ASSIGN,NULL,right,NULL,name,TYPE_VOID,0);
}

node* node_assignArray(node*left,node* right,char* name)
{
	return make_node(CH_ASSIGNARR,left,right,NULL,name,TYPE_VOID,0);
}

node* node_stmt(node* left,node* right)
{
	return make_node(CH_STMNT,left,right,NULL,NULL,TYPE_VOID,0);
}

node* node_var(char *name)
{
	return make_node(CH_IDENT,NULL,NULL,NULL,name,getVarType(name,root),0);
}

node* node_derefArray(char* name, node* left)
{
	return make_node(CH_IDENTARR,left,NULL,NULL,name,getVarType(name,root),0);
}


