#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc == 1 || argc > 2) {
	printf("enter one number as an argument");
	exit(1);}
	if (atoi(argv[1]) <= 0) {
	printf("enter number greater than 0");
	exit(1);} 
	int N = atoi(argv[1]);
	int P[N];
	int i = -1;
	while(i++ != N) P[i] = 1;
	
	for (i=2;i<=N;i++) {
		if (P[i]) {
			for (int j=2;(j*i)<=N;j++) P[j*i] = 0;
		}
	}
	
	for (i=2;i<=N;i++) {
		if (P[i]) printf("%d\n", i);
	}
	return 0;
}
