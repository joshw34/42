/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_var_get_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:32 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/16 14:11:41 by jwhitley         ###   ########.fr       */
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
}

char	*get_var(char **env, char *var)
{
	char	*ret;

	ret = find_var(env, var);
	if (!ret)
		return (NULL);
	return (strchr(ret, '=') + 1);
}
