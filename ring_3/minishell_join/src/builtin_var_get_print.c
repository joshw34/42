/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_var_get_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:32 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/10 14:48:07 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	if (!data->env)
		return ;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	g_last_signal = 0;
}

char	*get_var(char **env, char *var)
{
	char	*ret;

	ret = find_var(env, var);
	if (!ret)
		return (NULL);
	return (ft_strchr(ret, '=') + 1);
}
