/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:52:54 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/26 12:53:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	else
		result = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		result[i] = min;
		i++;
		min++;
	}
	return (result);
}
