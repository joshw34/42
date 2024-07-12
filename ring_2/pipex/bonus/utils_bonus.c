/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:46:10 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/12 01:29:21 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	**b_get_paths(char **env)
{
	char	**result;
	char	*paths;
	char	*temp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_strtrim(env[i], "PATH=");
		i++;
	}
	result = ft_split(paths, ':');
	i = 0;
	while (result[i])
	{
		temp = ft_strjoin(result[i], "/");
		free(result[i]);
		result[i] = temp;
		i++;
	}
	free(paths);
	return (result);
}

static	void	b_free_int_array(int **array)
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

void	b_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static	void	b_free_cmd_array(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		b_free_array(cmds[i]);
		i++;
	}
	free(cmds);
}

void	b_free_data_struct(t_data *data)
{
	if (data->cmds != NULL)
		b_free_cmd_array(data->cmds);
	if (data->cmd_paths != NULL)
		b_free_array(data->cmd_paths);
	if (data->p_fd != NULL)
		b_free_int_array(data->p_fd);
	if (data->pid != NULL)
		free(data->pid);
	free(data);
}
