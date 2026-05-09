#include <stdio.h>
#include <string.h>

int main()
{
	char s[20],t[20];
	printf("Enter the sentence:\n");
	scanf(" %[^\n]s",s);
	
	printf("Enter the word:\n");
	scanf(" %[^\n]s",t);
	
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(strstr(&s[i],t)==&s[i])
		{
			count++;
		}
	}
	
	printf("The word %s occurs %d times in the sentence:\n",t,count);
}
