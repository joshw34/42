#include <unistd.h>

void	ft_print_alphabet(void);

int	main(void)
{
	ft_print_alphabet();
	return (0);
}

void	ft_print_alphabet(void)
{
	char a;
	a = 'a';
	while(a <= 'z')
	{
		write(1, &a, 1);
		a++;
	}
}
