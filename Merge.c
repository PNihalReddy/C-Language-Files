#include <stdio.h>


void input_array(int a[],int n);
void output_array(int a[],int n);
void merge_sort(int a[],int li,int ri);
void merge(int a[],int li,int mi,int ri);


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
	merge_sort(a,0,n-1);	
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

void merge_sort(int a[],int li,int ri)
{
	int mi=(li+ri/2);
	if(li<ri)
	{
		merge_sort(a,li,mi);
		merge_sort(a,mi+1,ri);
		merge(a,li,mi,ri);
	}
}

void merge(int a[],int li,int mi,int ri)
{
	int i,j,k=0,n1,n2;
	n1=mi-li+1;
	n2=ri-mi;
	
	int la[n1];
	int ra[n2];
	
	for(i=0;i<n1;i++)
	{
		la[i]=a[li+i];
	}
	
	for(j=0;j<n2;j++)
	{
		ra[j]=a[mi+1+j];
	}
	
	i=0,j=0,k=li;
	
	while(i<n1 && j<n2)
	{
		if(la[i]<ra[j])
		{
			a[k++]=la[i++];
		}
		
		else
		{
			a[k++]=ra[j++];
		}
	}
	
	while(i<n1)
	{
		a[k++]=la[i++];
	}
	
	while(j<n2)
	{
		a[k++]=ra[j++];
	}
}
