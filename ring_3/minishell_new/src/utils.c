/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:08:51 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/12 18:07:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

char	*get_realpwd(void)
{
	char	*ret;

	ret = ft_calloc(1024, sizeof(char));
	getcwd(ret, 1024);
	return (ret);
}
