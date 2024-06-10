#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"
#define BLUE_TEXT "\x1b[34m"

int	main(void)
{
	printf(BLUE_TEXT "\n**********\nBZERO TEST\n**********\n" RESET_TEXT);
	
	/* Test 1*/
	char	my_bzero1[] = "Hello, World";
	char	libc_bzero1[] = "Hello, World";
	size_t	n = 13;
	size_t	len = strlen(my_bzero1);

	printf(RESET_TEXT "\nTEST 1\nZero all characters\ns = %s\tn = %ld\n", my_bzero1, n);
	ft_bzero(my_bzero1, n);
	bzero(libc_bzero1, n);
	if (memcmp(my_bzero1, libc_bzero1, len) == 0)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");

	/* Test 2*/
	char	my_bzero2[] = "Hello, World";
	char	libc_bzero2[] = "Hello, World";
	n = 6;
	len = strlen(my_bzero2);

	printf(RESET_TEXT "\nTEST 2\nZero part of string\ns = %s\tn = %ld\n", my_bzero2, n);
	ft_bzero(my_bzero2, n);
	bzero(libc_bzero2, n);
	if (memcmp(my_bzero2, libc_bzero2, len) == 0)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");

	/* Test 3*/
	n = 10;
	char	*my_bzero3 = calloc(n, sizeof(char));
	char	*libc_bzero3 = calloc(n, sizeof(char));

	if (my_bzero3 != NULL && libc_bzero3 != NULL)
	{
		printf(RESET_TEXT "\nTEST 3\nNULL String\ns = %s\tn = %ld\n", my_bzero3, n);
		ft_bzero(my_bzero3, n);
		bzero(libc_bzero3, n);
		if (memcmp(my_bzero3, libc_bzero3, n) == 0)
			printf(GREEN_TEXT "Test passed\n");
		else
			printf(RED_TEXT "Test failed\n");
		free(my_bzero3);
		free(libc_bzero3);
	}
	else
		printf(RED_TEXT "ALLOCATION FAILED");
	
	/* Test 4*/
	char	my_bzero4[] = "Hello, World";
	char	libc_bzero4[] = "Hello, World";
	n = 0;
	len = strlen(my_bzero4);

	printf(RESET_TEXT "\nTEST 4\nn = 0\ns = %s\tn = %ld\n", my_bzero4, n);
	ft_bzero(my_bzero4, n);
	bzero(libc_bzero4, n);
	if (memcmp(my_bzero4, libc_bzero4, len) == 0)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");
}