//WAP to read a text file and count the number of characters, words and lines.



#include<stdio.h>
#include<string.h>


int main()
{
	FILE *fp;

	fp = fopen("text.txt" ,"r");

	int characterCount =0;

	int lineCount = 0;

	int wordCount = 0;

	char ch = getc(fp);

	while( ch != EOF)
	{
		if(ch != '\n')
			characterCount++;
		if(ch == ' ' || ch =='\n')
			wordCount++;
		if(ch == '\n')
			lineCount++;

		ch = getc(fp);
	}

	printf("\nNumber of characters = %d", characterCount);
	printf("\nNumber of words = %d", (wordCount-1)); //minus one for EOF
	printf("\nNumber of lines = %d \n", (lineCount-1)); //minus one for EOF
}
