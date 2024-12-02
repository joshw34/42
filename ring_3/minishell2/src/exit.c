#include "../inc/minishell.h"

void	exit_cmd(t_data *data)
{
	if (data)
		free_data_struct(data, false);
	exit(EXIT_SUCCESS);
}
