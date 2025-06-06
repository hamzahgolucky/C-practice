#include <stdio.h>

int getBits(unsigned int i, int p, int n)
{
	i = i >> p;
	i &= (1 << n)-1;
	return i;
}

int clearBits(unsigned int i, int p, int n)
{
	i &= ~(getBits(i,p,n) << p);
	return i;
}

int setBits(unsigned int i, int p, int n, int b)
{
	i = clearBits(i,p,n);
	b &= (1<<n)-1;
	b = b << p;
	i |= b;
	return i;
	
}

int main()
{
	unsigned int i = 0b10110011100011110000111110000011;
	printf("%u\n", i = setBits(i,2,30,1));
	printf("%u\n", i = setBits(i,6,2,7));
	printf("%u\n", i = setBits(i,2,4,15));
	return 0;
}
