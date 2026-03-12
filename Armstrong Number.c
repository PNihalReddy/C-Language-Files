#include <stdio.h>
#include <math.h>
int main(){
	int n,rev=0,rem,ndigits,org_num;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("Enter the number of digits:");
	scanf("%d",&ndigits);
	org_num=n;
	while(n!=0){
		rem=n%10;
		rev=rev+pow(rem,ndigits);
		n=n/10;
	}
	if(rev==org_num){
		printf("It is an armstrong number");
	}
	else{
		printf("It is not an armstrong number");
	}
}
