#include <stdio.h>
int main(){
	int n,r,org_num,rev;
	printf("Enter the number:");
	scanf("%d",&n);
	org_num=n;
	while(n!=0){
		r=n%10;
		rev=rev*10+r;
		n=n/10;
	}
	if(rev==org_num){
		printf("The number is palindrome");
	}
	else{
		printf("The number is not palindrome");
	}
}
