#include <stdio.h>
#include <ctype.h>

int main(){

	/* Questions and options as 2d arrays */

	char questions[][100] = {"1. What year did the C language debut?: ",
                                 "2. Who is credited with creating C?:",
                                 "3. What is the predecessor of C?: "};
                            
	char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                               "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                               "A. Objective C", "B. B", "C. C++", "D. C#"};
                          
	char answers[] = {'B', 'A', 'B'};
	
	/* # of questions = size of array / 1 element */
	int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);

	char guess = ' ';
	int score = 0;

	printf("QUIZ GAME\n");    

	/* Outer loop run 'numberOfQuestions' times */
	for(int i = 0; i < numberOfQuestions; i++){
		printf("*********************\n");
		printf("%s\n", questions[i]);
		printf("*********************\n");

		/* when i=0, j=0, when i=1, j=4
		   first options A = options[0], second = [options[4] */
		for(int j = (i * 4); j < (i * 4) + 4; j++){
			printf("%s\n", options[j]);
		}
		

		printf("guess: ");
		scanf("%c", &guess);
		scanf("%*c"); //clear \n from input buffer

		guess = toupper(guess);

		if(guess == answers[i]){
			printf("CORRECT!\n");
			score++;
		}

		else{
			printf("WRONG!\n");
		}
	}

	printf("*********************\n");
	printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
	printf("*********************\n");
 
	return 0;

}
