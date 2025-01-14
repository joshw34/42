/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:34:49 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/14 14:35:51 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	t_tokens	*token_lstlast(t_tokens *tokens)
{
	if (tokens == NULL)
		return (tokens);
	while (tokens->next != NULL)
		tokens = tokens->next;
	return (tokens);
}

static	t_tokens	*token_lstnew(char *word, char *sep)
{
	t_tokens	*new;

	new = ft_calloc(1, sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->word = word;
	new->sep = sep;
	new->i = 0;
	new->processed = false;
	new->next = NULL;
	new->prev = NULL;
	set_token_type(new);
	return (new);
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
	new->processed = false;
	new->i = temp->i + 1;
	new->prev = temp;
	new->next = NULL;
	set_token_type(new);
}

static	bool	check_separator(char *str)
{
	if (ft_strncmp(str, "|", 2) == 0)
		return (true);
	else if (ft_strncmp(str, "<", 2) == 0)
		return (true);
	else if (ft_strncmp(str, ">", 2) == 0)
		return (true);
	else if (ft_strncmp(str, "<<", 3) == 0)
		return (true);
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (true);
	return (false);
}

bool	token_list(t_data *data, char **split)
{
	int	i;
	
	i = 1;
	if (check_separator(split[0]) == true)
		data->tokens = token_lstnew(NULL, ft_strdup(split[0]));
	else
		data->tokens = token_lstnew(ft_strdup(split[0]), NULL);
	if (!data->tokens)
	{
		free_array(split);
		return (false);
	}
	while (split[i])
	{
		if (check_separator(split[i]) == true)
			token_lstadd(data->tokens, NULL, ft_strdup(split[i]));
		else
			token_lstadd(data->tokens, ft_strdup(split[i]), NULL);
		i++;
	}
	free_array(split);
	return (true);
}
