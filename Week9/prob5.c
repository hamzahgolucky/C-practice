#include <stdio.h>

#define MAX(x, y) x > y ? x : y 

int strlength(char *s) 
{
	char *temp = s;
	while (*s != '\0')
	{
		s++;
	}
	return (s-temp);
}

int strmax(char *s, char *t)
{
	return MAX(strlength(s), strlength(t));
}

int main()
{
    printf("%d\n", strmax("", ""));
    printf("%d\n", strmax("", "abc"));
    printf("%d\n", strmax("abc", ""));
    printf("%d\n", strmax("abc", "abc"));
    printf("%d\n", strmax("abcdef", "abc"));
    printf("%d\n", strmax("abc", "abcdefghi"));
    return 0;
}

