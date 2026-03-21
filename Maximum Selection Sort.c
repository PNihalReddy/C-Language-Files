#include <stdio.h>

void input_array(int a[],int n);
void output_array(int a[],int n);
void max_selection_sort(int a[],int n);

void main()
{
	int n;
	printf("Enter array size:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d array elements:\n");
	input_array(a,n);
	
	printf("The array before sorting is - \n");
	output_array(a,n);
	
	printf("The array after sorting is - \n");
	max_selection_sort(a,n);
	output_array(a,n);
	
}


void input_array(int a[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
}


void output_array(int a[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}


void max_selection_sort(int a[],int n)
{
	int i,j,max,max_index;
	for(j=0;j<=n-1;j++)
	{
		max=a[j];
		max_index=j;
		for(i=j;i<=n-1;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				max_index=i;
			}
		}
		a[max_index]=a[j];
		a[j]=max;
	}
}
