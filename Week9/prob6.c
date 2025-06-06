#include <stdio.h>

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

void swapstrings(char *c, char *d)
{
    char temp[100];
    int i;

    int max = MAX(strlength(c), strlength(d));
    for (i = 0; i <= max; i++)
    {
        *(temp+i) = *(d+i);
        *(d+i) = *(c+i);
        *(c+i) = *(temp+i);
    }
}

int main()
{
    char s[100] = "the first string";
    char t[100] = "another string, a bit longer";
    printf("%s\n%s\n", s, t);
    swapstrings(s,t);
    printf("%s\n%s\n", s, t);
    return 0;
}

