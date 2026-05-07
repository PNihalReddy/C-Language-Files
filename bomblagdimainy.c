#include <stdio.h>

int fibon(int n);

int main(){
	int n,f;
	printf("Enter the number:\n");
	scanf("%d",&n);
	f=fibon(n);
	printf("The fibonacci series upto number %d is %d",n,f);
}

int fibon(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return fibon(n-1)+fibon(n-2);
	}
}
