#include <stdio.h>

/* enum = a user defined type of named integer identifiers
          helps to make a progrtam more readable */

/* enums are treated as integers not strings
   each value is a constant and has an associated integer */
   
/*   enum 'Day' declared and initialised.  Here Sun = 0 and Sat = 6 */

//enum Day{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

/* We can assign our own integer values instead */
enum Day{Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7};

int main(){

	/* To use the enum:
	   keyword 'enum' + identifier 'Day' and a variable name 'today' */

	enum Day today;
	today = Wed;

	/* As enum values are integers we can print using %d, however this will
	   just print the associated integer and not the 'Day' name */
	printf("%d\n", today);

	
	/* To make the following statement more readable we can replace the integer
	   values with the corrersponding day names */
	
	/*if(today == 1 || today == 7){
		printf("\nIt's the weekend! Party time!");
	}
	else{
		printf("\nI have to work today :(");
	} */
	
	if(today == Sun || today == Sat){
		printf("\nIt's the weekend! Party time!");
	}
	else{
		printf("\nI have to work today :(");
	}
 
	return 0;

}
