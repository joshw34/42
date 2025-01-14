/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:29:04 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/15 17:38:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	check_sep_spacing_2(char *input, int i)
{
	if (input[i + 1] != input[i])
	{
		if (input[i + 1] != '\0' && input[i + 1] != ' ' && input [i + 1] != 31)
			return (2);
		if (i != 0 && input[i - 1] != ' ' && input[i - 1] != 31 && input[i - 1] != input[i])
			return (1);
	}
	else if (input[i + 1] == input[i])
	{
		if (i != 0 && input[i - 1] == input[i])
			return (2);
		if (i != 0 && input[i - 1] != ' ' && input[i - 1] != 31)
			return (1);
	}
	return (0);
}

int	check_sep_spacing(char *input, int i)
{
	if (input[i] == '|')
	{
		if (input[i + 1] != '\0' && input[i + 1] != ' ' && input[i + 1] != 31)
			return (2);
		if (i != 0 && input[i - 1] != ' ' && input[i - 1] != 31)
			return (1);
	}
	if (input[i] == '>' || input[i] == '<')
		return (check_sep_spacing_2(input, i));
	return (0);
}

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