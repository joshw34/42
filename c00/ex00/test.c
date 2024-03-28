/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:33 by jwhitley          #+#    #+#             */
/*   Updated: 2024/02/14 12:09:45 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(void)
{
	char	c;

	c = '9';
	ft_putchar(c);
	return (0);
}

/* (1=stdout, &c=starting address of buffer, 1=bytes to print) */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
