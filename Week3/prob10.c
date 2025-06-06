#include <stdio.h>

#define FALSE  0  // not in a word
#define TRUE   1  // in a word

int main()
{
    int c, d, state;

    
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
        	if ( c == '\n' ) 
        	{
        		putchar(c);
        		state = FALSE;
            		while ( state == FALSE )
            		{
            			if ((d = getchar()) != '\n') { state = TRUE; putchar(d); }
            		}
        	}
        	else if ( c == '\t' || c == ' ' )
        	{
        		putchar(' ');
        		state = FALSE;
        		while (state == FALSE)
        		{
        			if ((d = getchar()) != '\t' && d != ' ') { state = TRUE; putchar(d); }
        		}
        	}
        }
        else { putchar(c); }
        
    }

    return 0;
}

