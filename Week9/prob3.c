#include <stdio.h>

char *strcopy(char *s, char *t) 
{
	int n = 0;
	do
	{
		*(s+n) = *(t+n);
	}
	while (*(t+n++) != '\0');
	return s;
}

int main()
{
    char s[100] = "overwrite", *t = "me!";
    printf("%s\n", strcopy(s, t));
    return 0;
}

