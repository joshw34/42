/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:29:27 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/16 18:15:30 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int		substitute_var(char **str, int start, char **env)
{
	int		i;
	int		j;
	char	*temp;
	
	j = 0;
	i = start + 1;
	temp = ft_calloc(ft_strlen(*str) + 1, sizeof(char));
	while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '$')
	{
		temp[j] = (*str)[i];
		i++;
		j++;
	}
	//printf("temp: %s\n", temp);
	i = token_str_join(str, get_var(env, temp), start, j);
	free(temp);
	return (i);
}

void	expand_tok_var(char **str, int start, int end, char **env)
{
	int	i;

	i = start;
	//printf("EXPAND: %s\ni = %d  end = %d\n", *str, i, end);
	while (i < end)
	{
		//printf("LOOP\n");
		if ((*str)[i] == '$')
		{
			i = substitute_var(str, i, env);
			end = ft_strlen(*str);
			printf("STR: %s\n", *str);
			printf("i = %d  end = %d\n", i, end);
		}
		i++;
	}
}

void	remove_tok_quotes(char **str, int open, int close)
{
	int		new_size;
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new_size = ft_strlen(*str) - 2;
	new = ft_calloc(new_size + 1, sizeof(char));
	while ((*str)[i])
	{
		if (i == open || i == close)
			i++;
		else
		{
			new[j] = (*str)[i];
			j++;
			i++;
		}
	}
	free(*str);
	*str = ft_strdup(new);
	free(new);
}

int	find_section_end(char *str, int start, int q_status)
{
	int		i;
	char	c;

	i = start;
	//printf("FIND; str = %s  q_status = %d\n", str + i, q_status);
	if (q_status == NONE)
	{
		while (str[i] && str[i] != 34 && str[i] != 39)
			i++;
	}
	else if ((q_status == S_QUOTE || q_status == D_QUOTE) && str[i + 1])
	{
		c = str[i];
		i++;
		while (str[i] != c)
			i++;
	}
	if (str[i] == '\0')
		return (i - 1);
	return (i);
}
