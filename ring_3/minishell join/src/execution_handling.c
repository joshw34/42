/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:40:04 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/11 10:40:23 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


int	execute_command(t_cmd *command_array)
{
	char	**fullpath;
	char	**anchor;

	if (!command_array->cmd)
		return (-1);
	if (access(command_array->cmd, X_OK) == 0)
			execve(command_array->cmd, command_array->args, command_array->env);
	
	if (ft_strchr(command_array->cmd, '/'))
		return (-1);
	//if (check_builtins(command_array))
	//	exit (0);
	//printf("B\n");
	//command_and_option = command_array->args;
	if (redirection_and_execution_builtin(command_array))
		return (1);
	fullpath = get_path_array(command_array->env, (command_array->args)[0]);
	if (!fullpath)
		return (-1);
	//printf("C\n");
	anchor = fullpath;
	while (*fullpath)
	{
		//printf("path == %s\n", *fullpath);
		if (execve(*fullpath, command_array->args, command_array->env) == -1)
			++fullpath;
	}
	ft_putstr_fd(command_array->cmd, STDERR_FILENO);
	ft_putstr_fd(" : command not found\n", STDERR_FILENO);

	free_2d_array(anchor);
	//free_2d_array(command_and_option);
	return (-1);
}

/*
int	exec_command(char **env, char **arg)
{
	char	**fullpath;
	char	**anchor;

	if (!arg[0])
		return (-1);
	if (access(arg[0], X_OK) == 0)
		execve(arg[0], arg, env);
	else if (ft_strchr(arg[0], '/'))
		return (-1);
	fullpath = get_path_array(env, arg[0]);
	if (!fullpath)
		return (-1);
	anchor = fullpath;
	while (*fullpath)
	{
		if (execve(*fullpath, arg, env) == -1)
			++fullpath;
	}
	free_2d_array(anchor);
	free_2d_array(arg);
	return (-1);
}
*/



void	fork_redirection_and_execution(t_cmd *command_array)
{
	command_array->pid = fork();
	if (!command_array->pid)
		redirection_and_execution(command_array);
}

void processing_commands(t_cmd *command_array)
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

void shell_execution(t_cmd *command_array)
{
	int	status;

	processing_commands(command_array);
	waiting_sons_processes(command_array, &status);
}
