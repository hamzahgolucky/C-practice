
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

char *revchars(char *s, char *t)
{
    char temp[100];
    int i = 0,j = 0,max=0;
    while (*(s+max) != *t) max++;
    for (i = 0, j = (max-1); i < j; i++,j--)
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
    printf("%s\n", revchars(a, a+strlength(a)));
    printf("%s\n", revchars(b, b+strlength(b)));
    printf("%s\n", revchars(c, c+strlength(c)));
    printf("%s\n", revchars(d, d+strlength(d)));
    printf("%s\n", revchars(s, s+strlength(s)));
    return 0;
}

