/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:43:50 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/26 13:44:30 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = malloc((sizeof(int) * (max - min)));
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	*range = array;
	return (i);
}
