#include "operators.h"
#define TYPE_BOOL	0
#define TYPE_INT	1
#define TYPE_VOID	2

int isBool(node* nptr)
{
	if(nptr->type==TYPE_BOOL)
		return 1;
	return 0;
}

int isInt(node* nptr)
{
	if(nptr->type==TYPE_INT)
		return 1;
	return 0;
}

int isType(node* nptr,int type)
{
	if(nptr->type==type)
		return 1;
	return 0;
}

int getType(node* nptr)
{
	return nptr->type;
}
