/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:22:32 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/03 18:41:54 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_digit(char c, int base)
{
	int		i;
	char	hex_chars[] = "0123456789abcdef";
	
	i = 0;
	if (c >= 'A' && c <= 'F')
		c = c + 32;
	while (i < base)
	{
		if (hex_chars[i] == c)
				return (i);
		i++;
	}
	return (-1);
}

int	last(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = last(str);
	int	result = 0;
	int	base = 1;
	int	digit = -1;
	int sign = 1;
	
	
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (i >= 0)
	{
		digit = get_digit(str[i], str_base);
		if (digit == -1)
			break ;
		result = result + (digit * base);
		i--;
		base = base * str_base;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int result;
	(void)argc;

	result = ft_atoi_base(argv[1], atoi(argv[2]));
	(void)result;
	printf("%d\n", result);
}
