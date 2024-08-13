/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/13 15:05:12 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 10;
	printf("BEFORE: a = %d\tb = %d\n", a, b);
	ft_swap(&a, &b);
	printf("AFTER:  a = %d\tb = %d\n", a, b);
}*/
