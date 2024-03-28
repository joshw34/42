#include <stdio.h>

/* 2D array = an array, where each element is an entire array
   useful if you need a matrix, grid, or table of data */

int main(){
	/* Declare and initialise 2darray.
	   The first square bracket refers to the maximum number of single arrays allowed in the 2d 
	   array (this can be blank).
	   The second square bracket refers to the maximum number of elements in each single array. */

	int numbers[4][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9},{10, 11, 12}};

	/*int numbers[2][3]; */

	/* Divide the total size 'numbers' by the size of a single array (or row here) */
	int rows = sizeof(numbers)/sizeof(numbers[0]);
	/* Divide the size of one array (row) by the size of one value in the (array)row */
	int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

	printf("rows: %d\n", rows);
	printf("columns: %d\n", columns);

	/*numbers[0][0] = 1;
	numbers[0][1] = 2;
	numbers[0][2] = 3;
	numbers[1][0] = 4;
	numbers[1][1] = 5;
	numbers[1][2] = 6; */

	/* The first for loop creates a new row with a '\n' each time the second loop adds the values 
	   for each column in that row */
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%d ", numbers[i][j]);
		}
      
		printf("\n");
	}

	return 0;

}
