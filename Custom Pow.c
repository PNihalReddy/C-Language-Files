#include <stdio.h>
#include <math.h>
int main(){
	int n,degree,res;
	printf("First enter number then power:");
	scanf("%d %d",&n,&degree);
	res=pow(n,degree);
	printf("The result is:%d",res);
}
