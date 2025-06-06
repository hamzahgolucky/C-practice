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


int main() 
{
	for(int i = 0; i < 40; ++i)
	{
		putchar(digitChar(i));
	}
	putchar('\n');

    return 0;
}
