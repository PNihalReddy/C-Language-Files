#include <stdio.h>
int main(){
	int n,i,rem=0,rem_digits=0,sum=0;
	printf("Enter the number:");
	scanf("%d",&n);
	while(n!=0){
		rem=n%10;
		rem_digits=rem_digits+rem;
		n=n/10;
	}
	sum=rem_digits;
	switch(sum){
		case 1:
		case 2:
		case 3:
			printf("The prize money is 10 lakhs");
			break;
		case 4:
		case 5:
		case 6:
			printf("The prize money is 5 lakhs");
			break;
		case 7:
		case 8:
		case 9:
			printf("The prize money is 2 lakhs");
			break;
		default:
			printf("No Result");
	}
}
