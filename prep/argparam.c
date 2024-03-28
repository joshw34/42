#include <stdio.h>
#include <string.h>

void birthday(char name[25], int age){
	printf("\nHappy Birthday %s!",  name);
	printf("\n\nYou are %d years old!\n", age);
}

int main(){
	char name[25];
	int age;

	printf("\nWhat is your name?  ");
	fgets(name, 25, stdin);
	name[strlen(name)-1] = '\0';
	printf("\nHow old are you?  ");
	scanf("%d", &age);

	birthday(name, age);

	return 0;

}
