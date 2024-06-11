#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error");
		return (1);
	}
	if (argc == 2)
		argv = split_argv(argv[1])
	return (0);
}
