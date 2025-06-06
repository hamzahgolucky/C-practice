#include <stdio.h>

int charIndex(char s[], int c)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return i;
		}
		++i;
	}
	return -1;
}

int main()
{
	char s[] = "Hello world, how are you?";
	printf("%d\n",charIndex(s,'H'));
	printf("%d\n",charIndex(s,'w'));
	printf("%d\n",charIndex(s,'?'));
	printf("%d\n",charIndex(s,'q'));
	printf("%d\n",charIndex(s,'\0'));
	return 0;
}
