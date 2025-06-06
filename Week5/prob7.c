#include <stdio.h>

void toLower(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'Z'))
		{
			s[i] = s[i] + 32;
		}
		++i;
	}
}

int main()
{
	char s[] = "Hello World How Are You?";
	toLower(s);
	printf("%s\n",s);
	return 0;
}
