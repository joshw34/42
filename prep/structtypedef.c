#include <stdio.h> 
#include <string.h>

/* typedef = reserved keyword that gives an existing datatype a "nickname"*/

/* add 'typedef' before 'struct'
   tagname is not required after 'struct'
   add the 'nickname' afetr the } */

typedef struct{

	char name[25];
	char password[12];
	int id;
	
} User;

int main(){

	/* Using 'User' as the datatype to refer to the struct and 'user1' & 'user2'
	   as variable names.
	   We no longer need the keyword 'struct'*/

	User user1 = {"Josh", "password123", 123456789};
	User user2 = {"Oceane", "password321", 987654321};

	printf("%s\n", user1.name);
	printf("%s\n", user1.password);
	printf("%d\n", user1.id);
	printf("\n");
	printf("%s\n", user2.name);
	printf("%s\n", user2.password);
	printf("%d\n", user2.id);

	return 0;

}
