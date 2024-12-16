/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:47 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/16 14:32:49 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_cmd(t_cmd *cmd)
{
	if (!cmd->args[1])
	{
		printf("\n");
		return ;
	}
	if (ft_strncmp(cmd->args[1], "-n", 3) == 0)
	{
		if (cmd->args[2] != NULL)
			printf("%s", cmd->args[2]);
	}
	else
		printf("%s\n", cmd->args[1]);
}
