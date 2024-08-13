/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:24:28 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/13 14:05:28 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int num)
{
	char	num_str[4];
	int		i;

	i = 0;
	while (num > 0)
	{
		num_str[i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	num_str[i] = '\0';
	i--;
	while (i >= 0)
	{
		write(1, &num_str[i], 1);
		i--;
	}
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if (i % 3 != 0 && i % 5 != 0)
			print_num(i);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
