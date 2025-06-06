#include <stdio.h>

int digitChar(int d)
{
	switch(d)
	{
		case 0 ... 9: return d+48;
		case 10 ... 35: return d+55;
		default: return '?';
	}
}

int itor(int i, char s[])
{
	int n = 0;
	do 
	{
		s[n] = digitChar(i%10);
		n++;
		i = ((i-i%10)/10);
	} while (i);
	s[n] = '\0';
	return n;
}

int main(int argc, char *argv[]) 
{
	char s[1024];
	
	itor(    0, s); printf("%s\n", s);
	itor(    1, s); printf("%s\n", s);
	itor(   42, s); printf("%s\n", s);
	itor(65535, s); printf("%s\n", s);

    return 0;
}
