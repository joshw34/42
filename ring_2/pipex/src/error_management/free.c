#include "../../inc/pipex.h"

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
	if (data->arg1 != NULL)
	{
		free_array(data->arg1);
		data->arg1 = NULL;
	}
	if (data->arg2 != NULL)
	{
		free_array(data->arg2);
		data->arg2 = NULL;
	}
	if (data->arg1_path != NULL)
	{
		free(data->arg1_path);
		data->arg1_path = NULL;
	}
	if (data->arg2_path != NULL)
	{
		free(data->arg2_path);
		data->arg2_path = NULL;
	}
	free(data);
}
