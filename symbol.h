typedef struct symbolnode
{
		char *name;
		int type;
		int size; 
		int *binding;
		struct symbolnode *next;
}symnode;

symnode* construct();

symnode* lookup(char *n,symnode *table);

symnode* makeSymEntry(char *n,symnode *table,int v,int t);

#include <stdio.h>
#include <stdlib.h>
symnode* construct()
{
		symnode *root;
		root=(symnode *)malloc(sizeof(symnode));
		root->name="-1";
		root->type=-1;
		root->size=-1;
		root->binding=NULL;
		root->next=NULL;
		return root;
}

symnode* lookup(char *n,symnode *table) 
{
		int a=0;
		if(table==NULL)
			return NULL;
		if(strcmp(table->name,n)!=0)
			return lookup(n,table->next);
		else
			return table;
}

symnode* makeSymEntry(char *n,symnode *table,int v,int t)
{
			symnode *node;
			node=lookup(n,table);
			if(node==NULL)
			{
				symnode *new;
				new=(symnode *)malloc(sizeof(symnode));
				new->binding=malloc(sizeof(int)*v);
				new->name=n;
				new->size=v;
				new->type=t;
				new->next=table->next;
				table->next=new;
				return table;
			}
			else
			{
				printf("Symbol already exists\n");
				return NULL;
			}	
}
	
