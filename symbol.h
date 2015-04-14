#ifndef _SYMBOL_H
#define _SYMBOL_H

int bind_base;
typedef struct symbolnode
{
	char *name;
	int type;
	int size; 
	int *binding,bind;
	struct symbolnode *next;
}symnode;

typedef struct argumentnode
{
	char *name;
	int type;
	struct argumentnode *next;
}argnode;

#include "operators.h"
#include "types.h"

symnode* construct();

int getVarType(char *n,symnode *table);

symnode* lookup(char *n,symnode *table);

symnode* makeSymEntry(char *n,symnode *table,int v,int t);

#endif
