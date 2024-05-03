#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;
	
	i = 1;
	while (i <= nb) 
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("\nSquare root of -25 = %d", ft_sqrt(-25));
	printf("\nSquare root of -9  = %d", ft_sqrt(-9));
	printf("\nSquare root of 0   = %d", ft_sqrt(0));
	printf("\nSquare root of 1   = %d", ft_sqrt(1));
	printf("\nSquare root of 9   = %d", ft_sqrt(9));
	printf("\nSquare root of 25  = %d", ft_sqrt(25));
	return (0);
}
