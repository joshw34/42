/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:01:39 by jwhitley          #+#    #+#             */
/*   Updated: 2024/04/18 12:01:41 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	min;
	int	max;

	if (nb > 2147395600 || nb < 1)
		return (0);
	else if ((nb / 2) > 46340)
		min = 46340;
	else
		min = nb / 2;
	while ((min * min) > nb)
	{
		min = (min / 2);
	}
	max = min * 2;
	while (min <= max)
	{
		if ((min * min) == nb)
			return (min);
		min++;
	}
	return (0);
}
