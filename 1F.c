#include <stdio.h>
int main(){
	int n,i,product=1;
	printf("Enter the last number:");
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		product=product*i;
	}
	printf("The product is %d",product);
}
