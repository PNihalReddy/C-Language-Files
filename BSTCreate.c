#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int data;
	struct BST *left,*right;
}*root=NULL,*newnode=NULL;

void create_tree();
void pre_order(struct BST *node);
void in_order(struct BST *node);
void post_order(struct BST *node);


int main()
{
	create_tree();
	printf("Data of BST Using Pre-Order Traversal\n");
	pre_order(root);
	
	printf("Data of BST Using In-Order Traversal\n");
	in_order(root);
	
	printf("Data of BST Using Post-Order Traversal\n");
	post_order(root);	
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


void pre_order(struct BST *node)
{
	if(node!=NULL)
	{
		printf("%d\n",node->data);
		pre_order(node->left);
		pre_order(node->right);
	}
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


void post_order(struct BST *node)
{
	if(node!=NULL)
	{
		post_order(node->left);
		post_order(node->right);
		printf("%d\n",node->data);
	}
}
