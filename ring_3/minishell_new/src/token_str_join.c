/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_str_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:03:53 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/16 18:39:39 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	join_start(char **str, char *new, int offset)
{
	char	*temp;

	temp = NULL;
	if (!new)
	{
		temp = ft_strdup(*str + offset);
		free(*str);
		*str = ft_strdup(temp);
		free(temp);
		return (0);
	}
	else
	{
		//printf("NEW: %s\nSTR: %s\nINDEX = %d\n", new, *str, offset);
		temp = ft_strjoin(new, *str + offset);
		free(*str);
		*str = ft_strdup(temp);
		free(temp);
		return (ft_strlen(new) - 1);
	}
}

static	int	replace_str(char **str, char *new)
{
	if (!new)
	{
		free(*str);
		*str = ft_strdup("");
	}
	else
	{
		free(*str);
		*str = ft_strdup(new);
	}
	return (ft_strlen(*str) - 1);
}

int	token_str_join(char **str, char *new, int start, int last_char)
{
	//printf("END: %d\n", end);
	if (start == 0 && (size_t)last_char == (ft_strlen(*str) - 1))
		return (replace_str(str, new));
	else if (start == 0)
		return (printf("RETURNING\n"), join_start(str, new, last_char + 1));
	/*else if (start > 0 && end < ft_strlen(*str) - 1)
		join_mid();
	else if (start > 0 && end == ft_strlen(*str) - 1)
		join_end();*/
	return (0);
}