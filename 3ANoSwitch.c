#include <stdio.h>
int main(){
	int n,rem,rem_digits=0,sum,i;
	printf("Enter the ticket number:");
	scanf("%d",&n);
	while(n!=0){
		rem=n%10;
		rem_digits=rem_digits+rem;
		n=n/10;
	}
	sum=rem_digits;
	if(sum>=1&&sum<=3){
		printf("The prize is 10 lakhs");
	}
	else if(sum>=4&&sum<=6){
		printf("The prize is 5 lakhs");
	}
	else if(sum>=7&&sum<=9){
		printf("The prize is 2 lakhs");
	}	
}
