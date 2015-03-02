#ifndef _TYPES_H
#define _TYPES_H
#include "operators.h"

#define TYPE_BOOL	0
#define TYPE_INT	1
#define TYPE_VOID	2

int isBool(node* nptr);


int isInt(node* nptr);


int isType(node* nptr,int type);


int getType(node* nptr);

#endif
