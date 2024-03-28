#include <stdio.h>
#include <string.h>

/* while loop = repeats a section of code possibly unlimited times.
   WHILE some condition remains true
   a while loop might not execute at all */

int main(){

	char name[25];

	printf("\nWhat's your name?: ");
	fgets(name, 25, stdin);
	name[strlen(name) - 1] = '\0';

	while(strlen(name) == 0){
		printf("\nYou did not enter your name\n");
		printf("\nWhat's your name?: ");
		fgets(name, 25, stdin);
		name[strlen(name) - 1] = '\0';
	}

	printf("Hello %s", name);

	return 0;

}
