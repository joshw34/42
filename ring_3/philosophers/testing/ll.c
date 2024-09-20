#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_ft(int *a, int *b)
{
	int	*temp;

	temp = a;
	a = b;
	b = temp;
}

int	main(int ac, char **av)
{
	int a = atoi(av[1]);
	int b = atoi(av[2]);
	printf("before: a = %d\tb = %d\n", a, b);
	ft_ft(&a, &b);
	printf("before: a = %d\tb = %d\n", a, b);
	(void)ac;
	return (0);
}