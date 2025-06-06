#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	while ((*argv) != 0)
	{
		
		printf("%s\n", *argv);
		*(argv++);
	}
	//printf("%p\n", (argv+1));
	//printf("%s\n", *(argv+1));
	//printf("%c\n", **(argv+1));
	return 0;
}
