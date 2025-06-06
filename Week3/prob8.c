#include <stdio.h>

#define OUTSIDE  0  // not in a word
#define INSIDE   1  // in a word

int main()
{
    int c, state;
    int wount = 0;

    state = OUTSIDE;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUTSIDE;
        }
        else {
            if (state == OUTSIDE) {
            	wount++;
                state = INSIDE;
            }
        }
    }
    printf("%d words", wount);

    return 0;
}

