/*  

    A program to read a stream of characters from the keyboard and spit out identifiers

*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>


int isAlpha(char x);
int isUnderscore(char x);
int isPoint(char x);
int isDigit(char x);
int isStops(char x);
int isKeyword(char buffer[]);
int isNumber(char buffer[]);
int isFractional(char buffer[]);
int isIdentifier(char buffer[]);

int main()
{
    char stream[1000], buffer[30], ch;
    int answer;
    int i = 0, k = 0;
    // stream = (char *)malloc(1000 * sizeof(char));
    
    printf("Enter : ");
    scanf("%[^\n]", stream);

    while (1)
    {
        ch = stream[i];
        i++;

        if (ch == '\0')
        {
            break;
        }

        if (!isStops(ch))
        {
            buffer[k++] = ch;
        }
        else if (k != 0)
        {
            buffer[k] = '\0';
            k = 0;

            if (isKeyword(buffer) == 0)
            {
                printf("\n%s : ", buffer);
                printf("<INT_KEYW>");
            }
            else if (isKeyword(buffer) == 1)
            {
                printf("\n%s : ", buffer);
                printf("<CHAR_KEYW>");
            }
            else if (isNumber(buffer) == 1)
            {
                printf("\n%s : ", buffer);
                printf("<INT_NUM>");
            }
            else if (isFractional(buffer) == 1)
            {
                printf("\n%s : ", buffer);
                printf("<FRACT_NUM>");
            }
            else if (isIdentifier(buffer) == 1)
            {
                printf("\n%s : ", buffer);
                printf("<IDENTIFIER>");
            }
        }
    }
}

int isAlpha(char x)
{

    if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
    {
        return 1;
    }
    return 0;
}

int isPoint(char x)
{
    if (x == '.')
    {
        return 1;
    }
    return 0;
}

int isDigit(char x)
{
    if (x >= '0' && x <= '9')
    {
        return 1;
    }
    return 0;
}

int isUnderscore(char x)
{
    if (x == '_')
    {
        return 1;
    }
    return 0;
}

int isStops(char x)
{
    if (isDigit(x) || isAlpha(x) || isPoint(x) || isUnderscore(x) || x=='\'')
    {
        return 0;
    }
    return 1;
}

int isKeyword(char buffer[])
{
    char keywords[2][5] = {"int", "char"};

    int i, keyword = 99;

    for (i = 0; i < 2; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            keyword = i;
            break;
        }
    }

    return keyword;
}

int isNumber(char buffer[])
{
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (isAlpha(buffer[i]) || isPoint(buffer[i]) || isUnderscore(buffer[i]))
        {
            return 0;
        }
    }
    return 1;
}

int isFractional(char buffer[])
{
    int pointCount = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if ( isAlpha(buffer[i]) || isUnderscore(buffer[i]) )
        {
            return 0;
        }
        else if (isPoint(buffer[i]))
        {
            pointCount++;
            if (pointCount > 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int isIdentifier(char buffer[])
{
    if (!isAlpha(buffer[0]) && !isUnderscore(buffer[0]))
    {
        return 0;
    }
    return 1;
}