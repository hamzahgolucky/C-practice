#include <stdio.h>

void printDigit(int i) 
{
	if (i >= 10) putchar(i+55);
	else putchar(i+48);
}

void printNumber(int i) 
{
	if (i >= 16) printNumber(i/16);
	printDigit(i % 16);
}

int main()
{
	int i;
	for (i=0; i<=20; i++)
	{
		printNumber(i);
		printf("\n");
	}
}
