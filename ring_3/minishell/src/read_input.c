/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:22:46 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 16:23:19 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	read_input(char *input, char **env)
{
	if (*input == '\0')
		return ;
	else if (ft_strncmp(input, "exit", 5) == 0)
		user_exit(input);
	else if (input)
	{
		if (!ft_strchr(input, '|'))
			run_single_command(input, env);
		else
			printf("PIPE\n");
	}
}
