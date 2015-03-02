#ifndef _SYMBOL_H
#define _SYMBOL_H
typedef struct symbolnode
{
		char *name;
		int type;
		int size; 
		int *binding;
		struct symbolnode *next;
}symnode;

symnode* construct();

int getVarType(char *n,symnode *table);

symnode* lookup(char *n,symnode *table);

symnode* makeSymEntry(char *n,symnode *table,int v,int t);

#endif
