#include <stdio.h>
#include <string.h> /* Must be included for strcpy() */

int main(){

	/* 2 variables to be swapped and temp storage declared/initialised
	   */

	/* If the length of the second value is longer than the first, and no string sizes
	   are given: the larger value will swap but not the smaller */

	//char x[] = "water";
	//char y[] = "soda";
	//char temp[15];

	/* This can be fixed by making the second value the longest: */
	//char x[] = "water";
	//char y[] = "lemonade";
	//char temp[15];
	
	/* Or by assigning a string size to each value: */
	char x[15] = "water";
	char y[15] = "soda";
	char temp[15];
	
	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);

	printf("x = %s\n", x);
	printf("y = %s\n", y);
 
   return 0; 
}
