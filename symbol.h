#ifndef _SYMBOL_H
#define _SYMBOL_H
#define ATYPENORM 0//value is passed used as id
#define ATYPEADDR 1//reference is passed used as id

int bind_base,Lbind_base,Lbind_argbase;

typedef struct argumentnode
{
	char *name;
	int type,refer;
	struct argumentnode *next;
}argnode;

typedef struct symbolnode
{
	char *name;
	int type;
	int size; 
	int *binding,bind;
	struct argumentnode *args;
	struct symbolnode *next;
}symnode;
/*
typedef struct symboltable
{
	int bind_base;
	struct symbolnode *symbols;
	struct symboltable *parent;
}
*/
#include "operators.h"
#include "types.h"

symnode* construct();

symnode* Lconstruct();

int getVarType(char *n,symnode *table);

symnode* lookup(char *n,symnode *table);

symnode* makeSymEntry(char *n,symnode *table,int v,int t,argnode *args);

argnode* makeArgNode(int type,char* name,int refer);

#endif
