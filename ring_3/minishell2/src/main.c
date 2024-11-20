#include "../inc/minishell.h"

void	minishell(char **env)
{
	t_data	*data;
	int i = 0;
	while (i < 5)
	{
		data = init_data_struct(env);
		if (data)
			data->user_input = get_input(data);
		printf("FIND:\t%s\n", find_var(data->env, "USER"));
		printf("GET :\t%s\n", get_var(data->env, "USER"));
		free_data_struct(data, false);
		i++;
	}
}

int	main(int ac, char **av, char **env) 
{
	(void)ac;
	(void)av;
	
	minishell(env);
	return (0);
}
