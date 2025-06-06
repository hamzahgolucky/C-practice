#include <stdio.h>

int strlength(char *s) 
{
	int n = 0;
	while (*(s+n) != '\0')
	{
		n++;
	}
	return n;
}

int main()
{
    printf("%d\n", strlength("hello, world")); // 12
    char s[] = "hello, world";
    printf("%d\n", strlength(s));              // 12
    char *p = s;
    printf("%d\n", strlength(p));              // 12
    return 0;
}

