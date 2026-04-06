#include <stdio.h>


void input_array(int a[],int n);
void output_array(int a[],int n);
int split_array(int a[],int li,int ri);
void quick_sort(int a[],int li,int ri);


int main()
{
	int n;
	printf("Enter array size:\n");
	scanf("%d",&n);
	
	int a[n];
	input_array(a,n);
	
	printf("The array before sorting is - \n");
	output_array(a,n);
	
	printf("The array after sorting is - \n");
	quick_sort(a,0,n-1);	
	output_array(a,n);
}


void input_array(int a[],int n)
{
	int i;
	printf("Enter %d elements into the array\n");
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


int split_array(int a[],int li,int ri)
{
	int i,j,pivot,temp;
	i=li,j=ri+1,pivot=a[li];
	
	while(i<j)
	{
		do
		{
			i++;
		}while(a[i]<pivot);
		
		do
		{
			j--;
		}while(a[j]>pivot);
		
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	
	temp=a[li];
	a[li]=a[j];
	a[j]=temp;
	return j;
}


void quick_sort(int a[],int li,int ri)
{
	int j;
	if(li<ri)
	{
		j=split_array(a,li,ri);
		quick_sort(a,li,j-1);
		quick_sort(a,j+1,ri);
	}
}
