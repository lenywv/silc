#include "operators.h"
#include "types.h"
#include "symbol.h"
#include <stdio.h>
extern symnode *root;
static int reg[8];
static int labelcount;
int initialiseCodeGen()
{
	int i;
	for(i=0;i<8;i++)
		reg[i]=0;
	labelcount=0;
	printf("START\n");
	return 0;
}
int completeCodeGen()
{
	printf("HALT\n");
	return 0;
}
int getLabel()
{
	return labelcount++;
}

int codegen(node *ptr)
{
	int op=ptr->op,temp,reg1,reg2,label1,label2;
	char buf[30];
	symnode *symentry;
	switch(op)
	{
		case CH_CONST:
			reg1=getreg();
			printf("MOV R%d, %d\n",reg1,ptr->value);
			return reg1;
		case CH_ADD:
			reg1=codegen(ptr->left);
			reg2=codegen(ptr->right);
			printf("ADD R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			return reg1;
		case CH_SUB:
			reg1=codegen(ptr->left);
			reg2=codegen(ptr->right);
			printf("SUB R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			return reg1;
		case CH_MUL:
			reg1=codegen(ptr->left);
			reg2=codegen(ptr->right);
			printf("MUL R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			return reg1;
		case CH_DIV:
			reg1=codegen(ptr->left);
			reg2=codegen(ptr->right);
			printf("DIV R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			return reg1;
		case CH_UMINUS:
			reg1=getreg();
			reg2=codegen(ptr->left);
			printf("MOV R%d, 0\n",reg1);
			printf("SUB R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			return reg1;
		case CH_IDENT:
			symentry=lookup(ptr->name,root);
			reg1=getreg();
			printf("MOV R%d, %d\n",reg1,symentry->bind);
			printf("MOV R%d, [R%d]\n",reg1,reg1);
			return reg1;
		case CH_IDENTARR:
			symentry=lookup(ptr->name,root);
			reg2=codegen(ptr->left);//expr in var[expr]
			reg1=getreg();
			printf("MOV R%d, %d\n",reg1,symentry->bind);
			printf("ADD R%d, R%d\n",reg1,reg2);
			printf("MOV R%d, [R%d]\n",reg1,reg1);
			freereg(reg2);
			return reg1;
		case CH_IF:
			reg1=codegen(ptr->left);
			label1=getLabel();
			printf("JZ R%d, L%d\n",reg1,label1);
			freereg(reg1);
			codegen(ptr->right);
			printf("L%d:\n",label1);
			return 0;
		case CH_IFELSE:
			reg1=codegen(ptr->left);
			label1=getLabel();
			label2=getLabel();
			printf("JZ R%d, L%d\n",reg1,label1);
			freereg(reg1);
			codegen(ptr->right);
			printf("JMP L%d\n",label2);
			printf("L%d:\n",label1);
			codegen(ptr->middle);
			printf("L%d:\n",label2);
			return 0;
		case CH_STMNT:
			codegen(ptr->left);
			return codegen(ptr->right);
		case CH_READ:
			reg1=getreg();
			printf("IN R%d\n",reg1);
			return reg1;	
		case CH_WRITE:
			reg1=codegen(ptr->left);
			printf("OUT R%d\n",reg1);
			freereg(reg1);
			return 0;
		case CH_ASSIGN:
			symentry=lookup(ptr->name,root);
			reg2=codegen(ptr->right);
			/*reg1=getreg();
			printf("MOV R%d, %d\n",reg1,symentry->bind);
			printf("MOV [R%d], R%d\n",reg1,reg2);*/
			printf("MOV [%d], R%d\n",symentry->bind,reg2);
			freereg(reg2);
			//freereg(reg1);
			return 0;
		case CH_ASSIGNARR:
			symentry=lookup(ptr->name,root);
			reg2=codegen(ptr->left);//expr in var[expr]
			reg1=getreg();
			printf("MOV R%d, %d\n",reg1,symentry->bind);
			printf("ADD R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			reg2=codegen(ptr->right);
			printf("MOV [R%d], R%d\n",reg1,reg2);
			freereg(reg2);
			freereg(reg1);
			return 0;
		case CH_RELOP:
			switch(ptr->value)
			{
				case CH_GE:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("GE R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
				case CH_LE:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("LE R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
				case CH_EQ:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("EQ R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
				case CH_NE:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("NE R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
				case CH_GT:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("GT R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
				case CH_LT:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("LT R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
				default:
					return 0;
			}
		case CH_LOGOP:
			switch(ptr->value)
			{
				case CH_LOGAND:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("MUL R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;

				case CH_LOGOR:
					reg1=codegen(ptr->left);
					reg2=codegen(ptr->right);
					printf("ADD R%d, R%d\n",reg1,reg2);
					freereg(reg2);
					return reg1;
					
				default:
					return 0;
			}
		case CH_WHILE:
			label1=getLabel();
			label2=getLabel();
			printf("L%d:\n",label1);
			reg1=codegen(ptr->left);
			printf("JZ R%d, L%d\n",reg1,label2);
			freereg(reg1);
			codegen(ptr->right);
			printf("JMP L%d\n",label1);
			printf("L%d:\n",label2);
			return 0;
			
		default:
			sprintf(buf,"Syntax error %d",op);			
			yyerror(buf);		
	}
}

int freereg(int regnum)
{
	reg[regnum]=0;
	return 0;
}

int getreg()
{
	int i;
	for(i=0;i<8;i++)
	{
		if(reg[i]==0)
		{
			reg[i]=1;
			return i;
		}
	}
	return -1;
}
