#include <stdio.h>

int is_prime(int n);

void two_prime(int a,int b);

int main(){
	int a,b;
	printf("Enter the two numbers\n");
	scanf("%d %d",&a,&b);
	
	two_prime(a,b);
	
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

void two_prime(int a,int b){
	int i;
	for(i=a;i<=b;i++){
		if(is_prime(i)){
			printf("%d\n",i);
		}
	}
}
