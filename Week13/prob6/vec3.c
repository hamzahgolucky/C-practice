#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Mat3 {
	double r1[3];
	double r2[3];
	double r3[3];
};

struct Vec3 {
	double r1[3];
};

typedef struct Mat3 Mat3;
typedef struct Vec3 Vec3;

void Mat3_print(Mat3 M) {
	printf("{");
	for (int i=0;i<=2;i++) {
		printf("%5f,\t", M.r1[i]);
	}
	printf("\n");
	for (int i=0;i<=2;i++) {
		printf("%5f,\t", M.r2[i]);
	}
	printf("\n");
	for (int i=0;i<=2;i++) {
		printf("%5f,\t", M.r3[i]);
	}
	printf("}\n");
}

void Vec3_print(Vec3 M) {
	printf("{");
	for (int i=0;i<=2;i++) {
		
		printf("%5f,\t", M.r1[i]);
	}
	printf("}\n");
}

void Mat3_mulMat3(Mat3 A, Mat3 B, Mat3 *P) {
	for (int i = 0; i < 3; i++) {
        	P->r1[i] = A.r1[0] * B.r1[i] + A.r1[1] * B.r2[i] + A.r1[2] * B.r3[i];
        	P->r2[i] = A.r2[0] * B.r1[i] + A.r2[1] * B.r2[i] + A.r2[2] * B.r3[i];
        	P->r3[i] = A.r3[0] * B.r1[i] + A.r3[1] * B.r2[i] + A.r3[2] * B.r3[i];
    	}
}

void Mat3_mulVec3(Mat3 A, Vec3 B, Vec3 *P) {
        P->r1[0] = A.r1[0] * B.r1[0] + A.r1[1] * B.r1[1] + A.r1[2] * B.r1[2];
        P->r1[1] = A.r2[0] * B.r1[0] + A.r2[1] * B.r1[1] + A.r2[2] * B.r1[2];
        P->r1[2] = A.r3[0] * B.r1[0] + A.r3[1] * B.r1[1] + A.r3[2] * B.r1[2];
}

int main() {
	Vec3 V = {3,4,1};
	Vec3_print(V);
	
	Mat3 S = {{3,0,0},{0,2,0},{0,0,1}};
	Vec3 SV;
	Mat3_mulVec3(S,V,&SV);
	Vec3_print(SV);
	
	Mat3 T = {{1,0,5},{0,1,7},{0,0,1}};
	Vec3 TV;
	Mat3_mulVec3(T,V,&TV);
	Vec3_print(TV);
	
	Mat3 TS;
	Mat3_mulMat3(T,S,&TS);
	Vec3 TSV;
	Mat3_mulVec3(TS,V,&TSV);
	Vec3_print(TSV);
}
