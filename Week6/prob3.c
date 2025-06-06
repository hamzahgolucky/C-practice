#include <stdio.h>

int digitChar(int d)
{
	switch(d)
	{
		case 0 ... 9: return d+48;
		case 10 ... 35: return d+55;
		default: return '?';
	}
}

int iprint(int i)
{
	do 
	{
		putchar(digitChar(i%10));
		i = ((i-i%10)/10);
	} while (i);
	printf("\n");
}

int main(int argc, char *argv[]) 
{
	iprint(    0);
	iprint(    1);
	iprint(   42);
	iprint(65535);

    return 0;
}
