#include <stdio.h>

void input_array(int a[],int n);
void output_array(int a[],int n);
void sortdigit(int a[],int n);


int main()
{
	int n;
	printf("Enter array size:\n");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter %d array elements:\n");
	input_array(a,n);
	
	printf("The array before sorting is - \n");
	output_array(a,n);
	
	printf("The array after digit sorting is - \n");
	sortdigit(a,n);
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
		printf("%d	",a[i]);
	}
}


void sortdigit(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((a[j]%10>a[j+1]%10))
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
