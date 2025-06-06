#include <stdio.h>

int digitValue(int c, int b)
{
	if ((c < '0' || c > '0'+b-1) && (c < 'a' || c > 'a'+b-11) && (c < 'A' || c > 'A'+b-11)) return (-1);
	else
{
	if (c >= '0' && c <= '9') return (c-'0');
	if (c >= 'a' && c <= 'z') return (c-'a'+10);
	if (c >= 'A' && c <= 'Z') return (c-'A'+10);
}
}

int strtoi(char s[], int b)
{
	int j,power;
	int sum = 0;
	int i = 0;
	int k = 0;
	while (s[i]!='\0')
	{
		k++;
		i++;
	}
	i=0;
	k--;
	while (i<=k)
	{
		if (digitValue(s[k-i],b)!=-1)
		{
			//printf("%d\n",digitValue(s[k-i],b));
			power = 1;
			for (j=0;j<i;j++)
			{
				power = power*b;
			}
			sum = sum + power*digitValue(s[k-i],b);
			//printf("%d\n",sum);
			//printf("%d\n",i);
			i++;
		}
		else k--;
	}
	return sum;
}

int main()
{
	printf("%d\n",strtoi("1010",2));
	printf("%d\n",strtoi("1010",8));
	printf("%d\n",strtoi("1010",10));
	printf("%d\n",strtoi("1010",16));
	printf("%d\n",strtoi("2A",16));
	printf("%d\n",strtoi("1012",2));
	printf("%d\n",strtoi("1789",8));
	printf("%d\n",strtoi("101A",10));
	printf("%d\n",strtoi("2FGH",16));
}
