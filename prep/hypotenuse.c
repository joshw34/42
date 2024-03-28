#include <stdio.h>
#include <math.h>

int main(){

	double a;
	double b;
	double c;

	printf("What is the length of 'a'?  ");
	scanf("%lf", &a);
	
	printf("What is the length of 'b'?  ");
	scanf("%lf", &b);

	c = sqrt(pow(a,2)+pow(b,2));

	printf("\nThe hypotenuse is: %lf\n", c);

	return 0;

}



