#ifndef _TYPES_H
#define _TYPES_H

#define TYPE_BOOL	0
#define TYPE_INT	1
#define TYPE_VOID	2

#include "operators.h"
#include "symbol.h"
#include "tree.h"

int isBool(node* nptr);

int isInt(node* nptr);

int isType(node* nptr,int type);

int getType(node* nptr);

int typeCheckLogop(node *left,node *right);

int typeCheckRelop(node *left,node *right);

int typeCheckArith(node *left,node *right);
#endif
