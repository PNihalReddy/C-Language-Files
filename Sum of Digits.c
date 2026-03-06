#include <stdio.h>
int main(){
	int n,digit,sum=0;
	printf("Enter the number:");
	scanf("%d",&n);
	while(n!=0){
		digit=n%10;
		sum=sum+digit;
		n=n/10;
	}
	printf("The sum of the digits is:%d",sum);
}
