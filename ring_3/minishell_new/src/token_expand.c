/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:59:42 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/16 16:45:41 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	expand_full(char **str, int q_status, int type, char **env)
{
	(void)type;
	if (q_status == S_QUOTE)
		remove_tok_quotes(str, 0, ft_strlen(*str) - 1);
	if (q_status == D_QUOTE)
	{
		remove_tok_quotes(str, 0, ft_strlen(*str) - 1);
		if (type == WORD)
			expand_tok_var(str, 0 , ft_strlen(*str), env);
	}
	return (ft_strlen(*str) - 1);
}

static	bool	process_word(char **str, int type, char **env)
{
	int	i;
	int	start;
	int end;
	int	q_status;

	i = 0;
	while ((*str)[i])
	{
		q_status = set_status((*str)[i]);
		start = i;
		end = find_section_end(*str, start, q_status);
		if (i == 0 && (size_t)end == (ft_strlen(*str) - 1))
			i = expand_full(str, q_status, type, env);
		i++;
	}
	return (true);
}

bool	expand_tokens(t_tokens *token)
{
	t_tokens	*temp;

	temp = token;
	while (temp != NULL)
	{
		//printf("token %d before: %s\n", temp->i, temp->word);
		if (temp->word)
		{
			if (word_syntax(temp->word) == false)
				return (false);
			if (process_word(&temp->word, temp->type, temp->data->env) == false)
				return (false);
			//printf("token %d after: %s\n", temp->i, temp->word);
		}
		else if (temp->sep)
		{	
			if (sep_syntax(token) == false)
				return (false);
		}
		temp = temp->next;
	}
	return (true);
}
