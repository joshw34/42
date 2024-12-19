/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execution_handling.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:46:36 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/19 11:46:38 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	is_a_builtin(t_cmd *cmd)
{
	if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		return (true);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		return (true);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		return (true);
	else if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		return (true);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (true);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (true);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (true);
	else
		return (false);
}



int redirection_and_execution_builtin(t_cmd *cmd)
{
	int	std_out_save;
	int	return_value;

	
	std_out_save = dup(STDOUT_FILENO);
	if (cmd->out)
		redirection_file_checking_and_selection(&cmd, 1);
	if (cmd->next)
		close(cmd->pipe_fd[0]);
	redirecting_std_output(cmd);
	return_value = check_builtins(cmd);
	dup2(std_out_save, STDOUT_FILENO);
	return (return_value);
}
