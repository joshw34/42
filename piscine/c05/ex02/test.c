#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	while (power > 0 && power != 1)
	{
		result = (result * nb);
		power--;	
	}
	return(result);
}

int	main(void)
{
	printf("10^0   = %d\n", ft_iterative_power(10, 0));
	printf("10^-1  = %d\n", ft_iterative_power(10, -1));
	printf("10^1   = %d\n", ft_iterative_power(10, 1));
	printf("0^0    = %d\n", ft_iterative_power(0, 0));
	printf("10^2   = %d\n", ft_iterative_power(10, 2));
	printf("10^3   = %d\n", ft_iterative_power(10, 3));
	printf("10^4   = %d\n", ft_iterative_power(10, 4));
	printf("-10^4  = %d\n", ft_iterative_power(-10, 4));
	printf("-10^3  = %d\n", ft_iterative_power(-10, 3));
	printf("-10^2  = %d\n", ft_iterative_power(-10, 2));
	return (0);
}
