#include <string.h>
#include <stdio.h>

int	main(void)
{
	char first[] = {'a', 'b', 'c', 'd', 'e'};
	char second[] = {'a', 'b', 'c', 'd', 'e'};
	int result = strcmp("abcde", "abcde");

	printf("%c", result);
	if (result == 0)
		printf("Strings are equal");
	else if (result > 0)
		printf("First > Second");
	else if (result < 0)
		printf(" Second > First");
	return (0);
	
}
