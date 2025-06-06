#include <stdio.h>

int main()
{
    int c;
    int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while ((c = getchar()) != EOF) {
        if ('0' <= c && c <= '9') { ++d[c-'0']; }
    }

	int i = 0;
	for (i = 0; i <= 9; i = i+1)
	{
		printf("%d %d ",i,d[i]);
		int a;
		for (a = 1; a <= d[i]; a = a+1)
		{
			putchar('*');
		}
		printf("\n");
	}
    
    return 0;
}

