/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:59:56 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/06 14:34:16 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*parse_argv(char **argv)
{
	int		i;
	char	*result;
	char	*temp;

	i = 0;
	if (argv[i])
	{
		result = ft_strdup(argv[i]);
		i++;
	}
	while (argv[i])
	{
		temp = ft_strjoin(result, " ");
		free(result);
		result = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	printf("**%s**\n", result);
	return (result);
}

bool	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 7 && str[i] <= 13) && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}
