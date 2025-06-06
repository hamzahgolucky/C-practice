#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct String
{
	char *chars;
	int size;
};

struct String String_new(char *s)
{
	struct String out = { strdup(s), strlen(s) };
	return out;
}

struct String String_println(struct String s)
{
	printf("\"%.*s\"\n", s.size, s.chars);
	return s;
}

int main(int argc, char **argv)
{
	struct String s = String_new("hello");
	String_println(s);
	return 0;
}
