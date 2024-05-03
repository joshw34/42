#include <unistd.h>

void	ft_print(char a, char b, char c, char d)
{
	if ((c == a && d > b) || (c > a))
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (!(a == '9' && b == '8' && c == '9' && d == '9'))
			write(1, ", ", 2);
	}
}

void	ft_find_comb(char a, char b, char c, char d)
{
	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				d = '0';
				while (d <= '9')
				{
					ft_print(a, b, c, d);
					d = d + 1;
				}
				c = c + 1;
			}
			b = b + 1;
		}
		a = a + 1;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	ft_find_comb(a, b, c, d);
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
