#include <stdio.h>

int main()
{
	int c;
	while (EOF != (c = getchar()))
	{
		if (c=='\n')
		{
			printf("\\n");
		}
		else if (c == '\t')
		{
			printf("\\t");
		}
		else { putchar(c); }
	}
	return 0;
}
