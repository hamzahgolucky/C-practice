#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
int i = 2;
	while (i <= n/2) 
	{
		if (n%i == 0)
		{
		return 0;
		}
		else i++;
	}
	return 1;
}

int main()
{
	int a = 2;
	while (a <= 20)
	{
		if (isPrime(a) == 0)
		{
			printf("%d is not prime\n", a);
		}
		else printf("%d is prime\n", a);
		a++;
	}
	return 0;
}
