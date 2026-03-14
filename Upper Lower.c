#include <stdio.h>
int main()
{
	char chr1;
	printf("Enter your character:");
	scanf("%c",&chr1);
	if(chr1>='a' && chr1<='z'){
		printf("Character is lower");
	}
	else if(chr1>='A' && chr1<='Z'){
		printf("Character is upper");
	}
	return 0;
}

