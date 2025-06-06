#include <stdio.h>
#include <ctype.h>

double stack[32];
int depth = 0;

void push(double d)
{
	stack[depth] = d;
	depth++;
}

double pop(void)
{
	depth--;
	return stack[depth];
}

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

