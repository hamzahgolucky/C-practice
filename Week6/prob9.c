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

int itosnbwp(int i, char s[], int n, int b, int w, int p)
{
	int m = 0;
	
	do 
	{
		if (!n) break;
		s[m] = digitChar(i%b);
		m++;
		i = ((i-i%b)/b);
	} while (i && m<(n-1));
	while (m<w) {s[m] = p; m++;}
	reverse(s, (m-1));
	s[m] = '\0';
	
	return m;
}

int main(int argc, char *argv[]) 
{
	char s[1024];
	
	itosnbwp(    0, s, 1024, 2, 4, ' '); printf("%s\n", s);
	itosnbwp(    1, s, 1024, 2, 4, '0'); printf("%s\n", s);
	itosnbwp(   42, s, 1024, 2, 4, ' '); printf("%s\n", s);
	itosnbwp(   42, s, 1024, 8, 4, ' '); printf("%s\n", s);
	itosnbwp(   42, s, 1024,10, 4, '0'); printf("%s\n", s);
	itosnbwp(65535, s, 1024,16, 4, '0'); printf("%s\n", s);

    return 0;
}
