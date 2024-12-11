/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:13:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/11 16:16:46 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*parse_cmd(t_tokens *tokens, int start, int end)
{
	t_tokens	*temp;
	size_t		len;
	char		*cmd;

	while (tokens != NULL && tokens->i != start)
		tokens = tokens->next;
	temp = tokens;
	len = 0;
	while (temp != NULL && temp->i <= end)
	{
		if (temp->processed == false && temp->word != NULL)
			len = len + ft_strlen(temp->word);
		temp = temp->next;
	}
	if (len == 0)
		return (NULL);
	cmd = ft_calloc(len + 1, sizeof(char));
	while (tokens != NULL && tokens->i <= end)
	{
		len = ft_strlen(cmd);
		if (tokens->processed == false && tokens->word !=NULL)
			ft_strlcat(cmd + len, tokens->word, ft_strlen(tokens->word) + 1);
		tokens = tokens->next;
	}
	return (cmd);
}

int	cmd_find_end(int start, t_tokens *tokens)
{
	int	ret;

	ret = 0;
	while (tokens != NULL && tokens->i != start)
		tokens = tokens->next;
	while (tokens != NULL && tokens->sep != NULL && tokens->sep[0] != '|')
	{
		ret = tokens->i;
		tokens = tokens->next;
	}
	if (tokens == NULL)
		return (ret);
	else
		return (ret + 1);
}

int	cmd_count(t_tokens *tokens)
{
	int	n;

	n = 1;
	while (tokens != NULL)
	{
		if (tokens->sep != NULL && tokens->sep[0] == '|'
			&& tokens->next != NULL)
			n++;
		tokens = tokens->next;
	}
	return (n);
}