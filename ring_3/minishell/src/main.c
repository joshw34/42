#include "../inc/minishell.h"

int	main(int ac, char **av)
{
	(void)ac;
	ft_printf("%s\n", ft_strjoin(av[1], av[2]));
	return (0);
}
