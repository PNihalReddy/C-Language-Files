#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct msword
{
	char word[50];
	struct msword *link;
}*head=NULL,*node=NULL,*newnode=NULL,*delnode=NULL;

typedef struct msword ms;

void store()
{
	newnode=(ms *)malloc(sizeof(ms));
	printf("Enter a new word\n");
	scanf("%s",&newnode->word);
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->link=NULL;
	}
	else
	{
		newnode->link=head;
		head=newnode;
	}
}

void undo()
{
	if(head==NULL)
	{
		printf("No word to undo\n");
	}
	else
	{
		delnode=head;
		head=head->link;
		printf("Deleted word is %s\n",delnode->word);
		free(delnode);
		delnode=NULL;
	}
}

void display()
{
	if(head==NULL)
	{
		printf("No word to display\n");
	}
	else
	{
	node=head;
	while(node!=NULL)
	{
		printf("%s\n",node->word);
		node=node->link;
	}
}
}

void main()
{
	int choice;
	char ch;
	do
	{
	printf("1.storing\n 2.undo\n 3.display\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: store(); break;
		case 2: undo(); break;
		case 3: display();break;
		default:
		printf("Invalid choice");
	}
	printf("enter y or Y to continue\n");
	scanf(" %c",&ch);
}while(ch=='Y'||ch=='y');
	
	
}
