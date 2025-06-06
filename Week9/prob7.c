
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

char *reverse(char *s)
{
    char temp[100];
    int i,j;
    for (i = 0, j = (strlength(s)-1); i < j; i++,j--)
    {
        *(temp+i) = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = *(temp+i);
    }
    return s;
}

int main()
{
    char a[100] = "";
    char b[100] = "b";
    char c[100] = "bc";
    char d[100] = "bcd";
    char s[100] = "peter piper picked a peck";
    printf("%s\n", reverse(a));
    printf("%s\n", reverse(b));
    printf("%s\n", reverse(c));
    printf("%s\n", reverse(d));
    printf("%s\n", reverse(s));
    return 0;
}

