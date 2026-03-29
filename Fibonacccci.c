#include <stdio.h>
int fibc(int n1,int n2,int n);

int main(){
	int n,n1=0,n2=1,f;
	printf("Enter the limit of the series:\n");
	scanf("%d",&n);
	printf("%d	%d	",n1,n2);
	fibc(n1,n2,n);

}

int fibc(int n1,int n2,int n){
	int n3;
	if(n1+n2<=n){
		n3=n1+n2;
		printf("%d	",n3);
		fibc(n2,n3,n);
	}
	
}
