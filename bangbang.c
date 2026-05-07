#include <stdio.h>

int power(int a,int b);

int main(){
	int a,b,f;
	printf("Enter the two numbers:\n");
	scanf("%d %d",&a,&b);
	f=power(a,b);
	printf("The power of %d wrt to %d is :  %d",a,b,f);
	
}

int power(int a,int b){
	if(b==0){
		return 1;
	}
	else{
		return a*power(a,b-1);
	}
}
