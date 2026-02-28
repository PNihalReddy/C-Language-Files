#include <stdio.h>

void input_array(int a[],int n);
void output_array(int a[],int n);
void shell_sort(int a[],int n);

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
	
	shell_sort(a,n);
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

void shell_sort(int a[],int n)
{
	int i,j,gap,key;
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			key=a[i];
			j=i-gap;
			while(j>=0 && key<a[j])
			{
				a[j+gap]=a[j];
				j=j-gap;
			}
			a[j+gap]=key;
		}
	}
}
