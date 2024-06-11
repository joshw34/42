/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:32:02 by jwhitley          #+#    #+#             */
/*   Updated: 2024/03/06 15:32:04 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	print_int_element(int nb)
{
	int		i;
	char	number[11];

	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb = (nb * -1);
	}
	while (nb != 0 && nb != -2147483648)
	{
		number[i] = (48 + (nb % 10));
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &number[i - 1], 1);
		i--;
	}
	write(1, "\n", 1);
}

void	print_element(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		print_element(par[i].str);
		print_int_element(par[i].size);
		print_element(par[i].copy);
		i++;
	}
}
