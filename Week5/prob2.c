#include <stdio.h>

int setBit(unsigned int i, int p)
{
	i |= (1 << p);
	return i;
}

int main()
{
	unsigned int i = 0;
	printf("%u\n", i = setBit(i,1));
	printf("%u\n", i = setBit(i,3));
	printf("%u\n", i = setBit(i,5));
	return 0;
}
