/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:09:33 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/15 15:12:40 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	a;	

	a = 12;
	printf("Before: %d", a);
	ft_ft(&a);
	printf("\nAfter:  %d", a);
	return (0);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
