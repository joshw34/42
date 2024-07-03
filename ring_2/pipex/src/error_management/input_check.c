#include "../inc/pipex.h"

static	void	file_check(int count, char **args)
{
	(void)count;
	if (access(args[0], R_OK) == -1)
		perror("File 1 Read Error\n"); 
}

static	void	arg_count(int count)
{
	if (count != 4)
	{
		if (count < 4)
			ft_putstr_fd("ERROR: Not enough arguments\n", 2);
		if (count > 4)
			ft_putstr_fd("Error: Too many arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	input_check(int count, char **args)
{
	arg_count(count - 1);
	file_check(count - 1, args + 1);
}