/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:32:08 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/11 10:32:09 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_2d_array(char **array)
{
	char	**anchor;

	anchor = array;
	while (*array)
	{
		free(*array);
		++array;
	}
	free(anchor);
}
