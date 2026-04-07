#include <stdio.h>

int is_prime(int n);

int main(){
	int n,Z;
	printf("Enter the number\n");
	scanf("%d",&n);
	
	Z=is_prime(n);
	if(Z==1){
		printf("The number is a prime number\n");
	}
	else{
		printf("The number is not a prime number\n");
	}
}

int is_prime(int n){
	int i;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
