#include <stdio.h>

void input_array(int a[],int n);
void output_array(int a[],int n);
void min_selection_sort(int a[],int n);

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
	min_selection_sort(a,n);
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


void min_selection_sort(int a[],int n)
{
	int i,j,min,min_index;
	for(j=0;j<=n-1;j++)
	{
		min=a[j];
		min_index=j;
		for(i=j;i<=n-1;i++)
		{
			if(a[i]<min)
			{
				min=a[i];
				min_index=i;
			}
		}
		a[min_index]=a[j];
		a[j]=min;
	}
}
