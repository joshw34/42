#include <stdio.h>
#include "ft.h"

int	main(void)
{
	ft_putchar('A');
	int a = 1;
	int b = 2;
	printf("\nBefore: A = %d  B = %d", a, b);
	ft_swap(&a, &b);
	printf("\nAfter : A = %d  B = %d\n", a, b);
	ft_putstr("Hello this is a string");
	printf("\nHello = %d characters", ft_strlen("Hello"));
	printf("\nIf string1 = string2: %d", ft_strcmp("Hello", "Hello"));
	return (0);
}
