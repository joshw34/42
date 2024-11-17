/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 23:02:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	t_single	*init_single_struct(char *input)
{
	t_single	*data;

	data = ft_calloc(1, sizeof(t_single));
	if (!data)
		return (NULL);
	data->args = get_args(input);
	if (!data->args)
	{
		free_single_struct(data);
		return (NULL);
	}
	data->path = get_path(data->args, getenv("PATH"));
	if (!data->path)
	{
		printf("Error: %s: command not found\n", data->args[0]);
		free_single_struct(data);
		return (NULL);
	}
	return (data);
}

void	run_single_command(char *input, char **env)
{
	t_single	*data;

	data = init_single_struct(input);
	if (!data)
		return ;
	data->pid = fork();
	if (data->pid == 0)
		execve(data->path, data->args, env);
	else
		waitpid(data->pid, NULL, 0);
	free_single_struct(data);
}
