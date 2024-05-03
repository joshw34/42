#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	main(void)
{
	printf("%d, ", ft_fibonacci(-1));
	printf("%d, ", ft_fibonacci(0));
	printf("%d, ", ft_fibonacci(1));
	printf("%d, ", ft_fibonacci(2));
	printf("%d, ", ft_fibonacci(3));
	printf("%d, ", ft_fibonacci(4));
	printf("%d, ", ft_fibonacci(5));
	printf("%d, ", ft_fibonacci(6));
	printf("%d, ", ft_fibonacci(7));
	printf("%d, ", ft_fibonacci(8));
	printf("%d, ", ft_fibonacci(9));
	printf("%d, ", ft_fibonacci(10));
	printf("%d, ", ft_fibonacci(11));
	printf("%d, ", ft_fibonacci(12));
	printf("%d, ", ft_fibonacci(13));
	printf("%d, ", ft_fibonacci(14));
	printf("%d, ", ft_fibonacci(15));
	printf("%d, ", ft_fibonacci(16));
	printf("%d, ", ft_fibonacci(17));
	printf("%d, ", ft_fibonacci(18));
	printf("%d, ", ft_fibonacci(19));
	printf("%d, ", ft_fibonacci(20));
}

