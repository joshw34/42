#include "ft_printf.h"

int	main(void)
{
	/*//Test 0 - no formatting
	int	total0 = ft_printf("Hello, World0");
	printf("\n%d\n", total0);
	
	// Test 1 - %c
	int	total1 = ft_printf("Hello%c%cWo%cld1", ',', ' ', 'r');
	printf("\n%d\n", total1);

	//Test 2 - %s
	int	total2 = ft_printf("%s2", "Hello, World");
	printf("\n%d\n", total2);

	//Test 3 - %c & %s
	int	total3 = ft_printf("H%cl%co%so%s3", 'e', 'l', ", W", "rld");
	printf("\n%d\n", total3);

	//Test 4 - %p
	char	str[] = "Hello, World";
	void	*ptr = &str[0];
	int	total4 = ft_printf("%p", ptr);
	printf("\n%d\n", total4);
	int	total4_2 = printf("%p", ptr);
	printf("\n%d\n", total4_2);*/

	
	ft_printf("%x\n", 179526);
	printf("%x\n", 179526);
	ft_printf("%X\n", 179526);
	printf("%X\n", 179526);
	//ft_printf("%%%%\n");
	printf("%%%%\n");
	return (0);
}