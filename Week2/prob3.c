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
	int count = 0;
	while (a <= 100000)
	{
		if (isPrime(a) == 1)
		{
		printf("%d\n", a);
		count++;
		}
		a++;
	}
	printf("number of prime numbers is precisely %d\n",count);
	return 0;
}
