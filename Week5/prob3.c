#include <stdio.h>

int clearBit(unsigned int i, int p)
{
	i &= ~(1 << p);
	return i;
}

int main()
{
	unsigned int i = 62;
	printf("%u\n", i = clearBit(i,0));
	printf("%u\n", i = clearBit(i,2));
	printf("%u\n", i = clearBit(i,4));
	return 0;
}
