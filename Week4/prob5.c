#include <stdio.h>

void printDigit(int i) 
{
	if (i >= 10) putchar(i+55);
	else putchar(i+48);
}

void printNumber(int i) 
{
	if (i < 0) {printf("-");i=-i;}
	
	if (i >= 16) printNumber(i/16);
	printDigit(i % 16);
}

int main()
{
	int i = -42;
	printNumber(i);
	printf("\n");
}
