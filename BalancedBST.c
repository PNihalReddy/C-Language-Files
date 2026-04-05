#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int data;
	struct BST *left,*right;
}*root=NULL,*newnode=NULL,*node=NULL;

void create_tree();
void in_order(struct BST *node);
int find_height(struct BST *node);
int is_balanced(struct BST *node);


int main()
{
	create_tree();
		
	printf("Data of BST Using In-Order Traversal\n");
	in_order(root);
	
	printf("The height of the tree is : %d\n",find_height(root));
	
	if(is_balanced(root))
	{
		printf("The BST is balanced\n");		
	}
	else
	{
		printf("The BST is not balanced\n");
	}
}


void create_tree()
{
	char ch;
	do
	{
		newnode=(struct BST*)malloc(sizeof(struct BST));
		printf("Enter any value:\n");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		
		struct BST *node,*parent=NULL;
		
		if(root==NULL)
		{
			root=newnode;
		}
		
		else
		{
			node=root;
			while(node!=NULL)
			{
				parent=node;
				
				if(newnode->data<node->data)
				{
					node=node->left;
				}
				
				else
				{
					node=node->right;
				}
			}
			
			if(newnode->data<parent->data)
			{
				parent->left=newnode;
			}
			else
			{
				parent->right=newnode;
			}
		}		
		printf("Enter y to continue:\n");
		scanf(" %c",&ch);
	}while(ch=='y');
}



void in_order(struct BST *node)
{
	if(node!=NULL)
	{
		in_order(node->left);
		printf("%d\n",node->data);
		in_order(node->right);
	}
}


int find_height(struct BST * node)
{
	if(node==NULL)
	{
		return -1;
	}
	int LSTH,RSTH;
	LSTH=find_height(node->left);
	RSTH=find_height(node->right);
	
	if(LSTH>RSTH)
	{
		return 1+LSTH;
	}
	else
	{
		return 1+RSTH;
	}
}


int is_balanced(struct BST *node)
{
	if(node==NULL)
	{
		return 1;
	}	
	
	int LH,RH,BF;
	LH=find_height(node->left);
	RH=find_height(node->right);
	BF=LH-RH;
	
	if(BF==0 || BF==-1 || BF==1)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
} 
