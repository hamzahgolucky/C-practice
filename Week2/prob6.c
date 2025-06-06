#include <stdio.h>
#define LINEMAX 100

int reverse(char line[], int len)
{
	int i, temp;
	for (i=0;i<=((len-2)/2);i++)
	{
		temp = line[i];
		line[i] = line[(len-2)-i];
		line[(len-2)-i] = temp;
		//printf("i = %d and line looks like %s\n",i,line);
	}
}

int main()
{
	int c;
	int tru=0;
	int i=0;
	char line[LINEMAX];
	while (tru == 0) 
	{
		if ((c=getchar()) == '\n' || c == EOF)
		{
		tru = 1;
		}
		else { line[i] = c; i++; }
		if (c=='\n') { 
		line[i] = '\n';
		line[i++]='\0';
		reverse(line,i);
		printf("%s\n",line);
		i=0;
		tru = 0;
		}
	}
	return 0;
}


