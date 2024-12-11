/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:11:52 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/11 15:43:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	input_redir_add(t_redir *input, t_tokens *tokens)
{
	t_redir	*new;
	
	new = ft_calloc(1, sizeof(t_redir));
	while (input->next != NULL)
		input = input->next;
	input->next = new;
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
	t_redir	*input;

	input = NULL;
	while (tokens != NULL && tokens->i != start)
		tokens = tokens->next;
	while (tokens != NULL && tokens->i != end)
	{
		if (tokens->sep != NULL)
		{
			if (ft_strncmp(tokens->sep, "<", 2) == 0
				|| ft_strncmp(tokens->sep, "<<", 3) == 0)
			{
				if (input == NULL)
					input = input_redir_new(tokens);
				else
					input_redir_add(input, tokens);
			}
		}
		tokens = tokens->next;
	}
	return (input);
}
