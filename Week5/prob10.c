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

void squeezeAll(char s[], char t[])
{
	int i = 0;
	int j = 0;
	int c = 0;
	while (t[i] != '\0')
	{
		while ((c=charIndex(s,t[i])) != -1)
		{
			while (s[c+j] != '\0')
			{
				s[c+j] = s[c+j+1];
				j++;
			}
			j=0;
		}
		++i;
	}
}

int main()
{
	char s[] = "Hello world, how are you?";
	squeezeAll(s,"aeiou");
	printf("%s\n",s);
	squeezeAll(s," ,");
	printf("%s\n",s);
	squeezeAll(s,"Hld");
	printf("%s\n",s);
	return 0;
}
