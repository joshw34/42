#include <stdio.h>

/* array = a data structure that can store many values of the same data type */

int main(){

	/* Each value in the array is given a value beginning with 0 */

	//double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0};
   
	double prices[5];

	prices[0] = 5.0;
	prices[1] = 10.0;
	prices[2] = 15.0;
	prices[3] = 25.0;
	prices[4] = 20.0;

	printf("$%.2lf", prices[0]); /* This will print $5.00 */
	
	return 0;
}
