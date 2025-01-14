/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/16 14:14:07 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	remove_quotes(t_tokens *token)
{
	char	*temp;
	int		last;

	temp = ft_strdup(token->word + 1);
	last = ft_strlen(temp) - 1;
	temp[last] = '\0';
	free(token->word);
	token->word = temp;
}

static	void	expand_strings(t_data *data, t_tokens *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->word != NULL && tokens->quote == NONE)
		{
			expand_tilde(data, tokens);
			expand_var(data, tokens);
			/*expand_path(tokens);*/
		}
		else if (tokens->word != NULL && tokens->quote == D_QUOTE)
		{
			expand_tilde(data, tokens);
			expand_var(data, tokens);
			remove_quotes(tokens);
		}
		else if (tokens->word != NULL && tokens->quote == S_QUOTE)
			remove_quotes(tokens);
		tokens = tokens->next;
	}
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

t_tokens	*get_tokens(t_data *data, char *user_input)
{
	int			i;
	char		**split;
	t_tokens	*tokens;

	i = 1;
	if (user_input[0] == '\0' || is_whitespace(user_input) == true)
		return (NULL);
	split = ft_split(user_input, ' ');
	if (check_separator(split[0]) == true)
		tokens = token_lstnew(NULL, ft_strdup(split[0]));
	else
		tokens = token_lstnew(ft_strdup(split[0]), NULL);
	while (split[i])
	{
		if (check_separator(split[i]) == true)
			token_lstadd(tokens, NULL, ft_strdup(split[i]));
		else
			token_lstadd(tokens, ft_strdup(split[i]), NULL);
		i++;
	}
	free_array(split);
	expand_strings(data, tokens);
	return (tokens);
}
