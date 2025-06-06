#include <stdio.h>

int getBits(unsigned int i, int p, int n)
{
	i = i >> p;
	i &= ((1 << n) - 1);
	return i;
}

int main()
{
	unsigned int i = 0b10110011100011110000111110000011;
	printf("%u\n", getBits(i,0,8));
	printf("%u\n", getBits(i,16,8));
	printf("%u\n", getBits(i,28,4));
	return 0;
}
