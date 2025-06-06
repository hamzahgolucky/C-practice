#include <stdio.h>

void squeeze(char s[], int c)
{
	int i = 0;
	int j = 0;
	while (s[i] != '\0')
	{
		if (s[i+j] != '\0')
		{
			while (s[i+j] != '\0')
			{
				s[i+j] = s[i+j+1];
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
	squeezeAll(s,'o');
	printf("%s\n",s);
	return 0;
}
