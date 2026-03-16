#include <stdio.h>
int remainder(int x,int y);
int main(){
	int x,y;
	printf("Enter the bigger number and then the number to divide with:\n");
	scanf("%d %d",&x,&y);
	printf("The remainder is:%d\n",remainder(x,y));
}

int remainder(int x,int y){
	int c;
	c=x%y;
	return c;
}
