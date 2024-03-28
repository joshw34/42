#include <stdio.h>
#include <ctype.h>

int main(){

	for(int i = 'a'; i <= 'z'; i+=2){

		printf("%c ", toupper(i));
	}

	printf("\n");

	for(int i = 'b'; i <= 'z'; i+=2){

		printf("%c ", i);
	}

	return 0;

}
