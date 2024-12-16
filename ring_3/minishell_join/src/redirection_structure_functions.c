/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_structure_functions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:38:50 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/11 10:38:52 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*
t_redir	*new_redirection(char *file_name, char *mode, int direction)
{
	t_redir	*redirection;
	
	redirection = malloc(sizeof(t_redir));
	if(!redirection)
		return (NULL);
	redirection->filename = file_name;
	redirection->mode = mode;
	redirection->direction = direction;
	redirection->next = NULL;
	redirection->fd = 0;
	return (redirection);
}

t_redir	*get_end_redirection(t_redir *redirection)
{
	while (redirection->next)
	{
		redirection = redirection-> next;
	}
	return (redirection);
}


void	add_redirection(t_redir **redirection_array, t_redir *redirection)
{
	t_redir	*end;

	end = get_end_redirection(*redirection_array);
	end -> next = redirection;
	//redirection->prev = end;
}
*/
