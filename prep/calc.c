#include <stdio.h>

int main(){

	double first;
	char operator;
	double second;

	printf("Enter 1st number:  ");
	scanf("%lf", &first);

	getchar();
	printf("Choose an operation (+ - * /):  ");
	scanf("%c", &operator);

	printf("Enter 2nd number:  ");
	scanf("%lf", &second);

	if(operator == '+'){
		printf("\n%lf %c %lf = %lf", first, operator, second, first+second);
	}
	else if(operator == '-'){
		printf("\n%lf %c %lf = %lf", first, operator, second, first-second);
	}
	else if(operator == '*'){
		printf("\n%lf %c %lf = %lf", first, operator, second, first*second);
	}
	else if(operator == '/'){
		printf("\n%lf %c %lf = %lf", first, operator, second, first/second);
	}
	return 0;

}
