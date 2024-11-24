/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_export_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:53:47 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/21 16:04:09 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static bool	value_valid_unquoted(char *new_var, int i)
{
	while (new_var[i])
	{
		if (ft_isalnum(new_var[i]) == 0 && new_var[i] != '_' && new_var[i] != '/')
			return (false);
		i++;
	}
	return (true);
}

static bool	value_valid_quoted(char *new_var, size_t i)
{
	while (new_var[i])
	{
		if (ft_isascii(new_var[i]) == 0)
			return (false);
		i++;
	}
	i = 0;
	while (new_var[i] != '"')
		i++;
	new_var[i] = new_var[i +1];
	i++;
	while ((i + 1) < ft_strlen(new_var) - 1)
	{
		new_var[i] = new_var[i + 1];
		i++;
	}
	new_var[i] = '\0';
	return (true);
}

static bool	value_is_quoted(char *new_var, int i)
{
	int	last;

	last = ft_strlen(new_var) - 1;
	if (new_var[i] == '"' && new_var[last] == '"')
		return (true);
	else
		return (false);
}

static bool	var_name_is_valid(int c)
{
	if (ft_isalnum(c) == 1 || c == '_')
		return (true);
	return (false);
}

bool	var_is_valid(char *new_var)
{
	int	i;

	i = 0;
	if ((new_var[i] >= 'A' && new_var[i] <= 'Z') || new_var[i] == '_')
		i++;
	else
		return (false);
	while (var_name_is_valid(new_var[i]) == true)
		i++;
	if (new_var[i] != '=')
		return (false);
	i++;
	if (value_is_quoted(new_var, i) == true)
	{
		if (value_valid_quoted(new_var, i + 1) == true)
			return (true);
		return (false);
	}
	else
	{
		if (value_valid_unquoted(new_var, i) == true)
			return (true);
		return (false);
	}
}
