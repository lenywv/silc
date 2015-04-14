#ifndef _TREE_H
#define _TREE_H
typedef struct treenode
{
	int op,type;
	char *name;
	struct treenode *left,*right,*middle;
	int value;
}node;


#include "operators.h"
#include <string.h>
#include "types.h"
#include "symbol.h"

extern symnode* root;

node* make_node(int op,node *left,node *right,node *middle,char *name,int type,int value);
node* node_arithmetic(int op,node *left,node *right);
node* node_const(int type,int val);
node* node_relOp(node *left,node *right,int ops);
node* node_logOp(node *left,node *right,int ops);
node* node_read();
node* node_write(node* left);
node* node_if(node* left,node* right);
node* node_ifElse(node* left,node* right,node* middle);
node* node_while(node* left,node* right);
node* node_assign(node* right,char* name);
node* node_assignArray(node*left,node* right,char* name);
node* node_stmt(node* left,node* right);
node* node_var(char *name);
node* node_derefArray(char* name, node* left);

#endif
