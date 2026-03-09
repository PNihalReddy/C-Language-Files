#include <stdio.h>
int main(){
	int i,j,k;
	for(i=1;i<=5;i=i+1){
		for(j=i;j<5;j=j+1){
			printf(" ");
		}
		for(k=1;k<=i;k=k+1){
			printf("*");
		}
		printf("\n");
	}
}
