#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int idk = 0;
	if (argc == 2)
	{
		idk = atoi(*(argv+1));
	}
	else if (argc > 2) {printf("too many arguments\n"); goto exit;}
	else idk = 10;
	printf("%d\n", idk);
	exit:
	return 0;
}
