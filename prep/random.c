#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* pseudo random numbers = A set of values or elements that is statistically random
   (Don't use these for any sort of cryptographic security) */

int main(){

	/* Use current time as a seed for random # generator
	   s=seed r=random time(0)=current time */

	srand(time(0));

	/* rand() generates a pseudo random # between 0 - 32,767
	   % 6 limits the range of number to 6 (0 - 5)
	   +1 changes 0-5 to 1-6 */

	int number1 = (rand() % 6) + 1;
	int number2 = (rand() % 6) + 1;
	int number3 = (rand() % 6) + 1;

	printf("%d\n", number1);
	printf("%d\n", number2);
	printf("%d\n", number3);

	return 0;

}
