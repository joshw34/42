#include <stdio.h>
#include <string.h>

int main(){
	
	/* Similar to 2darray - each string is an array of characters.
	   The first [] refers to the max # elements (strings) allowed. Can be blank.
	   The second [] refers to the max size of each element (string) */
	char cars[][10] = {"Mustang","Corvette","Camaro","BMW","Ferrari","Bugatti"};

	/* A value can not be directly changed in an array of strings as shown below: */
	//cars[0] = "Tesla";
	
	/* We must use the string copy 'strcpy()' function from <string.h>
	   Here we copy 'Tesla' in place of 'Mustang' */
	strcpy(cars[0], "Tesla");

	printf("Size of array = %d bytes\n", sizeof(cars));
	
	printf("# of strings = %d\n", sizeof(cars)/sizeof(cars[0]));

	
	/* The # of values = size of 'cars' array divided by size of 1 value */
	
	for(int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++){
		printf("%s\n", cars[i]);
	}

	return 0;

}
