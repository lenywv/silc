#include "types.h"
extern int lineno;
int isBool(node* nptr)
{
	if(nptr->type==TYPE_BOOL)
		return 1;
	return typeerror2(TYPE_BOOL,nptr->type);
}

int isInt(node* nptr)
{
	if(nptr->type==TYPE_INT)
		return 1;
	return typeerror2(TYPE_INT,nptr->type);
}

int isType(node* nptr,int type)
{
	if(nptr->type==type)
		return 1;
	return typeerror2(type,nptr->type);;
}

int getType(node* nptr)
{
	return nptr->type;
}

int typeCheckLogop(node *left,node *right)
{
	if(left->type!=TYPE_BOOL||right->type!=TYPE_BOOL)
		typeerror3(TYPE_BOOL,left->type,right->type);
	return 1;
}

int typeCheckRelop(node *left,node *right)
{
	if(left->type!=TYPE_INT||right->type!=TYPE_INT)
		typeerror3(TYPE_INT,left->type,right->type);
	return 1;
}

int typeCheckArith(node *left,node *right)
{
	return typeCheckRelop(left,right);
}

int typeCheckReturnStmt(int type,node *rtrn)
{
	if(rtrn->type!=type)
		return typeerror2(type,rtrn->type);
	return 0;
}
int typeerror()
{
	char buf[30];
	sprintf(buf,"Type error ");			
	yyerror(buf);
	exit(1);
}

int typeerror2(int typeexp,int type2)
{
	char buf[50];
	sprintf(buf,"Type error, expected type %s found %s",typeexp==TYPE_INT?"integer":"boolean",type2==TYPE_INT?"integer":"boolean");			
	yyerror(buf);
	exit(1);
}

int typeerror3(int typeexp,int type2,int type3)
{
	char buf[50];
	sprintf(buf,"Type error, expected type two %ss found %s and %s",typeexp==TYPE_INT?"integer":"boolean",type2==TYPE_INT?"integer":"boolean",type3==TYPE_INT?"integer":"boolean");			
	yyerror(buf);
	exit(1);
}

