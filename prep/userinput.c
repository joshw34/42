#include<stdio.h>
#include<string.h>

int main(){

	char name[25]; //25 = number of bytes allowed for input
	int age;

	printf("What is your name?\n");
	fgets(name, 25, stdin);
	name[strlen(name)-1] = '\0'; //this removes the new line after the %s caused by fgets

	printf("How old are you?\n");
	scanf("%d", &age);

	printf("Hello %s, how are you?\n", name);
	printf("You are %d years old\n", age);

	return 0;

}


