#ifndef _OPERATOR_H
#define _OPERATOR_H

#define CH_ADD '+'
#define CH_SUB '-'
#define CH_DIV '/'
#define CH_MUL '*'
#define CH_MOD '%'
#define CH_CONST ' '
#define CH_ASSIGN '='
#define CH_UMINUS 257

#define CH_GE 1
#define CH_LE 2
#define CH_EQ 3
#define CH_NE 4
#define CH_LT '<'
#define CH_GT '>'
#define CH_RELOP 	258
#define CH_IF		259
#define CH_IFELSE	260
#define CH_IDENT	261
#define CH_STMNT	262
#define CH_READ		263
#define CH_WRITE	264
#define CH_WHILE	265
#define CH_IDENTARR	266
#define CH_ASSIGNARR	267
#define CH_LOGAND	268
#define CH_LOGOR	269
#define CH_LOGOP	270

typedef struct treenode
{
	int op,type;
	char *name;
	struct treenode *left,*right,*middle;
	int value;
}node;
node* make_node(int op,node *left,node *right,node *middle,char *name,int type,int value);
#endif
