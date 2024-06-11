#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int fact;
	
	fact = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb != 1)
	{
		fact = fact * (nb - 1);
		nb--;
	}
	return (fact);
}

int main(void)
{
	printf("-1!  = %d\n", ft_iterative_factorial(-1));
	printf(" 0!  = %d\n", ft_iterative_factorial(0));
	printf(" 1!  = %d\n", ft_iterative_factorial(1));
	printf(" 2!  = %d\n", ft_iterative_factorial(2));
	printf(" 3!  = %d\n", ft_iterative_factorial(3));
	printf(" 4!  = %d\n", ft_iterative_factorial(4));
	printf(" 5!  = %d\n", ft_iterative_factorial(5));
	printf(" 6!  = %d\n", ft_iterative_factorial(6));
	printf(" 7!  = %d\n", ft_iterative_factorial(7));
	printf(" 8!  = %d\n", ft_iterative_factorial(8));
	printf(" 9!  = %d\n", ft_iterative_factorial(9));
	printf("10!  = %d\n", ft_iterative_factorial(10));
	printf("11!  = %d\n", ft_iterative_factorial(11));
	printf("12!  = %d\n", ft_iterative_factorial(12));
	printf("13!  = %d\n", ft_iterative_factorial(13));
	return (0);
}
