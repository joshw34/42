/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:20:30 by cngogang          #+#    #+#             */
/*   Updated: 2025/01/07 15:54:45 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	redirection_file_checking_and_selection(t_cmd **command_array,
int direction)
{
	t_redir	*redirection;
	int		fd;

	fd = 0;
	if (!direction)
		redirection = (*command_array)->in;
	else
		redirection = (*command_array)->out;
	while (redirection)
	{
		if (fd)
			close(fd);
		fd = open_file(redirection);
		if (fd == -1)
		{
			perror("open file");
			exit(1);
		}
		redirection = redirection->next;
	}
	if (!direction)
		(*command_array)->fd_in = fd;
	else
		(*command_array)->fd_out = fd;
}

void	redirecting_std_input(t_cmd *command_array)
{
	dup2(command_array->fd_in, 0);
	if (command_array->fd_in != 0)
		close(command_array->fd_in);
}

void	redirecting_std_output(t_cmd *command_array)
{
	dup2(command_array->fd_out, 1);
	if (command_array->fd_out != 1)
		close(command_array->fd_out);
}

void	redirection_and_execution(t_cmd *command_array)
{
//	int	fd_in;

//	fd_in = -1;
	if (!command_array->prev && command_array->in)
		redirection_file_checking_and_selection(&command_array, 0);
	redirecting_std_input(command_array);
	if (command_array->out)
		redirection_file_checking_and_selection(&command_array, 1);
	if (command_array->next)
		close(command_array->pipe_fd[0]);
	redirecting_std_output(command_array);
	if (execute_command(command_array) == -1)
		exit(127);
	exit(0);
}
