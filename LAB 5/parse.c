#include<stdio.h>
#include<stdlib.h>
char token=0,input[50];
int i;
void f_s();
void f_ss();
void f_A();
void f_AA();
char nextToken();
int main()
{
	i=0;
	printf("Enter the string\n");
	scanf("%s",input);
	token=nextToken();
	f_s();
	if(token=='$')
	printf("Success\n");
	else
	printf("Fail\n");

}

void f_s()
{
	if(token=='a')
	{
		token=nextToken();
		f_ss();
		if(token=='c')
		token=nextToken();
	}
	else
	{
		printf("error2\n");
		exit(0);
	}
}
void f_ss()
{
	if(token=='a')
	{
		token=nextToken();
		f_ss();
		if(token=='c')
		token=nextToken();
		else
		{
			printf("error3\n");
			exit(0);
		}
	}
	else if(token=='b')
	{
		f_A();
	}
	else
	{
		printf("error4\n");
		exit(0);
	}
}
void f_A()
{
	if(token=='b')
	{
		token=nextToken();
		f_AA();
	}
	
	else
	{
		printf("error5\n");
		exit(0);
	}
}
void f_AA()
{
	if(token=='b')
	{
		f_A();
		if (token=='c')
		token=nextToken();

		
	}
	else if(token=='c')
	{
		token=nextToken();
		
	}
	
	else
	{
		printf("error6\n");
		exit(0);
	}
}

char nextToken()
{
	return input[i++];
}
		
