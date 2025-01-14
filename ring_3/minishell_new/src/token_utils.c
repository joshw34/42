/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:29:04 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/14 15:07:52 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	set_token_type(t_tokens *token)
{
	if (token->sep)
	{
		if (token->sep[0] == '|')
			token->type = PIPE;
		if (token->sep[0] == '>' && token->sep[1] == '\0')
			token->type = OUTFILE;
		if (token->sep[0] == '>')
			token->type = APPEND;
		if (token->sep[0] == '<' && token->sep[1] == '\0')
			token->type = INFILE;
		if (token->sep[0] == '<')
			token->type = HEREDOC;
	}
	else if (token->word)
	{
		if (token->prev && token->prev->sep && token->prev->sep[0] != '|')
			token->type = token->prev->type;
		else
			token->type = WORD;
	}
}

bool	is_a_separator(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}