/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:29:58 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/26 15:03:50 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	token_lstclear(t_tokens *tokens)
{
	t_tokens	*current;
	t_tokens	*next;

	current = tokens;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

static	t_tokens	*token_lstlast(t_tokens *tokens)
{
	if (tokens == NULL)
		return (tokens);
	while (tokens->next != NULL)
		tokens = tokens->next;
	return (tokens);
}

static	void	token_lstadd(t_tokens *tokens, char *word, char *sep)
{
	t_tokens	*new;
	t_tokens	*temp;

	temp = token_lstlast(tokens);
	new = token_lstnew(word, sep);
	if (!new)
		return ;
	temp->next = new;
	new->i = temp->i++;
	new->prev = temp;
	new->next = NULL;
}

t_tokens	*token_lstnew(char *word, char *sep)
{
	t_tokens	*new;

	new = ft_calloc(1, sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->word = word;
	new->sep = sep;
	new->i = 0;
	new->next = NULL;
	new->next = NULL;
	return (new);
}
