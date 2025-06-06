#include <stdio.h>

void printDigit(int i) 
{
	if (i >= 10) putchar(i+55);
	else putchar(i+48);
}

int main()
{
	int i;
	for (i=0; i<=20; i++)
	{
		printDigit(i);
		printf("\n");
	}
}
