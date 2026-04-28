#include <stdio.h>

int prime(int n);

int main(){
	int n,Z;
	printf("Enter the number:\n");
	scanf("%d",&n);
	Z=prime(n);
	if(Z==0){
		printf("The number is prime\n");
	}
	else{
		printf("The number is consonant\n");
	}
	
}

int prime(int n){
	int i;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			return 1;
		}
	}
	return 0;
}
