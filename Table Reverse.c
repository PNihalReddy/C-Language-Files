#include <stdio.h>
int main(){
	int i=10,n;
	printf("Enter the number n:");
	scanf("%d",&n);
	for(i;i>=1;i=i-1){
		printf("%d \n",n*i);
	}
	return 0;
}
