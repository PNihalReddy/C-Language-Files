#include <stdio.h>
#include <stdlib.h>

struct student
{
	int id;
	char name[20],course[20];
	float fee;
	struct student *link;
}
*head=NULL,*np1=NULL,*np2=NULL,*temp=NULL,*node=NULL;

void create();
void display();
void reverse();


int main()
{
	create();
	printf("Data before sorting - \n");
	display();
	reverse();
	printf("Data after sorting - \n");
	display();
}

void create()
{
	int i,n;
	printf("Enter number of students:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		struct student *newnode=(struct student*)malloc(sizeof(struct student));
		printf("Enter student data");
		scanf("%d %s %s %f",&newnode->id,&newnode->name,&newnode->course,&newnode->fee);
		newnode->link=NULL;
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			node=head;
			while(node->link!=NULL)
			{
				node=node->link;
			}
			node->link=newnode;
		}
	}
}

void display()
{
	struct student *newnode;
	node=head;
	while(node!=NULL)
	{
		printf("%d %s %s %.2f\n",node->id,node->name,node->course,node->fee);
		node=node->link;
	}
}


void reverse()
{
	np1=head,np2=NULL,temp=NULL;
	while(np1!=NULL)
	{
		np2=np1;
		np1=np1->link;
		np2->link=temp;
		temp=np2;
	}
	head=temp;
}
