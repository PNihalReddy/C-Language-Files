#include <stdio.h>

void separate(float n,int *p,float *q);

int main(){
	float n,y;
	int x;
	printf("Enter the number:\n");
	scanf("%f",&n);
	
	separate(n,&x,&y);
	printf("The integer value is %d\n",x);
	printf("The float value is %.2f",y);
	
}

void separate(float n,int *p,float *q){
	*p=(int)n;
	*q=(float)n-*p;
}
