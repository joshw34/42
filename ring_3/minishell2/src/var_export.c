/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:36:46 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/21 16:04:14 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	bool	replace_var(t_data *data, char *new_var)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (new_var[i])
	{
		if (new_var[i] == '=')
			break ;
		i++;
	}
	while (data->env[j])
	{
		if (ft_strncmp(data->env[j], new_var, i) == 0)
			break ;
		j++;
	}
	temp = ft_strdup(new_var);
	if (!temp)
		return (false);
	free(data->env[j]);
	data->env[j] = temp;
	return (true);
}

bool	export_env(t_data *data, char *new_var)
{
	char	**split;
	char	*old_var;

	if (var_is_valid(new_var) == false)
		return (false);
	split = ft_split(new_var, '=');
	if (!split[0])
	 	return (free_array(split), false);
	old_var = find_var(data->env, split[0]);
	if (old_var)
	{
		replace_var(data, new_var);
		free_array(split);
		return (true);
	}
	else
		return (free_array(split), false);
	free_array(split);
}
