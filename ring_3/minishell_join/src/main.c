/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/16 12:21:20 by jwhitley         ###   ########.fr       */
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
		data->tokens = get_tokens(data, data->user_input);
		data->cmds =get_cmds(data);
		if (data->cmds != NULL)
			check_builtins(data->cmds);
		//DB_print_cmds(data);
		shell_execution(data->cmds);
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
