#include <stdio.h>
int main(){
	int i=1,n,sum=0;
	printf("Enter the number:");
	scanf("%d",&n);
	for(i;i<=n;i=i+1){
		sum=sum+i;
	}
	printf("The sum is:%d \n",sum);
	
	return 0;
}
