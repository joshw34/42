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

static	char	**remove_var_copy(char **old_env, char *var, int size)
{
	int		i;
	int		j;
	int		len;
	char	*temp;
	char	**ret;

	i = 0;
	j = 0;
	ret = ft_calloc(size, sizeof(char *));
	if (!ret)
		return (NULL);
	temp = ft_strjoin(var, "=");
	len = ft_strlen(temp);
	while (old_env[i])
	{
		if (ft_strncmp(old_env[i], temp, len) == 0)
			i++;
		ret[j] = ft_strdup(old_env[i]);
		i++;
		j++;
	}
	free(temp);
	return (ret);
}

bool	remove_var(t_data *data, char *var)
{
	char	**new_env;
	int		size;

	size = 0;
	if (find_var(data->env, var) == NULL)
		return (false);
	while (data->env[size])
		size++;
	new_env = remove_var_copy(data->env, var, size);
	if (!new_env)
		return (false);
	free_array(data->env);
	data->env = new_env;
	return (true);
}

static	bool	add_var(t_data *data, char *new_var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (data->env[i])
		i++;
	new_env = ft_calloc(i + 2, sizeof(char *));
	if (!new_env)
		return (false);
	i = 0;
	while (data->env[i])
	{
		new_env[i] = ft_strdup(data->env[i]);
		i++;
	}
	new_env[i] = ft_strdup(new_var);
	free_array(data->env);
	data->env = new_env;
	return (true);
}

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
	{
		add_var(data, new_var);
		free_array(split);
		return (true);
	}
	free_array(split);
}
