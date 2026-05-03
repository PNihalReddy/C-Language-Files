#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int op_stack[50];
int top=-1;

void push(int N);
int pop();
int chk_operator(char C);


int main()
{
	int p_index=0,opnd1,opnd2,N_index=-1;
	char postfix[100],num[25],X;
	printf("Enter postfix expression and use space after operands:");
	scanf(" %[^\n]s",&postfix);
	
	do
	{
		X=postfix[p_index];
		if(chk_operator(X))
		{
			opnd2=pop();
			opnd1=pop();
			switch(X)
			{
				case '+':
					push(opnd1+opnd2);
					break;
				
				case '-':
					push(opnd1-opnd2);
					break;
				
				case '*':
					push(opnd1*opnd2);
					break;
				
				case '/':
					push(opnd1/opnd2);
					break;
				
				case '%':
					push(opnd1%opnd2);
					break;
				
				case '^':
					push((int)pow(opnd1,opnd2));
					break;
			}
		}
		
		else
		{
			while(postfix[p_index]!=' ')
			{
				num[++N_index]=postfix[p_index++];
			}
			push(atoi(num));
			N_index=0;
			
			while(num[N_index]!='\0')
			{
				num[N_index++]='\0';
			}
			N_index=-1;
		}
		p_index++;
	}while(postfix[p_index]!='\0');
	
	printf("The result is : %d\n",pop());
	
}



void push(int N)
{
	op_stack[++top]=N;
}


int pop()
{
	return op_stack[top--];
}


int chk_operator(char C)
{
	switch(C)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			return 1;
		default:
			return 0;
	}
}
