/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:47 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/06 14:31:50 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	echo_print(t_cmd *cmd, int i)
{
	int j;

	while (cmd->args[i])
	{
		j = 0;
		while (cmd->args[i][j])
		{
			if (cmd->args[i][j] != 34)
				ft_putchar_fd(cmd->args[i][j], 1);
			j++;
		}
		i++;
		if (cmd->args[i])
			write(1, " ", 1);
	}
}

static int	only_n_after_minus(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		i++;
		while (arg[i])
		{
			if(arg[i] != 'n')
				return (0);
			i++;
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
	if (only_n_after_minus(cmd->args[i]) == 0)
	{
		echo_print(cmd, i);
		write(1, "\n", 1);
	}
	else
		echo_print(cmd, i + 1);
}
