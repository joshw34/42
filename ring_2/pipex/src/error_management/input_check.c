#include "../../inc/pipex.h"

static	void	file_access(char **args, t_data *data)
{
	if (access(args[0], R_OK) == -1)
	{
		perror("Infile");
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
	if (access(args[3], W_OK) == -1)
	{
		perror("Outfile");
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
	data->infile = args[0];
	data->outfile = args[3];
}

static	void	arg_count(int count, t_data *data)
{
	if (count != 4)
	{
		if (count < 4)
			ft_putstr_fd("ERROR: Not enough arguments\n", 2);
		if (count > 4)
			ft_putstr_fd("Error: Too many arguments\n", 2);
		free_data_struct(data);
		exit(EXIT_FAILURE);
	}
}

void	populate_struct(int count, char **args, char **env, t_data *data)
{
	arg_count(count - 1, data);
	file_access(args + 1, data);
}
