#include "symbol.h"
extern symnode *root,*Lroot;
symnode* construct()
{
		bind_base=0;
		symnode *nroot;
		nroot=(symnode *)malloc(sizeof(symnode));
		nroot->name="-1";
		nroot->type=-1;
		nroot->size=-1;
		nroot->binding=NULL;
		nroot->next=NULL;
		nroot->args=NULL;
		return nroot;
}

symnode* Lconstruct()
{
		Lbind_base=1;
		Lbind_argbase=-3;
		symnode *Lnroot;
		Lnroot=(symnode *)malloc(sizeof(symnode));
		Lnroot->name="-1";
		Lnroot->type=-1;
		Lnroot->size=-1;
		Lnroot->atype=0;
		Lnroot->binding=NULL;
		Lnroot->next=NULL;
		Lnroot->args=NULL;
		return Lnroot;
}
symnode* Ldestruct(symnode *Lroot1)
{
	Lbind_base=1;
	Lbind_argbase=-3;
	if(Lroot1!=NULL)
		deletenodes(Lroot1->next);
	Lroot1->next=NULL;
}

deletenodes(symnode *snode)
{
	if(snode!=NULL)
	{
		deletenodes(snode->next);
		free(snode);
	}
		
}
int getVarType(char *n,symnode *table)
{
	char buf[50];
	symnode *entry=lookup(n,Lroot);
	if(entry==NULL)
		entry=lookup(n,root);
	if(entry==NULL)
	{
		sprintf(buf,"Variable %s was not declared ",n);
		yyerror(buf);
	}
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

symnode* makeLSymEntry(char *n,symnode *table,int t,int isarg,int atype)
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
				new->atype=atype;
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
				printf("Symbol %s already exists\n",n);
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
	while(left->next!=NULL)
		left=left->next;
	left->next=right;
}
