/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:40:25 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/08 15:40:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool in_quotes(const char *str, int i)
{
	if (str[i] == 34)
	{
		i++;
		while (str[i])
		{
			if (str[i] == 34)
				return (true);
			i++;
		}
		return (false);
	}
	else if (str[i] == 39)
	{
		i++;
		while (str[i])
		{
			if (str[i] == 39)
				return (true);
			i++;
		}
		return (false);
	}
	else
		return (false);
}

int	find_end_quote(const char *str, int i)
{
	char	c;
	int		ret;

	c = str[i];
	ret = i + 1;

	while (str[ret] && str[ret] != c)
	{
		ret++;
	}
	if (str[ret] == '\0')
		return (ret - 1);
	else
		return (ret);
}

int	find_next_string(const char *str, char c)
{
	int	i;

	i = 0;
	if (c == 34 || c == 39)
	{
		i++;
		while (str[i])
		{
			if (str[i] == c)
				return (i + 1);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (str[i] == ' ')
				return (i);
			i++;
		}
	}
	return (i);
}
