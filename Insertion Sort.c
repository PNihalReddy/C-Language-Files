#include <stdio.h>

void input_array(int a[],int n);
void output_array(int a[],int n);
void insertion_sort(int a[],int n);

int main()
{
	int n;
	printf("Enter array size:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d elements into array - \n",n);
	input_array(a,n);
	
	printf("The original array is - \n");
	output_array(a,n);
	
	insertion_sort(a,n);
	printf("The array after sorting is - \n");
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
		printf("%d  ",a[i]);
	}
}

void insertion_sort(int a[],int n)
{
	int j,It,key;
	for(It=1;It<=n-1;It++)
	{
		j=It-1;
		key=a[It];
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
