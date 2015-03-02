#include "types.h"
#include "operators.h"
#include "symbol.h"

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
