#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car
{
	char name[20];
	int model;
	float price;
	struct car *next;
}*node=NULL,*head=NULL,*newnode=NULL,*delnode=NULL;

void push();
void pop();
void peep();
void peek();
void display();


int main()
{
	int opt;
	char ch;
	do
	{
		printf("1.PUSH 2.POP 3.PEEP 4.PEEK 5.DISPLAY\n");
		printf("Enter your choice:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:peep();break;
			case 4:peek();break;
			case 5:display;break;
			default:
				printf("Invalid Option\n");
				break;
		}
		printf("Enter y to continue\n");
		scanf("%s",&ch);
	}while(ch=='y');
	
}


void push()
{
	newnode=(struct car*)malloc(sizeof(struct car));
	printf("Enter car details:\n");
	scanf("%s %d %f",&newnode->name,&newnode->model,&newnode->price);
	
	if(head==NULL)
	{
		newnode->next=NULL;
	}
	
	else
	{
		newnode->next=head;
	}
	head=newnode;
}


void pop()
{
	if(head==NULL)
	{
		printf("Underflow\n");
	}
	
	else
	{
		delnode=head;
		head=head->next;
		printf("The car details are - \n");
		printf("%s %d %.2f\n",delnode->name,delnode->model,delnode->price);
		free(delnode);
		delnode=NULL;
	}
}


void peep()
{
	if(head==NULL)
	{
		printf("Underflow\n");
	}
	
	else
	{
		char name[30];
		int found=0;
		printf("Enter car name to search:\n");
		scanf("%s",name);
		
		node=head;
		while(node!=NULL)
		{
			if(strcmp(name,node->name)==0)
			{
				found=1;
				break;
			}
			node=node->next;
		}
		
		if(found)
		{
			printf("Car found its details are - \n");
			printf("%s %d %.2f\n",node->name,node->model,node->price);
		}
		
		else
		{
			printf("Car not found\n");
		}
	}
}


void peek()
{
	if(head==NULL)
	{
		printf("Underflow\n");
	}
	
	else
	{
		node=head;
		printf("Details of the first car are - \n");
		printf("%s %d %.2f\n",node->name,node->model,node->price);
	}
}


void display()
{
	if(head==NULL)
	{
		printf("Underflow\n");
	}
	
	else
	{
		node=head;
		while(node!=NULL)
		{
			printf("%s %d %.2f\n",node->name,node->model,node->price);
			node=node->next;
		}
	}
}
