/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:48 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/16 13:42:12 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_last_signal;

/*void	minishell_non_int(char **env, char **argv)
{
	t_data	*data;

	data = init_data_struct(env);
	data->user_input = parse_argv(argv);
	data->tokens = get_tokens(data, data->user_input);
	data->cmds = get_cmds(data);
	if (data->cmds && data->cmds->args[0] != NULL)
	{
		if (data->cmds->cmd_n == 1 && is_a_builtin(data->cmds))
			redirection_and_execution_builtin(data->cmds);
		else
			shell_execution(data->cmds);
	}
	free_data_struct(data, false);
}*/

void	minishell(char **env)
{
	t_data	*data;

	data = init_data_struct(env);
	signal(SIGQUIT, SIG_IGN);
	int i = 0;
	while (i < 3)
	{
		signal(SIGINT, standard_behavior);
		if (process_user_input(data) == true)
		{
			/*if (data->cmds->cmd_n == 1 && is_a_builtin(data->cmds))
				redirection_and_execution_builtin(data->cmds);
			else
				shell_execution(data->cmds);*/
		}
		free_data_struct(data, true);
		i++;
	}
	free_data_struct(data, false);
}

int	main(int ac, char **av, char **env)
{
	if (env[0] == NULL)
		exit(EXIT_FAILURE);
	g_last_signal = 0;
	if (ac == 1)
		minishell(env);
	(void)av;
	/*else
		minishell_non_int(env, av + 1);*/
	return (0);
}
