#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(){

	char operator;
	float num1;
	float num2;

	operator = tolower(operator);

	printf("Choose an operation:\nAddition (+)\nSubtraction (-)\nMultiplication (*)\nDivision (/)\nSquare Root (s)\nLogarithm (l)\n\n");
	scanf("%c", &operator);

	if(operator == '+' || operator == '-' || operator == '*' || operator == '/'){
		printf("\nEnter first number:  ");
		scanf("%f", &num1);
		printf("\nEnter second number:  ");
		scanf("%f", &num2);
		switch(operator){
			case '+':
				printf("\nAnswer:  %f", num1+num2);
				break;
			case '-':
				printf("\nAnswer:  %f", num1-num2);
				break;
			case '*':
				printf("\nAnswer:  %f", num1*num2);
				break;
			case '/':
				printf("\nAnswer:  %f", num1/num2);
				break;
		}
	}

	else if(operator == 's' || operator == 'l'){
		printf("\nEnter number:  ");
		scanf("%f", &num1);
		switch(operator){
			case 's':
				printf("\nAnswer:  %f", sqrt(num1));
				break;
			case 'l':
				printf("\nAnswer:  %f", log(num1));
				break;
		}
	}

	else{
		printf("\n\"%c\" is not a valid operation", operator);
	}


	return 0;

}

