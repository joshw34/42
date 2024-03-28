#include <stdio.h> 

/* typedef = reserved keyword that gives an existing datatype a "nickname" */

/* typedef called user is created as a char string of 25bytes */

typedef char user[25];

int main(){
	
	/* 'user' here is used like a datatype and will always creatye a char string of 25 bytes
	    'user1' is the variable name */

	user user1 = "Josh";

	printf("user1 = %s", user1);

	return 0;

}
