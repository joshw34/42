#include "../inc/minishell.h"

void	free_data_struct(t_data *data, bool keep_env)
{
	if (!data)
		return ;
	if (data->user_input)
	{
		free(data->user_input);
		data->user_input = NULL;
	}
	if (data->env && keep_env == false)
	{
		free_array(data->env);
		data->env = NULL;
	}
	if (keep_env == false)
		free(data);
}

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
