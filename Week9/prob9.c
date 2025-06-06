#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int strlength(char *s) 
{
    char *temp = s;
    while (*s != '\0')
    {
        s++;
    }
    return (s - temp);
}

char *revchars(char *s, char *t)
{
    char temp[100];
    int i=0,j = 0,max=0;
    //printf("%s\n", s);
    while (*(s+max) != *t && isalpha(*(s+max))) max++;
    for (i = 0, j = (max-1); i < j; i++,j--)
    {
        *(temp+i) = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = *(temp+i);
    }
    //printf("%s\n", s);
    return s;
}

char *revwords(char *s)
{
	int temp=0;
	char word[100];
	char a[100] = " ";
	char b[100] = "\0";
	int i = 0;
	while (*(s+(++i)) != '\0')
	{
		if (*(s+i) == ' ') {
		revchars(s+temp,s+i);
		temp = (i+1);
		}
	}
	revchars(s+temp,b);
	return s;
}

int main()
{
    char s[100] = "retep repip dekcip a kcep fo delkcip reppep";
    printf("%s\n", revwords(s));
    return 0;
}

