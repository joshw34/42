#include <stdio.h>
#include <string.h>

/*Comment*/

int main(){

	char fname[25];
	char sname[25];

	int day;
	char month[25];
	int year;

	char job[25];

	int number;
	char street[25];
	char city[25];

	printf("What is your first name?  ");
	scanf("%s", &fname);

	printf("What is your surname?  ");
	scanf("%s", &sname);

	printf("On which day of the month were you born?  ");
	scanf("%d", &day);

	printf("In which month were you born?  ");
	scanf("%s", &month);

	printf("In which year were you born?  ");
	scanf("%d", &year);

	getchar();
	printf("What is your profession?  ");
	fgets(job, 25, stdin);
	job[strlen(job)-1] = '\0';

	printf("What number is your house?  ");
	scanf("%d", &number);

	getchar();
	printf("On which street is your house?  ");
	fgets(street, 25, stdin);
	street[strlen(street)-1] = '\0';

	printf("Which city do you live in?  ");
	scanf("%s", &city);

	printf("\nYour name is %s %s and you were born on %d %s %d \n", fname, sname, day, month, year);
	printf("\nYou are a %s \n", job);
	printf("\nYou live at %d %s in %s\n", number, street, city);

	return 0;

}








