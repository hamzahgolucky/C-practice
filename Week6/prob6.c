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

void reverse(char s[], int len)
{
	int c = 0;
	int i = 0;
	int j = len;
	for(i=0;i<j;i++,j--)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;
	}
	
}

int itos(int i, char s[], int n)
{
	int m = 0;
	
	do 
	{
		if (!n) break;
		s[m] = digitChar(i%10);
		m++;
		i = ((i-i%10)/10);
	} while (i && m<(n-1));
	reverse(s, (m-1));
	s[m] = '\0';
	
	return n;
}

int main(int argc, char *argv[]) 
{
	char s[1024];
	
	itos(    0, s, 4); printf("%s\n", s);
	itos(    1, s, 4); printf("%s\n", s);
	itos(   42, s, 4); printf("%s\n", s);
	itos(65535, s, 4); printf("%s\n", s);

    return 0;
}
