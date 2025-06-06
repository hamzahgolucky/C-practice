#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("%s\n", *(argv+1));
		int idk = atoi(*(argv+1));
		printf("%d\n", idk);
	}
	//printf("%p\n", (argv+1));
	//printf("%s\n", *(argv+1));
	//printf("%c\n", **(argv+1));
	return 0;
}
