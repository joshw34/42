#include <stdio.h>
#include <ctype.h>

int main(){

	char unit;
	float temp;

	printf("Is the temperature in Celsius(C), Fahrenheit(F) or Kelvin?  ");
	scanf("%c", &unit);

	unit = toupper(unit);

	switch(unit){
		case 'C':
			printf("\nWhat is the temperature in Celsius?  ");
			scanf("%f", &temp);
			printf("\nThe temperature in Fahrenheit is %.2f\n", (temp * 9/5) + 32);
			printf("\nThe temperature in Kelvin is %.2f\n", temp + 273.15);
			break;
		case 'F':
			printf("\nWhat is the temperature in Fahrenheit?  ");
			scanf("%f", &temp);
			printf("\nThe temperature in Celsius is %.2f\n", (temp - 32) * 5/9);
			printf("\nThe temperature in Kelvin is %.2f\n", ((temp - 32) * 5/9) + 273.15);
			break;
		case 'K':
			printf("\nWhat is the temperature in Kelvin?  ");
			scanf("%f", &temp);
			printf("\nThe temperature in Celsius is %.2f\n", temp - 273.15);
			printf("\nThe temperature in Fahrenheit is %.2f\n", ((temp - 273.15) * 9/5) + 32);
			break;
		default:
			printf("\n%c is not a valid input\n", unit);
			getchar();
			main();
			//break;
	}

	return 0;

}

