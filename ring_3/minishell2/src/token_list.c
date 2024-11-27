/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:53 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/27 14:00:34 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_tokens	*get_tokens(char *user_input)
{
	int			i;
	char		**split;
	t_tokens	*tokens;
	
	i = 1;
	if (user_input[0] == '\0' || is_whitespace(user_input) == true)
		return (NULL);
	split = ft_split(user_input, ' ');
	tokens = token_lstnew(ft_strdup(split[0]), NULL);
	while (split[i])
	{
		token_lstadd(tokens, ft_strdup(split[i]), NULL);
		i++;
	}
	free_array(split);
	return (tokens);
}
