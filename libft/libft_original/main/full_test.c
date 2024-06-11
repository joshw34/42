#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include <string.h>

#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"
#define BLUE_TEXT "\x1b[34m"

void	calloc_test(void)
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

void	bzero_test(void)
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

void	atoi_test(void)
{
	printf(BLUE_TEXT "\n*********\nATOI TEST\n*********\n" RESET_TEXT);
	
	int	my_atoi;
	int libc_atoi;

	/* Test 1*/
	my_atoi = ft_atoi("42");
	libc_atoi = atoi("42");
	printf(RESET_TEXT "\nTEST 1 - Positive\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");
	
	/* Test 2*/
	my_atoi = ft_atoi("-42");
	libc_atoi = atoi("-42");
	printf(RESET_TEXT "\nTEST 2 - Negative\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");
	
	/* Test 3*/
	my_atoi = ft_atoi("0");
	libc_atoi = atoi("0");
	printf(RESET_TEXT "\nTEST 3 - Zero\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");

	/* Test 4*/
	my_atoi = ft_atoi("2147483647");
	libc_atoi = atoi("2147483647");
	printf(RESET_TEXT "\nTEST 4 - Int Max\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");

	/* Test 5*/
	my_atoi = ft_atoi("-2147483648");
	libc_atoi = atoi("-2147483648");
	printf(RESET_TEXT "\nTEST 5 - Int Min\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");

	/* Test 6*/
	my_atoi = ft_atoi("2147483648");
	libc_atoi = atoi("2147483648");
	printf(RESET_TEXT "\nTEST 6 - Above Int Max\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");

	/* Test 7*/
	my_atoi = ft_atoi("-2147483649");
	libc_atoi = atoi("-2147483649");
	printf(RESET_TEXT "\nTEST 7 - Below Int Min\n");
	printf("ft_atoi: %d\tatoi: %d\n", my_atoi, libc_atoi);
	if (my_atoi == libc_atoi)
		printf(GREEN_TEXT "Test passed\n");
	else
		printf(RED_TEXT "Test failed\n");
}

int	main(void)
{
	atoi_test();
	bzero_test();
	calloc_test();
}