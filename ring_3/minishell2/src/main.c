/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/27 14:28:12 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	minishell(char **env)
{
	t_data	*data;
	data = init_data_struct(env);
	while (1)
	{
		if (data)
			data->user_input = get_input(data);
		data->tokens = get_tokens(data->user_input);
		check_builtins(data); 
		free_data_struct(data, true);
	}
	free_data_struct(data, false);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	minishell(env);
	return (0);
}

/*int	main(int ac, char **av, char **env)
{
	(void)ac;
	//(void)av;
	printf("\n\n%s\n\n", av[1]);
	t_data *data;
	data = init_data_struct(env);
	//print_env(data);
	if (export_env(data, av[1]) == true)
		printf("WORKS\n");
	//print_env(data);
	free_data_struct(data, false);
	return (0);
}*/
