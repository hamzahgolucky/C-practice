#include <stdio.h>

int main()
{
	int c;
	for (c = ' '; c <= '~'; c = c+1)
	{
		printf("%c %d\n",c,c);
	}
	return 0;
}
