/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:25 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/09 14:00:09 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	check_builtins(t_data *data)
{
	if (ft_strncmp(data->tokens->word, "pwd", 4) == 0)
		print_pwd(data);
	else if (ft_strncmp(data->tokens->word, "exit", 5) == 0)
		exit_cmd(data);
	else if (ft_strncmp(data->tokens->word, "env", 4) == 0)
		print_env(data);
	else if (data->tokens->next == NULL)
		return (false);
	else if (ft_strncmp(data->tokens->word, "cd", 3) == 0)
		change_dir(data, data->tokens->next->word);
	else if (ft_strncmp(data->tokens->word, "export", 7) == 0)
		export_env(data, data->tokens->next->word);
	else if (ft_strncmp(data->tokens->word, "unset", 6) == 0)
		remove_var(data, data->tokens->next->word);
	else if (ft_strncmp(data->tokens->word, "echo", 5) == 0)
		echo_cmd(data);
	else
		return (false);
	return (true);
}
