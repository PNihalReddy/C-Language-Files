#include <stdio.h>
int main(){
	int n,r=0;
	printf("Enter ticket number:");
	scanf("%d",&n);
	r=n%10;
	if(r%3==0 || r%6==0 || r%9==0){
		printf("Lucky Winner");
	}
	else{
		printf("Not a Lucky Winner");
	}
	
}
