#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct dictionary
{
	char word[100],meaning[1000];
	struct dictionary *link;
}*head=NULL,*node=NULL,*delnode=NULL,*newnode=NULL;

typedef struct dictionary dict;

void create()
{
	int n,i;
	printf("Number of words in dictionary");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(dict *)malloc(sizeof(dict));
		printf("enter %d word and meaning",i);
		scanf("%s %s",newnode->word,newnode->meaning);
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
	dict *w2=NULL,*w1=NULL;
	char tempword[100],tempmeaning[1000];
	w1=head;
	while(w1->link!=NULL)
	{
	  w2=w1->link;
	  while(w2->link!=NULL)	
	  {
	  	if(strcmp(w1->word,w2->word) > 0)
	  	{
	  	  strcpy(tempword,w1->word);
	  	  strcpy(tempmeaning,w1->meaning);
	  	  strcpy(w1->word,w2->word);
		  strcpy(w1->meaning,w2->meaning);
		  strcpy(w2->word,tempword);
		  strcpy(w2->meaning,tempmeaning);
	    }
	    w2=w2->link;
	  }
	  w1=w1->link;
	}	
}


void createstore()
{
	newnode=(dict *)malloc(sizeof(dict));
	printf("enter word and meaning");
	scanf("%s %s",newnode->word,newnode->meaning);
	newnode->link=NULL;
}


void add_word()
{
	createstore();
	if(head==NULL)
	{
		head=newnode;
	}
	else if(strcmp(newnode->word,head->word) < 0)
	{
		newnode->link=head;
		head=newnode;
	}
	else
	{
		node=head;
		while(node->link!=NULL && strcmp(newnode->word,node->link->word) > 0)
		{
			node=node->link;
		}
		newnode->link=node->link;
		node->link=newnode;
	}
}

void search()
{
	char searchingword[100];
	printf("Enter word to find its meaning");
	scanf("%s",searchingword);
	if(head==NULL)
	{
		printf("No word in the linked list");
	}
	else
	{
		node=head;
		while(node!=NULL)
		{
			if(strcmp(searchingword,node->word) == 0)
			{
				printf("word = %s \t: Meaning = %s\n",node->word,node->meaning);
		        return;
			}
			node=node->link;
		}
		printf("Word not found in linkedlist\n");
	}
}

int count_words()
{
	int c=0;
	node=head;
	while(node!=NULL)
	{
		c++;
		node=node->link;
	}
	return c;
}

void delete_word()
{
	char delword[100];
	printf("enter word to delete:\n");
	scanf("%s",delword);
	if(head==NULL)
	{
		printf("No words in dictionary\n");
	}
	else if(head->link==NULL  && strcmp(delword,head->word) == 0)
	{
		delnode=head;
		head=NULL;
		free(delnode);
		delnode=NULL;
	}
	else
	{
		node=head;
		if(strcmp(delword,node->word)==0)
		{
			delnode=node;
			head=node->link;
			free(delnode);
			delnode=NULL;		
		}
		
		while(node->link!=NULL)
		{
			if(strcmp(delword,node->link->word) == 0)
			{
				delnode=node->link;
				node->link=node->link->link;
				free(delnode);
				delnode=NULL;
			}
			node=node->link;
			
		}
	}
}

void display()
{
	for(node=head;node!=NULL;node=node->link)
	{
		printf("word = %s \t: Meaning = %s\n",node->word,node->meaning);
	}
}
void main()
{
	create();
	int selection;
	char choice;
	do
{
	printf("enter your selection:\n 1.Add a new word \n 2.search for meaning \n 3.counting no. of words \n 4. deleting word from dictionary\n 5.display\n");
	scanf("%d",&selection);
	switch(selection)
	{
		case 1: add_word(); break;
		case 2: search(); break;
		case 3: printf("The total words are %d\n",count_words());break;
		case 4: delete_word(); break;
		case 5: display();break;
		default : printf("Invalid option\n");
	}
	printf("enter Y or y to repeat\n");
	scanf(" %c",choice);
}while( choice=='Y' || choice=='y');
}
