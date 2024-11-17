/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 16:23:57 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	run_single_command(char *input, char **env)
{
	char	**args;
	char	*path;
	pid_t	pid;

	args = get_args(input);
	if (!args[0])
	{
		free_array(args);
		return ;
	}
	path = ft_strjoin("/usr/bin/", args[0]);
	pid = fork();
	if (pid == 0)
		execve(path, args, env);
	else
		waitpid(pid, NULL, 0);
	add_history(input);
	free(path);
	free_array(args);
}
