#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"
#define BLUE_TEXT "\x1b[34m"

int	main(void)
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