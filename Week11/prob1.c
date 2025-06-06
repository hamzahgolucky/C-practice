#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Point
{
	double x, y;
};

struct Point Point_newXY(double x, double y)
{
	struct Point a = { x, y };
	return a;
}

int main(int argc, char **argv)
{
	struct Point p = Point_newXY(3.0,4.0);
	printf("%f,%f", p.x, p.y);
	putchar('\n');
	return 0;
}
