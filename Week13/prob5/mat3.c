#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Mat3 {
	double r1[3];
	double r2[3];
	double r3[3];
};

typedef struct Mat3 Mat3;

void Mat3_print(Mat3 M) {
	for (int i=0;i<=2;i++) {
		printf("%5f\t", M.r1[i]);
	}
	printf("\n");
	for (int i=0;i<=2;i++) {
		printf("%5f\t", M.r2[i]);
	}
	printf("\n");
	for (int i=0;i<=2;i++) {
		printf("%5f\t", M.r3[i]);
	}
	printf("\n");
}

void Mat3_mulMat3(Mat3 A, Mat3 B, Mat3 *P) {
	for (int i = 0; i < 3; i++) {
        	P->r1[i] = A.r1[0] * B.r1[i] + A.r1[1] * B.r2[i] + A.r1[2] * B.r3[i];
        	P->r2[i] = A.r2[0] * B.r1[i] + A.r2[1] * B.r2[i] + A.r2[2] * B.r3[i];
        	P->r3[i] = A.r3[0] * B.r1[i] + A.r3[1] * B.r2[i] + A.r3[2] * B.r3[i];
    	}
}

int main() {
	Mat3 A = {{2, 1, 5}, {2, 10, 5}, {3, 1, 4}};
    Mat3 B = {{8, 7, 1}, {4, 2, 7}, {2, 3, 5}};
    Mat3 P;
    Mat3_mulMat3(A, B, &P);
    Mat3_print(P);
}
