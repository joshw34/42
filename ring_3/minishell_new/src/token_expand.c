/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:59:42 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 17:19:08 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	bool	process_token(t_tokens *tok)
{
	if (tok->word)
	{
		if (word_syntax(tok->word) == false)
			return (false);
	}
	else if (tok->sep)
	{
		if (sep_syntax(tok) == false)
			return (false);
	}
	return (true);
}

bool	expand_tokens(t_tokens *token)
{
	t_tokens	*temp;

	temp = token;
	while (temp != NULL)
	{
		if (process_token(temp) == false)
			return (false);
		temp = temp->next;
	}
	return (true);
}
