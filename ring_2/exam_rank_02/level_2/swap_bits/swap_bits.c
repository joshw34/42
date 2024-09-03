/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:34:37 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/03 12:59:51 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char result;

	result = ((octet >> 4) | (octet << 4));
	return (result);
}

int	main(int argc, char **argv)
{
	(void)argc;
	int	number = atoi(argv[1]);
	unsigned char result = swap_bits(number);
	printf("%d\n", result);
}