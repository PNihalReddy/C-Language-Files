#include <stdio.h>

int main()
{
	int n1,n2;
	printf("Enter number of elements of array 1:\n");
	scanf("%d",&n1);
	
	int i,a[n1];
	printf("Enter array 1 elements:\n");
	for(i=0;i<=n1-1;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enter number of elements of array 2:\n");
	scanf("%d",&n2);
	
	int b[n2];
	printf("Enter array 2 elements:\n");
	for(i=0;i<=n2-1;i++)
	{
		scanf("%d",&b[i]);
	}
	
	int s1=0,s2=0,s3=0;
	for(i=0;i<=n1-1;i++)
	{
		s1=s1+a[i];
	}
	
	for(i=0;i<=n2-1;i++)
	{
		s2=s2+b[i];
	}
	
	s3=s1+s2;
	printf("The sum of both array elements is : %d\n",s3);
	
}
