/* WAP in c to design a DFA 
	+
    ++
    +=
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
		printf("\n+ --- <Addition>");
	}
	if(count ==1 && equal ==1)
	{
		printf("\n+= --- <Plus Equal to>");
	}
	if(count ==2 && equal ==0)
	{
		printf("\n++ --- <Increment>");
	}
}

int main()
{
	int i = 0;
	char store[15];
    
	printf("\nEnter: ");
	scanf("%[^\n]", store);
	
	while(store[i] != '\0')
	{
		if( store[i] == '+' && count < 3)
		    count++;
		
        if( store[i] != '+' && store[i] != '=')
		{
			check();
			
			count = 0;
			equal = 0;

		}
		
        if( store[i] == '=' && (count == 0 || count == 1))
			equal++;		

        i++;
        if(store[i] == '\0')
            check();
        		
	}
	
}
