#include <stdio.h>
#include <stdlib.h>

void create_store();
void add_first();
void add_last();
void add_middle();
void delete_first();
void delete_last();
void delete_middle();
void display();
int count_nodes();
int is_empty();

struct student
{
	int id;
	char name[30],course[10];
	float fee;
	struct student *link;
}*head=NULL,*node=NULL,*newnode=NULL,*delnode=NULL;


int main()
{
	int opt;
	char ch;
	do
	{
		printf("OPTIONS\n");
		printf("1.Add First 2.Add Middle 3.Add Last 4.Delete First 5.Delete Middle 6.Delete Last 7.Display 8.Count of Nodes\n");
		printf("Enter your option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: add_first();break;
			case 2: add_middle();break;
			case 3: add_last();break;
			case 4: delete_first();break;
			case 5: delete_middle();break;
			case 6: delete_last();break;
			case 7: display();break;
			case 8: printf("The number of nodes is - %d\n",count_nodes());
				break;
			
			default:
				printf("Invalid Option\n");
				break;
		}
		printf("Enter y to repeat:\n");
		scanf("%s",&ch);
		
	}while(ch=='y');
	
	
}


void create_store()
{
	newnode=(struct student*)malloc(sizeof(struct student));
	printf("Enter student details:\n");
	scanf("%d %s %s %f",&newnode->id,&newnode->name,&newnode->course,&newnode->fee);
	newnode->link=NULL;
}


int is_empty()
{
	if(head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int count_nodes()
{
	int count=0;
	if(!is_empty())
	{
		node=head;
		while(node!=NULL)
		{
			node=node->link;
			count++;
		}
	}
	return count;
}


void add_first()
{
	create_store();
	if(!is_empty())
	{
		newnode->link=head;
	}
	head=newnode;
}


void add_middle()
{
	int i,c,pos;
	printf("Enter node position:\n");
	scanf("%d",&pos);
	c=count_nodes();
	
	if(pos==1)
	{
		add_first();
	}
	
	else if(pos<=c+1)
	{
		create_store();
		node=head;
		for(i=1;i<pos-1;i++)
		{
			node=node->link;
		}
		newnode->link=node->link;
		node->link=newnode;
	}
}


void add_last()
{
	create_store();
	if(is_empty())
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


void delete_first()
{
	if(is_empty())
	{
		printf("Linked list is empty:\n");
	}
	
	else
	{
		delnode=head;
		head=head->link;
		printf("Deleted record data is - \n");
		printf("%d %s %s %.2f\n",delnode->id,delnode->name,delnode->course,delnode->fee);
		free(delnode);
		delnode=NULL;
	}
}


void delete_middle()
{
	int i,c,pos;
	
	if(is_empty())
	{
		printf("Linked list is empty\n");
	}
	
	else
	{
		printf("Enter the position where you want to delete:\n");
		scanf("%d",&pos);
		c=count_nodes();
		
		if(pos<=0 || pos>c)
		{
			printf("Invalid Position\n");
		}
		
		else
		{
			node=head;
			for(i=1;i<pos-1;i++)
			{
				node=node->link;
			}
			delnode=node->link;
			node->link=delnode->link;
			printf("The deleted record is - \n");
			printf("%d %s %s %.2f\n",delnode->id,delnode->name,delnode->course,delnode->fee);
			free(delnode);
			delnode=NULL;
		}
	}
}


void delete_last()
{
	if(is_empty())
	{
		printf("Linked list is empty\n");
	}
	
	else
	{
		node=head;
		while(node->link->link!=NULL)
		{
			node=node->link;
		}
		delnode=node->link;
		node->link=NULL;
		printf("Deleted record data is - \n");
		printf("%d %s %s %.2f\n",delnode->id,delnode->name,delnode->course,delnode->fee);
		free(delnode);
		delnode=NULL;
	}
}


void display()
{
	node=head;
	while(node!=NULL)
	{
		printf("%d %s %s %.2f\n",node->id,node->name,node->course,node->fee);
		node=node->link;
	}
}
