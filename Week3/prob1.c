#include <stdio.h>
#define LOWER 0
#define UPPER 100
#define STEP 10
int main()
{
	float fahr, celsius;
	for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
	{
		fahr = 32 + celsius * 9/5;
		printf("%6.1f %6.1f\n", celsius, fahr);
	}
	return 0;
}

