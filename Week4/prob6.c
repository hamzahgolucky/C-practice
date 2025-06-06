#include <stdio.h>

int digitValue(int c)
{
	if (c < '0' || c > '9') return (-1);
	else return (c-'0');
}

int main()
{
	int i;
	for (i='/';i<=':';i++)
	{
		printf("%d\n",digitValue(i));
	}
}
