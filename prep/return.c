#include <stdio.h>

/* In the main function: x is declared and then initialised by user input. The declared value is then used as an argument for the square function
   which subsequently provides the value indicated by the placeholder.

   In the square function: 'void' is replaced by double as the value we are returning is a double. Inside the brackets the value x declared in the
   main function is used as a parameter (this allows the square function to see avariable declared in the main function). Another double 'result'
   is initialised and then returned to the main function.*/

double square(double x){
	double result = x * x;
	return result;
}
	
int main(){
	//double x = square(3.14);
	double x;
	printf("Enter number:  ");
	scanf("%lf", &x);
	printf("Answer:  %.2lf\n", square(x));

	return 0;
}
