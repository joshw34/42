/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:13:00 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/22 15:14:04 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	while (power > 0 && power != 1)
	{
		result = (result * nb);
		power--;
	}
	return (result);
}
