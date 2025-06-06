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

int itosnbw(int i, char s[], int n, int b, int w) {itosnbwp(i,s,n,b,w,' ');}
int itosnb(int i, char s[], int n, int b) {itosnbw(i,s,n,b,0);}
int itosn(int i, char s[], int n) {itosnb(i,s,n,10);}
int itos(int i, char s[]) {itosn(i,s,1024);}
void iprint(int i) {
	char s[1024];
	itos(i,s);
	printf("%s\n",s);
	}

int main(int argc, char *argv[])
{
    char s[1024];

    iprint(    0);
    iprint(    1);
    iprint(   42);
    iprint(65535);

    itos(    0, s);  printf("%s\n", s);
    itos(    1, s);  printf("%s\n", s);
    itos(   42, s);  printf("%s\n", s);
    itos(65535, s);  printf("%s\n", s);

    itosn(    0, s, 4);  printf("%s\n", s);
    itosn(    1, s, 4);  printf("%s\n", s);
    itosn(   42, s, 4);  printf("%s\n", s);
    itosn(65535, s, 4);  printf("%s\n", s);

    itosnb(    0, s, 1024,  2);  printf("%s\n", s);
    itosnb(    1, s, 1024,  2);  printf("%s\n", s);
    itosnb(   42, s, 1024,  2);  printf("%s\n", s);
    itosnb(   42, s, 1024,  8);  printf("%s\n", s);
    itosnb(   42, s, 1024, 10);  printf("%s\n", s);
    itosnb(65535, s, 1024, 16);  printf("%s\n", s);

    itosnbw(    0, s, 1024,  2, 4);  printf("%s\n", s);
    itosnbw(    1, s, 1024,  2, 4);  printf("%s\n", s);
    itosnbw(   42, s, 1024,  2, 4);  printf("%s\n", s);
    itosnbw(   42, s, 1024,  8, 4);  printf("%s\n", s);
    itosnbw(   42, s, 1024, 10, 4);  printf("%s\n", s);
    itosnbw(65535, s, 1024, 16, 4);  printf("%s\n", s);

    itosnbwp(    0, s, 1024,  2, 4, ' ');  printf("%s\n", s);
    itosnbwp(    1, s, 1024,  2, 4, '0');  printf("%s\n", s);
    itosnbwp(   42, s, 1024,  2, 4, ' ');  printf("%s\n", s);
    itosnbwp(   42, s, 1024,  8, 4, ' ');  printf("%s\n", s);
    itosnbwp(   42, s, 1024, 10, 4, '0');  printf("%s\n", s);
    itosnbwp(65535, s, 1024, 16, 4, '0');  printf("%s\n", s);

    return 0;
}

