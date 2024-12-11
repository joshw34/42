/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:13:45 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/11 15:44:00 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	output_redir_add(t_redir *output, t_tokens *tokens)
{
	t_redir	*new;
	
	new = ft_calloc(1, sizeof(t_redir));
	while (output->next != NULL)
		output = output->next;
	output->next = new;
	if (tokens->sep[0] == '>' && tokens->sep[1] == '\0')
		new->mode = OUTFILE;
	else
		new->mode = APPEND;
	new->direction = OUT;
	new->filename = ft_strdup(tokens->next->word);
	new->next = NULL;
	new->fd = -1;
	tokens->processed = true;
	tokens->next->processed = true;
}

static	t_redir	*output_redir_new(t_tokens *tokens)
{
	t_redir	*new;

	new = ft_calloc(1, sizeof(t_redir));
	if (tokens->sep[0] == '>' && tokens->sep[1] == '\0')
		new->mode = OUTFILE;
	else
		new->mode = APPEND;
	new->direction = OUT;
	new->filename = ft_strdup(tokens->next->word);
	new->next = NULL;
	new->fd = -1;
	tokens->processed = true;
	tokens->next->processed = true;
	return (new);
}

t_redir	*get_output_redir(t_tokens *tokens, int start, int end)
{
	t_redir	*output;

	output = NULL;
	while (tokens != NULL && tokens->i != start)
		tokens = tokens->next;
	while (tokens != NULL && tokens->i != end)
	{
		if (tokens->sep != NULL)
		{
			if (ft_strncmp(tokens->sep, ">", 2) == 0
				|| ft_strncmp(tokens->sep, ">>", 3) == 0)
			{
				if (output == NULL)
					output = output_redir_new(tokens);
				else
					output_redir_add(output, tokens);
			}
		}
		tokens = tokens->next;
	}
	return (output);
}