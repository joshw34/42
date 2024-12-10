/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:13:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/10 13:35:33 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd	cmdlist_new(t_tokens *tokens, int start, int end)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	
}

int	cmd_find_end(int start, t_tokens *tokens)
{
	while (tokens != NULL && tokens->i != start)
		tokens = tokens->next;
	while (tokens != NULL && tokens->sep != NULL && tokens->sep[0] != '|')
		tokens = tokens->next;
	return (tokens->i);
}

int	cmd_count(t_tokens *tokens)
{
	int	n;

	n = 1;
	while (tokens != NULL)
	{
		if (tokens->sep != NULL && tokens->sep[0] == '|'
			&& tokens->next != NULL)
			n++;
		tokens = tokens->next;
	}
	return (n);
}