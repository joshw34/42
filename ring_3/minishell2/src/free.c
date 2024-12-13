/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:01 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/13 11:33:29 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	free_cmds(t_data *data)
{
	cmd_list_clear(data->cmds);
	data->cmds = NULL;
}

static	void	free_tokens(t_data *data)
{
	token_lstclear(data->tokens);
	data->tokens = NULL;
}

void	free_data_struct(t_data *data, bool keep_env)
{
	if (!data)
		return ;
	if (data->user_input)
	{
		free(data->user_input);
		data->user_input = NULL;
	}
	if (data->env && keep_env == false)
	{
		free_array(data->env);
		data->env = NULL;
	}
	if (data->tokens)
		free_tokens(data);
	if (data->cmds)
		free_cmds(data);
	if (keep_env == false)
		free(data);
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
