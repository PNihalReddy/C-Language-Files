#include <stdio.h>
#include <stdlib.h>

struct canteen
{
	int s_id,serve_time;
	char item[30];
	struct canteen *next;
}*head=NULL,*node=NULL,*newnode=NULL,*delnode=NULL;

void enqueue();
void dequeue();
void peep();
void display();


int main()
{
	int opt;
	char ch;
	do
	{
		printf("QUEUE OPERATIONS\n");
		printf("1.ENQUEUE 2.DEQUEUE 3.PEEP 4.DISPLAY\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: enqueue();break;
			case 2: dequeue();break;
			case 3: peep();break;
			case 4: display();break;
			default:
				printf("Invalid Choice\n");
		}
		printf("Enter your choice:\n");
		scanf("%s",&ch);
	}while(ch=='y');
}



void enqueue()
{
	newnode=(struct canteen*)malloc(sizeof(struct canteen));
	printf("Enter the details:\n");
	scanf("%d %s %d",&newnode->s_id,&newnode->item,&newnode->serve_time);
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
	}
	
	else
	{
		node=head;
		while(node->next!=NULL)
		{
			node=node->next;
		}
		node->next=newnode;
	}
}


void dequeue()
{
	if(head==NULL)
	{
		printf("Queue Underflow\n");
	}
	
	else
	{
		delnode=head;
		head=head->next;
		printf("Deleted details are - \n");
		printf("%d %s %d\n",delnode->s_id,delnode->item,delnode->serve_time);
		free(delnode);
		delnode=NULL;
	}
}


void peep()
{
	int found=0;
	if(head==NULL)
	{
		printf("Queue Underflow\n");
	}
	
	else
	{
		int id;
		printf("Enter id to be searched for:\n");
		scanf("%d",&id);
		
		node=head;
		while(node!=NULL)
		{
			if(id==node->s_id)
			{
				found=1;
				break;
			}
			node=node->next;
		}
	}
	
	if(found)
	{
		printf("Searched details are - \n");
		printf("%d %s %d\n",node->s_id,node->item,node->serve_time);
	}
	
	else
	{
		printf("Details not found\n");
	}
}


void display()
{
	if(head==NULL)
	{
		printf("Queue Underflow\n");
	}
	
	else
	{
		node=head;
		while(node!=NULL)
		{
			printf("%d %s %d\n",node->s_id,node->item,node->serve_time);
			node=node->next;
		}
	}
}
