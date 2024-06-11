/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:35:38 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/15 18:36:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	x;
	int	y;

	x = 20;
	y = 8;
	printf("Before: *a = %d   *b = %d", x, y);
	ft_ultimate_div_mod(&x, &y);
	printf("\nAfter:  *a = %d   *b = %d", x, y);
	return (0);
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tempx;
	int	tempy;

	tempx = *a / *b;
	tempy = *a % *b;
	*a = tempx;
	*b = tempy;
}
