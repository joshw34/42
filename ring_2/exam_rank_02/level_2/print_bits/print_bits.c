/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:49:03 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/03 12:53:38 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	unsigned char result = 0;
	
	while (i >= 0)
	{
		result = (octet >> i & 1) + '0';
		write(1, &result, 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	print_bits(atoi(argv[1]));
	write(1, "\n", 1);
}