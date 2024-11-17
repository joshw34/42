/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:22:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 22:52:44 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_single_struct(t_single *data)
{
	if (data->args)
		free_array(data->args);
	if (data->path)
		free(data->path);
	free(data);
}

void	user_exit(char *input)
{
	rl_clear_history();
	free(input);
	exit(EXIT_SUCCESS);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
