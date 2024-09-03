/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:13:06 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/03 12:57:14 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char	result = 0;
	while (i > 0)
	{
		result = (result * 2) + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	(void)argc;
	int	i = atoi(argv[1]);
	unsigned char result = reverse_bits(i);
	printf("%d\n", result);
}