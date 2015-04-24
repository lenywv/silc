#include "operators.h"
#include "types.h"
#include "symbol.h"
extern symnode *root,*Lroot;
extern Lbind_base;
static int reg[8];
static int labelcount;
int initialiseCodeGen()
{
	int i;
	for(i=0;i<8;i++)
		reg[i]=0;
	labelcount=0;
	printf("START\n");
	printf("JMP main\n");
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
	int op=ptr->op,temp,reg1,reg2,reg3,label1,label2;
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
			reg2=codegen(ptr->left);
			reg1=getreg();
			printf("MOV R%d, 0\n",reg1);
			printf("SUB R%d, R%d\n",reg1,reg2);
			freereg(reg2);
			return reg1;
		case CH_ADDR:
			symentry=lookup(ptr->name,Lroot);
			reg1=getreg();
			if(symentry==NULL)
			{
				symentry=lookup(ptr->name,root);
				printf("MOV R%d, %d\n",reg1,symentry->bind);
			}
			else
			{
				printf("MOV R%d, %d\n",reg1,symentry->bind);
				reg2=getreg();
				printf("MOV R%d, BP\n",reg2);
				printf("ADD R%d, R%d\n",reg1,reg2);
				if(symentry->atype==ATYPEADDR)
					printf("MOV R%d, [R%d]\n",reg1,reg1);
				freereg(reg2);
			}
			return reg1;
		case CH_IDENT:
			symentry=lookup(ptr->name,Lroot);
			reg1=getreg();
			/*printf("MOV R%d, %d\n",reg1,symentry->bind);
			printf("MOV R%d, [R%d]\n",reg1,reg1);*/
			if(symentry==NULL)
			{
				symentry=lookup(ptr->name,root);
				printf("MOV R%d, [%d]\n",reg1,symentry->bind);
			}
			else
			{
				printf("MOV R%d, %d\n",reg1,symentry->bind);
				reg2=getreg();
				printf("MOV R%d, BP\n",reg2);
				printf("ADD R%d, R%d\n",reg1,reg2);
				printf("MOV R%d, [R%d]\n",reg1,reg1);
				if(symentry->atype==ATYPEADDR)
					printf("MOV R%d, [R%d]\n",reg1,reg1);
				freereg(reg2);
			}
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
			symentry=lookup(ptr->name,Lroot);
			reg3=codegen(ptr->right);
			/*reg1=getreg();
			printf("MOV R%d, %d\n",reg1,symentry->bind);
			printf("MOV [R%d], R%d\n",reg1,reg2);*/
			if(symentry==NULL)
			{
				symentry=lookup(ptr->name,root);
				printf("MOV [%d], R%d\n",symentry->bind,reg3);
			}
			else
			{
				reg1=getreg();
				reg2=getreg();
				printf("MOV R%d, %d\n",reg1,symentry->bind);
				printf("MOV R%d, BP\n",reg2);
				printf("ADD R%d, R%d\n",reg1,reg2);
				if(symentry->atype==ATYPEADDR)
					printf("MOV R%d, [R%d]\n",reg1,reg1);
				printf("MOV [R%d], R%d\n",reg1,reg3);
				freereg(reg2);
				freereg(reg1);
			}
			
			freereg(reg3);
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
		case CH_MAINFUNC:
			printf("main:\n");
			reg1=getreg();
			reg2=getreg();
			//pushing space for global variable
			printf("MOV R%d, %d\n",reg1,bind_base);
			printf("MOV R%d, BP\n",reg2);
			printf("ADD R%d, R%d\n",reg1,reg2);
			printf("MOV SP, R%d\n",reg1);
			
			//pushing space for global variables
			printf("PUSH BP\n");
			printf("MOV BP, SP\n");
			printf("MOV R%d, %d\n",reg1,Lbind_base);
			printf("MOV R%d, BP\n",reg2);
			printf("ADD R%d, R%d\n",reg1,reg2);
			printf("MOV SP, R%d\n",reg1);
			freereg(reg1);
			freereg(reg2);
			codegen(ptr->left);
			printf("MOV SP, BP\n");
			printf("POP BP\n");
			return 0;		
		case CH_FUNC:
			printf("%s:\n",ptr->name);
			reg1=getreg();
			reg2=getreg();
			printf("PUSH BP\n");
			printf("MOV BP, SP\n");
			printf("MOV R%d, %d\n",reg1,Lbind_base-1);
			printf("MOV R%d, BP\n",reg2);
			printf("ADD R%d, R%d\n",reg1,reg2);
			printf("MOV SP, R%d\n",reg1);
			freereg(reg1);
			freereg(reg2);
			codegen(ptr->left);
			reg1=codegen(ptr->right);
			reg2=getreg();
			reg3=getreg();
			printf("MOV R%d, BP\n",reg2);
			printf("MOV R%d, -2\n",reg3);
			printf("ADD R%d, R%d\n",reg2,reg3);
			printf("MOV [R%d], R%d\n",reg2,reg1);
			freereg(reg1);
			freereg(reg2);
			freereg(reg3);
			printf("MOV SP, BP\n");
			printf("POP BP\n");
			printf("RET\n");
			return 0;
		case CH_FUNCCALL:
			return generate_code_func_call(ptr->name,ptr->left);
		default:
			sprintf(buf,"Syntax error %d",op);			
			yyerror(buf);		
	}
}

int generate_code_func_call(char* name, node *actarg)
{
	int reg1,regpost1,regpost2,i,regstatus[8],n_args=0,returnreg;
	for(i=0;i<8;i++)
	{
		regstatus[i]=getregstatus(i);
		if(regstatus[i])
			printf("PUSH R%d\n",i);//pushing all the current register values to stack
	}
	returnreg=getreg();
	regpost1=getreg();
	regpost2=getreg();
	resetreg();
	while(actarg!=NULL)
		{
		reg1=codegen(actarg->left);
		printf("PUSH R%d\n",reg1);//pushing the arguments
		freereg(reg1);
		actarg=actarg->right;
		n_args++;
	}
	printf("PUSH R0\n");//space for return value
	printf("CALL %s\n",name);//calling function
	
	//post call
	printf("POP R%d\n",returnreg);
	printf("MOV R%d, -%d\n",regpost1,n_args);
	printf("MOV R%d, SP\n",regpost2);
	printf("ADD R%d, R%d\n",regpost1,regpost2);
	printf("MOV SP, R%d\n",regpost1);
	
	for(i=0;i<8;i++)
	{
		setregstatus(i,regstatus[i]);
		if(regstatus[i])
			printf("POP R%d\n",i);
	}
	setregstatus(returnreg,1);
	return returnreg;
}

int freereg(int regnum)
{
	reg[regnum]=0;
	return 0;
}
int resetreg()
{
	int i;
	for(i=0;i<8;i++)
		reg[i]=0;

}

int setregstatus(int regnum,int status)
{
	reg[regnum]=status;
	return 0;
}

int getregstatus(int regnum)
{
	return reg[regnum];
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
