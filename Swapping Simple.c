#include <stdio.h>
int main(){
	int n1,n2,temp=0;
	printf("Enter the two numbers:");
	scanf("%d %d",&n1,&n2);
	printf("The numbers before swapping are %d and %d",n1,n2);
	
	temp=n1;
	n1=n2;
	n2=temp;
	printf("The numbers after swapping are %d and %d",n1,n2);
	
	
}
