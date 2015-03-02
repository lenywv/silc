#include "operators.h"
#include <stdlib.h>
#include <string.h>
node* make_node(int op,node *left,node *right,node *middle,char *name,int type,int value)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->op=op;
	ptr->left=left;
	ptr->right=right;
	ptr->middle=middle;
	ptr->value=value;
	ptr->type=type;
	if(name!=NULL)
		ptr->name=strdup(name);
	else
		ptr->name=NULL;
	return ptr;
}

