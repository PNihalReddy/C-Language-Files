#include <stdio.h>
#include <stdlib.h>

struct student
{
	int id;
	char name[20],course[20];
	float fee;
	struct student *link;
}
*head=NULL,*node=NULL;

void create();
void display();


int main()
{
	create();
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
