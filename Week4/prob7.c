#include <stdio.h>

int digitValue(int c, int b)
{
	if ((c < '0' || c > '9') && (c < 'a' || c > 'a'+b-11) && (c < 'A' || c > 'A'+b-11)) return (-1);
	else
{
	if (c >= '0' && c <= '9') return (c-'0');
	if (c >= 'a' && c <= 'z') return (c-'a'+10);
	if (c >= 'A' && c <= 'Z') return (c-'A'+10);
}
}

int main()
{
	int i;
	while ((i=getchar())!=EOF)
	{
		printf("%d\n",digitValue(i,16));
	}
}
