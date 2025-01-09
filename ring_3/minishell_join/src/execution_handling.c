/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:40:04 by cngogang          #+#    #+#             */
/*   Updated: 2025/01/09 19:22:17 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


static void print_error_finding_command(t_cmd *command_array)
{
	ft_putstr_fd(command_array->cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

int	execute_command(t_cmd *command_array)
{
	char	**fullpath;
	char	**anchor;

	if (!command_array->cmd)
		return (-1);
	if (access(command_array->cmd, X_OK) == 0)
		execve(command_array->cmd, command_array->args, command_array->env);
	if (ft_strchr(command_array->cmd, '/'))
		return (print_error_finding_command(command_array), -1);
	if (redirection_and_execution_builtin(command_array))
		return (1);
	fullpath = get_path_array(command_array->env, (command_array->args)[0]);
	if (!fullpath)
		return (print_error_finding_command(command_array),-1);
	anchor = fullpath;
	while (*fullpath)
	{
		if (execve(*fullpath, command_array->args, command_array->env) == -1)
			++fullpath;
	}
	print_error_finding_command(command_array);
	free_2d_array(anchor);
	return (-1);
}

void	fork_redirection_and_execution(t_cmd *command_array)
{
	command_array->pid = fork();
	signal(SIGINT, action_2);
	if (!command_array->pid)
	{
		redirection_and_execution(command_array);
	}
	
}

void	processing_commands(t_cmd *command_array)
{
	while (command_array)
	{
		if (command_array->prev)
		{
			command_array->fd_in = command_array->prev->pipe_fd[0];
			if (command_array->prev->fd_in)
				close(command_array->prev->fd_in);
		}
		if (command_array->next)
		{
			if (pipe(command_array->pipe_fd) == -1)
				perror("pipe");
			command_array->fd_out = command_array->pipe_fd[1];
		}
		fork_redirection_and_execution(command_array);
		if (command_array->next)
			close(command_array->pipe_fd[1]);
		else if (!command_array->next && command_array->fd_in)
			close(command_array->fd_in);
		command_array = command_array->next;
	}
}

void	shell_execution(t_cmd *command_array)
{
	int	status;

	processing_commands(command_array);
	waiting_sons_processes(command_array, &status);
}
