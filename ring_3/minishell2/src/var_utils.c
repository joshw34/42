/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:51 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/21 16:04:06 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdbool.h>

char	*find_var(char **env, char *var)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	temp = ft_strjoin(var, "=");
	len = ft_strlen(temp);
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], len) == 0)
		{
			free(temp);
			return (env[i]);
		}
		i++;
	}
	free(temp);
	return (NULL);
}
