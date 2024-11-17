/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:21:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 16:21:50 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**get_args(char *input)
{
	char	**args;

	if (!input)
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
