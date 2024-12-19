/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_structure_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:38:31 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/11 10:38:33 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd	*new_command(char *command_text, int number_of_command, char **env)
{
	t_cmd	*command;

	command = malloc(sizeof(t_cmd));
	if (!command)
		return (NULL);
	(command->cmd) = command_text;
	command->cmd_n = number_of_command;
	command->in = NULL;
	command->out = NULL;
	command->env = env;
	command->fd_in = 0;
	command->fd_out = 1;
	command->prev = NULL;
	command->next = NULL;
	return (command);
}

t_cmd	*get_end(t_cmd *command)
{
	while (command->next)
	{
		command = command-> next;
	}
	return (command);
}

void	add_command(t_cmd **command_array, t_cmd *command)
{
	t_cmd	*end;

	end = get_end(*command_array);
	end -> next = command;
	command->prev = end;
}
