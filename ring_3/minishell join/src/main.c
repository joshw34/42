/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:48 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/06 17:28:18 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void action(int sigint)
{
	//printf("the signal caught is %i\n", sigint);
	if (sigint == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}


/*static void sig_init(struct sigaction *sig_act)
{
	sigemptyset(&(sig_act->sa_mask));        // Don't block any other signals
    sig_act->sa_flags = 0;                 // No special flags
	sig_act->sa_handler = &action;
	if (sigaction(SIGINT, sig_act, NULL) == -1) 
	{
        perror("sigaction");
        exit(1);
	}
}*/

void	minishell_non_int(char **env, char **argv)
{
	t_data	*data;
	data = init_data_struct(env);
	data->user_input = parse_argv(argv);
	data->tokens = get_tokens(data, data->user_input);
	data->cmds = get_cmds(data);
	if (data->cmds)
	{
		if (data->cmds->cmd_n == 1 && is_a_builtin(data->cmds))
			redirection_and_execution_builtin(data->cmds);
		else
			shell_execution(data->cmds);
	}
	free_data_struct(data, false);
}

void	minishell(char **env)
{
	t_data	*data;
	//struct sigaction sig_act;

	data = init_data_struct(env);
	//sig_init(&sig_act);
	while (1)
	{
		signal(SIGINT, action);
		signal(SIGQUIT, SIG_IGN);
		if (data)
			data->user_input = get_input(data);
		data->tokens = get_tokens(data, data->user_input);
		data->cmds =get_cmds(data);
		if (data->cmds)
		{
			if (data->cmds->cmd_n == 1 && is_a_builtin(data->cmds)) ///dont forget to redirect output;
				redirection_and_execution_builtin(data->cmds);
			else
				shell_execution(data->cmds);
		}

		free_data_struct(data, true);
	}

}

int	main(int ac, char **av, char **env)
{
	if (ac == 1)
		minishell(env);
	else
		minishell_non_int(env, av + 1);
	return (0);
}
