#include "evaluate.h"
#include "operators.h"
#include "types.h"
#include "symbol.h"
#include <stdio.h>

extern symnode *root;
int evaluate(node *ptr)
{
	int op=ptr->op,temp;
	char buf[30];
	symnode *symentry;
	switch(op)
	{
		case CH_CONST:
			return ptr->value;
		case CH_ADD:
			return evaluate(ptr->left)+evaluate(ptr->right);
		case CH_SUB:
			return evaluate(ptr->left)-evaluate(ptr->right);
		case CH_MUL:
			return evaluate(ptr->left)*evaluate(ptr->right);
		case CH_DIV:
			return evaluate(ptr->left)/evaluate(ptr->right);
		case CH_UMINUS:
			return -evaluate(ptr->left);
		case CH_IDENT:
			symentry=lookup(ptr->name,root);
			return *(symentry->binding);
		case CH_IDENTARR:
			temp=evaluate(ptr->left);
			symentry=lookup(ptr->name,root);
			return *(symentry->binding+temp);
		case CH_IF:
			if(evaluate(ptr->left)!=0)
				return evaluate(ptr->right);
			return 0;
		case CH_IFELSE:
			if(evaluate(ptr->left)!=0)
				return evaluate(ptr->right);
			else
				return evaluate(ptr->middle);
		
		case CH_STMNT:
			evaluate(ptr->left);
			return evaluate(ptr->right);
		case CH_READ:
			printf("enter ");
			scanf("%d",&temp);
			return temp;	
		case CH_WRITE:
			printf("%d\n",evaluate(ptr->left));	
			return 0;
		case CH_ASSIGN:
			symentry=lookup(ptr->name,root);
			*(symentry->binding)=evaluate(ptr->right);
			return 0;
		case CH_ASSIGNARR:
			symentry=lookup(ptr->name,root);
			temp=evaluate(ptr->left);
			*(symentry->binding+temp)=evaluate(ptr->right);
			return 0;
		case CH_RELOP:
			switch(ptr->value)
			{
				case CH_GE:
					if(evaluate(ptr->left)>=evaluate(ptr->right))
						return 1;
					return 0;
				case CH_LE:
					if(evaluate(ptr->left)<=evaluate(ptr->right))
						return 1;
					return 0;
				case CH_EQ:
					if(evaluate(ptr->left)==evaluate(ptr->right))
						return 1;
					return 0;
				case CH_NE:
					if(evaluate(ptr->left)!=evaluate(ptr->right))
						return 1;
					return 0;
				case CH_GT:
					if(evaluate(ptr->left)>evaluate(ptr->right))
						return 1;
					return 0;
				case CH_LT:
					if(evaluate(ptr->left)<evaluate(ptr->right))
						return 1;
					return 0;
				default:
					return 0;
			}
		case CH_LOGOP:
			switch(ptr->value)
			{
				case CH_LOGAND:
					if(evaluate(ptr->left)&&evaluate(ptr->right))
						return 1;
					return 0;

				case CH_LOGOR:
					if(evaluate(ptr->left)||evaluate(ptr->right))
						return 1;
					return 0;
				default:
					return 0;
			}
		case CH_WHILE:
			while(evaluate(ptr->left)!=0)
			{
				evaluate(ptr->right);
			}
			return 0;
			
		default:
			sprintf(buf,"Syntax error %d",op);			
			yyerror(buf);		
	}
}

