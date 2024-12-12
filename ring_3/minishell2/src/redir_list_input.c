/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:11:52 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/12 11:23:07 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	input_redir_add(t_redir *input, t_tokens *tokens)
{
	t_redir	*new;
	t_redir	*temp_input;
	
	new = ft_calloc(1, sizeof(t_redir));
	temp_input = input;
	while (temp_input->next != NULL)
		temp_input = temp_input->next;
	temp_input->next = new;
	if (tokens->sep[0] == '<' && tokens->sep[1] == '\0')
		new->mode = INFILE;
	else
		new->mode = HEREDOC;
	new->direction = IN;
	new->filename = ft_strdup(tokens->next->word);
	new->next = NULL;
	new->fd = -1;
	tokens->processed = true;
	tokens->next->processed = true;
}

static	t_redir	*input_redir_new(t_tokens *tokens)
{
	t_redir	*new;

	new = ft_calloc(1, sizeof(t_redir));
	if (tokens->sep[0] == '<' && tokens->sep[1] == '\0')
		new->mode = INFILE;
	else
		new->mode = HEREDOC;
	new->direction = IN;
	new->filename = ft_strdup(tokens->next->word);
	new->next = NULL;
	new->fd = -1;
	tokens->processed = true;
	tokens->next->processed = true;
	return (new);
}

t_redir	*get_input_redir(t_tokens *tokens, int start, int end)
{
	t_redir		*input;
	t_tokens	*temp_tok;

	input = NULL;
	temp_tok = tokens;
	while (temp_tok != NULL && temp_tok->i != start)
		temp_tok = temp_tok->next;
	while (temp_tok != NULL && temp_tok->i != end)
	{
		if (temp_tok->sep != NULL)
		{
			if (ft_strncmp(temp_tok->sep, "<", 2) == 0
				|| ft_strncmp(temp_tok->sep, "<<", 3) == 0)
			{
				if (input == NULL)
					input = input_redir_new(temp_tok);
				else
					input_redir_add(input, temp_tok);
			}
		}
		temp_tok = temp_tok->next;
	}
	return (input);
}
