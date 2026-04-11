#include <stdio.h>
int main(){
	int n,m;
	printf("Enter the value of m:");
	scanf("%d",&m);
	if(m==0){
		n=0;
	}
	if(m>0){
		n=1;
	}
	if(m<0){
		n=-1;
	}
	printf("The value of n is %d",n);
}
