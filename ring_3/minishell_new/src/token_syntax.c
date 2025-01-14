/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:01:16 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/14 13:07:14 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	bool	check_quotes(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != 34 && str[i] != 39)
			i++;
		if (str[i] == '\0')
			return (true);
		if (str[i])
		{
			c = str[i];
			//ft_printf("First %c found at index %d\n", c, i);
			if (str[i + 1])
				i++;
			while (str[i] && str[i] != c)
				i++;
			if (str[i] == '\0')
				return (printf("%s %c\n", ERROR_1, c), false);
			//else
				//ft_printf("Second %c found at index %d\n", c, i);
		}
		i++;
	}
	return (true);
}

bool	sep_syntax(t_tokens * token)
{
	if (token->sep[0] == '|' && token->i == 0)
		return (printf("%s '%s'\n", ERROR_3, token->next->sep), false);
	if (!token->next)
		return(printf("%s\n", ERROR_2), false);
	if (token->next->sep)
		return (printf("%s '%s'\n", ERROR_3, token->next->sep), false);
	return (true);
}

bool	word_syntax(char *str)
{
	if (check_quotes(str) == false)
		return (false);
	return (true);
}