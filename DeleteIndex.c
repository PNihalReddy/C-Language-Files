#include <stdio.h>

int main()
{
	char c;
	printf("Enter the alphabet:\n");
	scanf("%c",&c);
	
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("It is a vowel\n");
			break;
		
		default:
			printf("It is a consonant\n");
	}
}
