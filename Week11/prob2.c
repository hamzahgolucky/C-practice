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

double point_x(struct Point p)
{
	return p.x;
}

double point_y(struct Point p)
{
	return p.y;
}

int main(int argc, char **argv)
{
	struct Point p = Point_newXY(3.0,4.0);
	printf("%f,%f", point_x(p), point_y(p));
	putchar('\n');
	return 0;
}
