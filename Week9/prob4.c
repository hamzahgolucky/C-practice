#include <stdio.h>

char *strappend(char *s, char *t) 
{
	int n = 0;
	while (*(s+n) != '\0')
	{
		n++;
	}
	int slen = n;
	n = 0;
	do
	{
		*(s+slen+n) = *(t+n);
	}
	while (*(t+n++) != '\0');
	return s;
}

int main()
{
    char s[100] = "append ", *t = "me!";
    printf("%s\n", strappend(s, t));
    return 0;
}

