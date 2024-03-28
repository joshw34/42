#include <stdio.h>
#include <string.h>

/* struct = collection of related members ("variables") 
   they can be of different data types
   listed under one name in a block of memory
   VERY SIMILAR to classes in other languages (but no methods) */

/* Create a struct using keyword 'struct' and tagname 'Player'
   Variables are declared inside */

struct Player{
	
	char name[12];
	int score;

};


int main(){

	/* Here we declare variables 'player1' and 'player2'
	   'struct Player' acts as the data type here */

	struct Player player1;
	struct Player player2;

	/* To assign values we use the '.' (one of the member access operators)
	   As 'name' is an array we must use strcpy() to assign a value
	   Otherwise, we can assign directly like 'score' */

	strcpy(player1.name, "Josh");
	player1.score = 4;

	/* As the struct can be reused, we can also assign values for player2
	   The structs for player 1 and 2 arte stored in sepertate blocks of memory */
	
	strcpy(player2.name, "Oceane");
	player2.score = 5;

	printf("%s\n", player1.name);
	printf("%d\n", player1.score);

	printf("%s\n", player2.name);
	printf("%d\n", player2.score);

	return 0;

}
