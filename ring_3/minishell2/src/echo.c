/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:47 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/13 13:59:48 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_cmd(t_cmd *cmd)
{
	if (ft_strncmp(cmd->args[1], "-n", 3) == 0)
		printf("%s", cmd->args[2]);
	else
		printf("%s\n", cmd->args[1]);
}
