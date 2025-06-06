#include <stdio.h>

int countBits(unsigned int n)
{
	int count = 0;
	while (n != 0)
	{
		count += n & 1;
		n = n>>1;
	}
}

int main()
{
	for (int i =0; i<=15; ++i)
		printf("%d\n", countBits(i));
	return 0;
}
