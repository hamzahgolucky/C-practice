#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) {
	if (argc > 2 || argc < 2) {
		printf("usage: ./pi n-points\n");
		exit(1);
	}
	int N = atoi(argv[1]);
	int incount=0;
	for (int i=0;i<=N;i++) {
		double x = ((rand() % 200) / 100.0) ;
		double y = ((rand() % 200) / 100.0);
		if (sqrt((x-1)*(x-1) + (y-1)*(y-1))<=1) incount++;
	}
	printf("%d out of %d points inside the circle\npi is approximately %0.8f\n", incount, N, ((4.0*incount)/N));
	return 0;
}
