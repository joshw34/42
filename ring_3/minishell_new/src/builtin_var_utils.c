/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_var_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:51 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/20 19:20:47 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*find_var(char **env, char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (env[i])
	{
		if (ft_strncmp(var, env[i], len) == 0)
		{
			if (env[i][len] == '\0' || env[i][len] == '=')
			return (env[i]);
		}
		i++;
	}
	return (NULL);
}
