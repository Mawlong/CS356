%option noyywrap

%%
a(a|b)+a	{printf("\nvalid");}
.*		{printf("\nInvalid");}	

%%
main()
{
	yylex();
}
