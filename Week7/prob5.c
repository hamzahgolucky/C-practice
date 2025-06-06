#include <stdio.h>
#include <ctype.h>

double stack[32];
int depth = 0;
double number = 0;


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

int getop(void)
{
	while (1)
	{
	int c = getchar();
	switch(c)
	{
		case (' '):
			break;
		case (EOF):
			return -1;
		case ('\n'):
			return 0;
		default:
			if (isdigit(c)) 
			{ number = (c-48);
			while (isdigit(c=getchar())) { number = number*10 + (c-48); }
			return '0';}
			else return c;
	}
	}
}

int main()
{
    for (;;) {
	int c = getop();
	switch (c) {
	    case -1:	printf("EOF\n");			return 0;
	    case  0:	while (depth>0) {
	    			printf("%g\n",stack[--depth]);
	    		}					break;
	    case '0':	push(number);				break;
	    case '+':	{
	    			int a = pop();
	    			int b = pop();
	    			push(b + a);
	    		} 					break;
	    case '-':	{
	    			int a = pop();
	    			int b = pop();
	    			push(b - a);
	    		} 					break;
	    case '*':	{
	    			int a = pop();
	    			int b = pop();
	    			push(b * a);
	    		} 					break;
	    case '/':	{
	    			int a = pop();
	    			int b = pop();
	    			push(b / a);
	    		} 					break;
	    default:	printf("unknown operator '%c'\n", c);	break;
	}
    }
    return 0;
}

