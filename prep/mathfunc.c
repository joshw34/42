#include <stdio.h>
#include <math.h>

int main(){

	float A = sqrt(9);
	float B = pow(2, 4);
	int C = round(3.14);
	int D = ceil(3.14);
	int E = floor(3.14);
	float F = fabs(-100);
	float G = log(3);
	float H = sin(45);
	float I = cos(45);
	float J = tan(45);

	printf("The square root of 9 = %f\n", A);
	printf("2 to the power of 4 = %f\n", B);
	printf("3.14 rounded to the nearest whole number = %d\n", C);
	printf("3.14 rounded up = %d\n", D);
	printf("3.14 rounded down = %d\n", E);
	printf("The absolute value of -100 = %f\n", F);
	printf("The logarithm of 3 = %f\n", G);
	printf("sin(45) = %f\n", H);
	printf("cos(45) = %f\n", I);
	printf("tan(45) = %f\n", J);

	return 0;

}


