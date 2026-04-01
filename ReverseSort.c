#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student
{
	int id;
	char name[20],course[20];
	float fee;
	struct student *link;
}
*head=NULL,*node=NULL,*np1=NULL,*np2=NULL,*temp=NULL,*newnode=NULL;

void create();
void display();
void reverse();
void l_sort();



int main()
{
	create();
	printf("The original linked list is - \n");
	display();
	
	printf("The reversed linked list is - \n");
	reverse();
	display();
	
	printf("The linked list after sorting is - \n");
	l_sort();
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


void l_sort()
{
	int t_id;
	char t_name[30],t_course[10];
	float t_fee;
	np1=head;
	while(np1->link!=NULL)
	{
		np2=np1->link;
		while(np2!=NULL)
		{
			if(np1->fee>np2->fee)
			{
				t_id=np1->id;
				strcpy(t_name,np1->name);
				strcpy(t_course,np1->course);
				t_fee=np1->fee;
				
				np1->id=np2->id;
				strcpy(np1->name,np2->name);
				strcpy(np1->course,np2->course);
				np1->fee=np2->fee;
				
				np2->id=t_id;
				strcpy(np2->name,t_name);
				strcpy(np2->course,t_course);
				np2->fee=t_fee;
			}
			np2=np2->link;
		}
		np1=np1->link;
	}
}
