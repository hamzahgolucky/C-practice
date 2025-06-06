#include <stdio.h>

// define stack[], depth, push(), and pop() here

int main()
{
    push(1.0);
    push(2.0);
    push(3.0);
    printf("%g\n", pop());
    printf("%g\n", pop());
    push(4.0);
    push(5.0);
    printf("%g\n", pop());
    printf("%g\n", pop());
    printf("%g\n", pop());
    return 0;
}
