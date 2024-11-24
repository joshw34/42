/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:56:24 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/21 16:04:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	char	**init_env(char **env)
{
	int		i;
	char	**ret;

	i = 0;
	while (env[i])
		i++;
	ret = ft_calloc(i + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (env[i])
	{
		ret[i] = ft_strdup(env[i]);
		if (!ret[i])
			return (free_array(ret), NULL);
		i++;
	}
	return (ret);
}

t_data	*init_data_struct(char **env)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = init_env(env);
	remove_var(data, "OLDPWD");
	return (data);
}
