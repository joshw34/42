#include <stdio.h>

int main(){
	
	/* The values to be swapped 'x & y' are declared and initialised with a temporary
	   variable 'temp' for storage */

	char x = 'X';
	char y = 'Y';
	char temp;

	temp = x;
	x = y;
	y = temp;

	printf("x = %c\n", x);
	printf("y = %c\n", y);

	return 0;

}
