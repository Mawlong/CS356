/* WAP in c to design a DFA 
	>>
	>=
	>
	>>=
*/

//sample input: a<<b a<=b a<b a<<=b

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count = 0;
int equal = 0;


void check()
{
	if(count == 1 && equal == 0)
	{
		printf("\n> --- <Greater>\n");
	}
	if(count ==1 && equal ==1)
	{
		printf(">= --- <Greater than or Equal>\n");
	}
	if(count ==2 && equal ==0)
	{
		printf(">> --- <Right Shift>\n");
	}
	if(count ==2 && equal ==1)
	{
		printf(">>= --- <Right Shift Assign>\n");
	}
}

int main()
{
	
	int i = 0;
	char store[15];

	printf("\nEner: ");
	scanf("%[^\n]", store);
	
	while(store[i] != '\0')
	{
		if( store[i] == '>' && count < 3)
			count++;
			
		if( store[i] != '>' && store[i] != '=')
		{
			check();
			
			count = 0;
			equal = 0;
				
		}

		if( store[i] == '=' && (count == 1 || count == 2))
			equal++;

		i++;
        if(store[i] == '\0')
            check();
		
	}
	
}
