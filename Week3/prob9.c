#include <stdio.h>

#define OUTSIDE  0  // not in a word
#define INSIDE   1  // in a word

int main()
{
    int c, state;
    int wount = 0;
    int lount = 0;
    int count = 0;

    state = OUTSIDE;

    while ((c = getchar()) != EOF) {
    count++;
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUTSIDE;
            if (c == '\n') { lount++; }
        }
        else {
            if (state == OUTSIDE) {
            	wount++;
                state = INSIDE;
            }
        }
    }
    printf("%d words, %d characters, %d lines\n", wount, count, lount);

    return 0;
}

