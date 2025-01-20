/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:39 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/20 19:33:18 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	is_only_digit(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[1] && cmd->args[1][i])
	{
		if (!(cmd->args[1][i] <= '9' && cmd->args[1][i] >= '0'))
		{
			printf("minishell: exit: %s: numeric argument required\n",
				cmd->args[1]);
			free_data_struct(cmd->data, false);
			exit(2);
		}
		++i;
	}
	return (1);
}


void	exit_cmd(t_data *data)
{
	char	exit_code[2048];
	int		len;

	printf("\nexit\n");
	if (!data->cmds->args[1])
	{
		free_data_struct(data, false);
		exit(g_last_signal);
	}
	if (data->cmds->args[2])
	{
		printf("minishell : exit: too many arguments\n");
		return ;
	}
	if (data->cmds->args[1] && is_only_digit(data->cmds))
	{
		len = ft_strlen(data->cmds->args[1]) + 1;
		ft_strlcpy(exit_code, data->cmds->args[1], len);
		free_data_struct(data, false);
		exit(ft_atoi(exit_code));
	}
}
