#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct String
{
	char *chars;
	int size;
};

int main(int argc, char **argv)
{
	struct String s = { strdup("hello"), 5 };
	printf("\"%.*s\"\n", s.size, s.chars);
	return 0;
}
