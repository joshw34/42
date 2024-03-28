#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main(){

	double left;
	double right;
	char operand;

	printf("\nChoose an operation:\nAddition: +\nSubtraction: -\nMultiplication: *\nDivision /\nSquare Root: s\nLogarithm: l\n\n");
	scanf("%c", &operand);

	if(operand == '+' || operand == '-' || operand == '*' || operand == '/'){
		printf("\nEnter first number: ");
		scanf("%lf", &left);
		printf("\nEnter second number:  ");
		scanf("%lf", &right);

		if(operand == '+'){
			printf("\n%lf %c %lf = %lf\n", left, operand, right, left+right);
			getchar();
		}
		else if(operand == '-'){
			printf("\n%lf %c %lf = %lf\n", left, operand, right, left-right);
		}
		else if(operand == '*'){
			printf("\n%lf %c %lf = %lf\n", left, operand, right, left*right);
		}
		else if(operand == '/'){
			printf("\n%lf %c %lf = %lf\n", left, operand, right, left/right);
		}
	}
	
	else if(operand == 's'){
		printf("\nEnter number:  ");
		scanf("%lf", &left);
		printf("\nThe square root of %lf is: %lf\n", left, sqrt(left));
	}
	
	else if(operand == 'l'){
		printf("\nEnter number:  ");
		scanf("%lf", &left);
		printf("\nThe natural logarithm of %lf is: %lf\n", left, log(left));
	}


	return 0;

}
