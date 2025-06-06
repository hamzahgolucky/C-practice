#include <stdio.h>
#define LINEMAX 100

int main()
{
	int c;
	int tru=0;
	int i=0;
	int count=0;
	char line[LINEMAX];
	while (tru == 0) 
	{
		if ((c=getchar()) == '\n' || c == EOF)
		{
		tru = 1;
		}
		else { line[i] = c; i++; count++; }
		if (c=='\n' && count > 79) { line[i] = '\n'; line[i++]='\0';count++; printf("%d\t%s\n",count,line); i=0; tru = 0; count = 0; }
		else if (c=='\n') { i=0; tru = 0; count = 0; }
	}
	return 0;
}


