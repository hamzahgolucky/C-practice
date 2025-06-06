#include <math.h>
#include <stdio.h>

float power(float x, float y)
{
float result = exp(y*log(x));
return result;
}

int main()
{
float i = 1;
while (i <= 4) { 
	float a = i, b = 0.5;
	float answer = power(a,b);
	printf("%0.2f\n", answer);
	i += 0.5;
}
return 0;
}
