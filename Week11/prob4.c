#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

struct Point Point_printXY(struct Point p)
{
	printf("%f,%f", point_x(p), point_y(p));
}

double Point_r(struct Point p)
{
	double val = sqrt(point_x(p)*point_x(p)+point_y(p)*point_y(p));
	return val;
}

int main(int argc, char **argv)
{
	struct Point p = Point_newXY(3,4);
	Point_printXY(p);
	putchar('\n');
	printf("%f\n", Point_r(p));
	return 0;
}
