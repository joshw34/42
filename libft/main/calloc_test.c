#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"
#define BLUE_TEXT "\x1b[34m"

int	main(void)
{
	printf(BLUE_TEXT "\n************\nCALLOC TEST\n************\n" RESET_TEXT);
	
	/* Test 1*/
	size_t	n = 10;
	char	*my_calloc1 = ft_calloc(n, sizeof(char));
	char	*libc_calloc1 = calloc(n, sizeof(char));

	if (my_calloc1 != NULL && libc_calloc1 != NULL)
	{
		printf(RESET_TEXT "\nTEST 1 - Basic Calloc\nnmemb = %ld\tsize = sizeof(char)\n", n);
		if (memcmp(my_calloc1, libc_calloc1, n) == 0)
			printf(GREEN_TEXT "Test passed\n");
		else
			printf(RED_TEXT "Test failed\n");
		free(my_calloc1);
		free(libc_calloc1);
	}
	else
		printf(RED_TEXT "ALLOCATION FAILED");

	/* Test 2*/
	n = 0;
	char	*my_calloc2 = ft_calloc(n, sizeof(char));
	char	*libc_calloc2 = calloc(n, sizeof(char));

	printf(RESET_TEXT "\nTEST 2 - nmemb = 0\nnmemb = %ld\tsize = sizeof(char)\n", n);
	if ((my_calloc2 != NULL && libc_calloc2 != NULL) && my_calloc2 != libc_calloc2)
	{
		printf(GREEN_TEXT "Test passed\n");
		free(my_calloc2);
		free(libc_calloc2);
	}
	else if (my_calloc2 == NULL && libc_calloc2 == NULL)
		printf(RED_TEXT "ALLOCATION FAILED");

	/* Test 3*/
	n = 10;
	char	*my_calloc3 = ft_calloc(n, 0);
	char	*libc_calloc3 = calloc(n, 0);

	printf(RESET_TEXT "\nTEST 3 - size = 0\nnmemb = %ld\tsize = 0\n", n);
	if ((my_calloc3 != NULL && libc_calloc3 != NULL) && my_calloc3 != libc_calloc3)
	{
		printf(GREEN_TEXT "Test passed\n");
		free(my_calloc3);
		free(libc_calloc3);
	}
	else if (my_calloc3 == NULL && libc_calloc3 == NULL)
		printf(RED_TEXT "ALLOCATION FAILED");
}