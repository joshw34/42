/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:32 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/09 13:59:03 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	printf("1\n");
	if (!data->env)
		return ;
	printf("2\n");
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	printf("3\n");
}

char	*get_var(char **env, char *var)
{
	char	*ret;

	ret = find_var(env, var);
	if (!ret)
		return (NULL);
	return (strchr(ret, '=') + 1);
}
