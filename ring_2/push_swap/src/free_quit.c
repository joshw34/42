#include "../inc/push_swap.h"

void	quit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	quit_error_free(char **argv, int start_pos)
{
	if (start_pos == 0)
		free_argv(argv);
	quit_error();
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}