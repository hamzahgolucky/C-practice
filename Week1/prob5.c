#include <stdio.h>

int main()
{
float fahr, celsius;
int lower, upper, step;
lower = 0;
upper = 100;
step = 10;
celsius=lower;
while (celsius <= upper) {
fahr = (celsius * 9 / 5) + 32;
printf("%6.1f %6.1f\n",celsius,fahr);
celsius = celsius+step;
}
return 0;
}
