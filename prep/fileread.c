#include <stdio.h>
#include <unistd.h>

int main(){

	/* FILE=datatype, pF=pointer to file, r=open to read */
	FILE *pF = fopen("writefile.txt", "r");
	char buffer[255];

	/* check if file exists */
	if(pF == NULL){
		printf("Unable to open file!\n");
	}

	else{
		/* fgets stops reading at \n so while loop needed to continue
		   This will continue until fgets has nothing left to read and is NULL */
		while(fgets(buffer, 255, pF) != NULL){
			printf("%s", buffer);
		}
	}
	
	return 0;

}
