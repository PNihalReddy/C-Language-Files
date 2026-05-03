#include <stdio.h>
#include <math.h>

int op_stack[50];
int top=-1;


void push(int X);
int pop();


int main()
{
	char postfix[50],X;
	int opnd1,opnd2,p_index=0;
	printf("Enter the postfix expression:");
	scanf("%s",postfix);
	
	do
	{
		X=postfix[p_index];
		
		if(X>='0' && X<='9')
		{
			push(X-'0');
		}
		
		else
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
		p_index++;
	}while(postfix[p_index]!='\0');
	printf("Result is : %d\n",pop());
	
}


void push(int X)
{
	op_stack[++top]=X;
}


int pop()
{
	return op_stack[top--];
}
