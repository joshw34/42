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


static int	only_n_after_minus(char *arg)
{
	int	i;

	i = 0;
	if (arg[i++] == '-')
	{
		while (arg[i])
		{
			if(arg[i++] != 'n')
				return (0);
		}
		return (1);	
	}
	else
		return (0);
}

void	echo_cmd(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (!cmd->args[i])
	{
		printf("\n");
		return ;
	}
	//if (ft_strncmp(cmd->args[1], "-n", 3) == 0)
	while (only_n_after_minus(cmd->args[i]))
		++i;
	while (cmd->args[i])
		printf("%s\n", cmd->args[i++]);
	
}
