#include <stdio.h>

void printDigit(int i) 
{
	if (i >= 10) putchar(i+55);
	else putchar(i+48);
}

void printNumber(int i, int b) 
{
	if (i >= b) printNumber(i/b,b);
	printDigit(i % b);
}

int main()
{
	int i;
	for (i=2;i<21;i++)
	{
		printNumber(42,i);
		printf("\n");
	}
	
}
