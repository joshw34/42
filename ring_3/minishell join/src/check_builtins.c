/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:25 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/16 14:27:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	check_builtins(t_cmd *cmd)
{
	if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		print_pwd(cmd->data);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		exit_cmd(cmd->data);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		print_env(cmd->data);
	else if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		echo_cmd(cmd);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		change_dir(cmd);
	else if (cmd->args[1] == NULL)
		return (false);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		export_env(cmd->data, cmd->args[1]);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		remove_var(cmd->data, cmd->args[1]);
	else
		return (false);
	return (true);
}
