#include "../inc/pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_data_struct(t_data *data)
{
	if (data->cmd1 != NULL)
	{
		free_array(data->cmd1);
		data->cmd1 = NULL;
	}
	if (data->cmd2 != NULL)
	{
		free_array(data->cmd2);
		data->cmd2 = NULL;
	}
	if (data->cmd1_path != NULL)
	{
		free(data->cmd1_path);
		data->cmd1_path = NULL;
	}
	if (data->cmd2_path != NULL)
	{
		free(data->cmd2_path);
		data->cmd2_path = NULL;
	}
	free(data);
}

void	free_exit(int status, t_data *data)
{
	if (errno != 0)
		perror("");
	free_data_struct(data);
	exit(status);
}
