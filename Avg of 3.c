#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c,avg;
	printf("Enter the three numbers:\n");
	scanf("%d %d %d",&a,&b,&c);
	avg=(a+b+c)/3;
	printf("The average of these 3 numbers is:%d",avg);
	return 0;
}
