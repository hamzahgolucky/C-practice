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

struct String String_println(struct String *s)
{
	printf("\"%.*s\"\n", s->size, s->chars);
	return *s;
}

struct String *String_append(struct String *s, int c)
{
	s->chars = realloc(s->chars, s->size + 1);
	*(s->chars+s->size) = c;
	s->size += 1;
}

int main(int argc, char **argv)
{
	struct String s = String_new("hello");
	String_append(&s, '!');
	String_println(&s);
	return 0;
}
