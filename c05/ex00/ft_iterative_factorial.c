/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:35:09 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/21 15:35:52 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	fact = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb != 1)
	{
		fact = fact * (nb - 1);
		nb--;
	}
	return (fact);
}
