#include <stdio.h>

int main(){

	/* WRITE/APPEND A FILE */

	/* FILE=datatype, *pF=pointer to file
	   can use relative or absolute file path
	   modes: w=write, a=append, r=read */
	FILE *pF = fopen("writefile.txt", "w");

	fprintf(pF, "Example text file\nHello!");

	fclose(pF);

	/* DELETE A FILE */

	/*	
	if(remove("writefile.txt") == 0){

		printf("That file was deleted successfully!");
	}

	else{

		printf("That file was NOT deleted!");
	} */
	

	return 0;

}
