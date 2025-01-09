/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:13:45 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/13 11:51:33 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	output_redir_add(t_redir *output, t_tokens *tokens)
{
	t_redir	*new;
	t_redir	*temp_output;

	new = ft_calloc(1, sizeof(t_redir));
	temp_output = output;
	while (temp_output->next != NULL)
		temp_output = temp_output->next;
	temp_output->next = new;
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
	t_redir		*output;
	t_tokens	*temp_tok;

	output = NULL;
	temp_tok = tokens;
	while (temp_tok != NULL && temp_tok->i != start)
		temp_tok = temp_tok->next;
	while (temp_tok != NULL && temp_tok->i != end)
	{
		if (temp_tok->sep != NULL)
		{
			if (ft_strncmp(temp_tok->sep, ">", 2) == 0
				|| ft_strncmp(temp_tok->sep, ">>", 3) == 0)
			{
				if (output == NULL)
					output = output_redir_new(temp_tok);
				else
					output_redir_add(output, temp_tok);
			}
		}
		temp_tok = temp_tok->next;
	}
	return (output);
}
