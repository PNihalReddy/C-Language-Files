#include <stdio.h>

int perfect(int n);

int main(){
	int n,Z;
	printf("Enter the number:\n");
	scanf("%d",&n);
	Z=perfect(n);
	if(Z==1){
		printf("The number %d is a perfect number\n",n);
	}
	else{
		printf("The number %d is not a perfect number\n",n);
	}
}

int perfect(int n){
	int i,sum=0;
	for(i=1;i<n;i++){
		if(n%i==0){
			sum=sum+i;
		}
	}
	if(sum==n){
		return 1;
	}
	else{
		return 0;
	}
}
