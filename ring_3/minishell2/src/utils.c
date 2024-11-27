/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:59:56 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/27 14:04:15 by jwhitley         ###   ########.fr       */
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
