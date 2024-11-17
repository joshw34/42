/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:21:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/18 00:04:14 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_path(char **args, char *paths)
{
	char	*temp;
	char	*result;
	char	**split;
	int		i;
	
	i = 0;
	split = ft_split(paths, ':');
	while (split[i])
	{
		temp = ft_strjoin(split[i], "/");
		result = ft_strjoin(temp, args[0]);
		free(temp);
		if (access(result, X_OK) == 0)
		{
			free_array(split);
			return(result);
		}
		else
			free(result);
		i++;
	}
	free_array(split);
	return (NULL);
}

static	bool	check_spaces(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' ')
			return (true);
		i++;
	}
	return (false);
}

char	**get_args(char *input)
{
	char	**args;

	if (!input || check_spaces(input) == false)
		return (NULL);
	args = ft_split(input, ' ');
	return (args);
}

char	*get_prompt(void)
{
	char	*prompt;
	char	*buffer;

	buffer = malloc(sizeof(char) * 201);
	buffer = getcwd(buffer, 200);
	prompt = ft_strjoin(ft_strrchr(buffer, '/') + 1, ": ");
	free(buffer);
	return (prompt);
}
