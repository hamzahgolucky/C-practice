#include <stdio.h>
#include <ctype.h>

double number = 0;

double getnum(void)
{
	double c;
	number = 0;
	while (isdigit(c=getchar())) number = number * 10 + c - '0';
	if (c == EOF) return -1;
	return 0;
}

int main() {
	while (getnum() != -1) printf("%g\n", number);
	return 0;
}
