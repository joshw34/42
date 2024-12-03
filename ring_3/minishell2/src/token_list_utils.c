/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:29:58 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/03 12:38:00 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	token_lstclear(t_tokens *tokens)
{
	t_tokens	*current;
	t_tokens	*next;

	current = tokens;
	while (current->i != 0)
		current = current->prev;
	while (current != NULL)
	{
		next = current->next;
		free(current->word);
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

static	int	quote_status(char *str)
{
	int	last;

	last = ft_strlen(str) - 1;
	if (str[0] == 39 && str[last] == 39)
		return (S_QUOTE);
	else if (str[0] == 34 && str[last] == 34)
		return (D_QUOTE);
	else
		return (NONE);
}

void	token_lstadd(t_tokens *tokens, char *word, char *sep)
{
	t_tokens	*new;
	t_tokens	*temp;

	temp = token_lstlast(tokens);
	new = token_lstnew(word, sep);
	if (!new)
		return ;
	temp->next = new;
	new->i = temp->i + 1;
	new->prev = temp;
	new->next = NULL;
}

t_tokens	*token_lstnew(char *word, char *sep)
{
	t_tokens	*new;

	new = ft_calloc(1, sizeof(t_tokens));
	if (!new)
		return (NULL);
	if (word)
		new->quote = quote_status(word);
	new->word = word;
	new->sep = sep;
	new->i = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
