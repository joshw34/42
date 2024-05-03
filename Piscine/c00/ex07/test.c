#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	i;
	char	number[11];

	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb = (nb * -1);
	}
	while (nb != 0 && nb != -2147483648)
	{
		number[i] = (48 + (nb % 10));
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &number[i - 1], 1);
		i--;
	}
}

void ft_putchar(char c) {write(1, &c, 1);}
int	main(void)
{
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(1047483647);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-270590);
	ft_putchar('\n');
	ft_putnbr(151422);
	ft_putchar('\n');
	return (0);
}
