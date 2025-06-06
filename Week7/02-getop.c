#include <stdio.h>
#include <ctype.h>

// define number and getop() here

int main()
{
    for (;;) {
	int c = getop();
	switch (c) {
	    case -1:	printf("EOF\n");			return 0;
	    case  0:	printf("newline\n");			break;
	    case '0':	printf("%g\n", number);			break;
	    default:	printf("unknown operator '%c'\n", c);	break;
	}
    }
    return 0;
}
