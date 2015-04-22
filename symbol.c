#include "symbol.h"

symnode* construct()
{
		bind_base=0;
		symnode *root;
		root=(symnode *)malloc(sizeof(symnode));
		root->name="-1";
		root->type=-1;
		root->size=-1;
		root->binding=NULL;
		root->next=NULL;
		root->args=NULL;
		return root;
}

symnode* Lconstruct()
{
		Lbind_base=1;
		Lbind_argbase=-3;
		symnode *Lroot;
		root=(symnode *)malloc(sizeof(symnode));
		root->name="-1";
		root->type=-1;
		root->size=-1;
		root->binding=NULL;
		root->next=NULL;
		root->args=NULL;
		return Lroot;
}
symnode* Ldestruct(symnode *Lroot)
{
	Lbind_base=1;
	if(Lroot!=NULL)
		deletenodes(Lroot->next);
}

deletenodes(symnode *node)
{
	if(node!=NULL)
	{
		deletenodes(node->next);
		free(node);
	}
		
}
int getVarType(char *n,symnode *table)
{
	symnode *entry=lookup(n,table);
	return entry->type;
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

symnode* makeSymEntry(char *n,symnode *table,int v,int t,argnode* args)
{
			symnode *node;
			node=lookup(n,table);
			if(node==NULL)
			{
				symnode *new;
				new=(symnode *)malloc(sizeof(symnode));
				new->name=n;
				new->size=v;
				new->type=t;
				new->next=table->next;
				table->next=new;
				new->args=args;
				if(args==NULL)
				{
					new->bind=bind_base;
					new->binding=malloc(sizeof(int)*v);
					bind_base+=v;
				}
				return table;
			}
			else
			{
				printf("Symbol already exists\n");
				return NULL;
			}	
}

symnode* makeLSymEntry(char *n,symnode *table,int t,int isarg)
{
			symnode *node;
			node=lookup(n,table);
			if(node==NULL)
			{
				symnode *new;
				new=(symnode *)malloc(sizeof(symnode));
				new->name=n;
				new->size=1;
				new->type=t;
				new->next=table->next;
				table->next=new;
				new->args=NULL;
				new->binding=NULL;//malloc(sizeof(int)*v);
				if(isarg)
				{
					new->bind=Lbind_argbase;
					Lbind_argbase-=1;
				}
				else
				{
					new->bind=Lbind_base;
					Lbind_base+=1;
				}
				return table;
			}
			else
			{
				printf("Symbol already exists\n");
				return NULL;
			}	
}

argnode* makeArgNode(int type,char* name,int refer)
{
	argnode *aptr=(argnode*)malloc(sizeof(argnode));
	aptr->name=name;
	aptr->type=type;
	aptr->refer=refer;
	aptr->next=NULL;
	return aptr;
}

int linkArgs(argnode *left,argnode *right)
{
	left->next=right;
}
