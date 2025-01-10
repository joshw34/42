/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:39 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/10 14:48:07 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exit_cmd(t_data *data)
{
	char	exit_code[2048];
	int		len;

	if (data->cmds->args[1])
	{
		len = ft_strlen(data->cmds->args[1]) + 1;
		ft_strlcpy(exit_code, data->cmds->args[1], len);
		free_data_struct(data, false);
		exit(ft_atoi(exit_code));
	}
	else
	{
		free_data_struct(data, false);
		exit(g_last_signal);
	}
}
