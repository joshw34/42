/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:59:56 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/10 15:14:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*parse_argv(char **argv)
{
	int		i;
	char	*result;
	char	*temp;

	i = 0;
	if (argv[i])
	{
		result = ft_strdup(argv[i]);
		i++;
	}
	while (argv[i])
	{
		temp = ft_strjoin(result, " ");
		free(result);
		result = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (result);
}

bool	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 7 && str[i] <= 13) && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	is_special_str(char *str)
{
	if (ft_strchr(str, '!') != 0 || ft_strchr(str, '?') != 0
		|| ft_strchr(str, '$') != 0 || ft_strchr(str, '*') != 0
		|| ft_strchr(str, '&') != 0 || ft_strchr(str, ';') != 0)
		return (true);
	if (ft_strchr(str, '(') != 0 || ft_strchr(str, ')') != 0
		|| ft_strchr(str, '[') != 0 || ft_strchr(str, ']') != 0)
		return (true);
	if (ft_strchr(str, '=') != 0 || ft_strchr(str, '~') != 0
		|| ft_strchr(str, '\\') != 0 || ft_strchr(str, '|') != 0
		|| ft_strchr(str, 37) != 0)
		return (true);
	return (false);
}

bool	is_special_char(char c)
{
	if (c == '!' || c == '?' || c == '$' || c == '*' || c == '&' || c == ';')
		return (true);
	if (c == '(' || c == ')' || c == '[' || c == ']')
		return (true);
	if (c == '=' || c == '~' || c == '\\' || c == '|' || c == 37)
		return (true);
	return (false);
}
