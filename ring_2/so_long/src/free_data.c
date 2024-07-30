#include "../inc/so_long.h"

void	free_array(char **array)
{
	int	i;
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_data(t_data *data)
{
	if (data->init != NULL)
		free(data->init);
	if (data->win != NULL)
		free(data->win);
	if (data->map != NULL)
		free_array(data->map);
	free(data);
}

void	error_exit(t_data *data)
{
	free_data(data);
	exit(EXIT_FAILURE);
}