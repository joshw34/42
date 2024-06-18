/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:35:57 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:35:58 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (sign * result);
}

static	bool	check_repeat(char *str, char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_strlen(str) == ft_strlen(input[i]))
		{
			if (ft_strncmp(str, input[i], ft_strlen(str)) == 0)
				return (false);
		}
		i++;
	}
	return (true);
}

static	bool	check_format(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	if (ft_isdigit(str[i]) == 0 && str[i] != '+' && str[i] != '-')
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	return (true);
}

bool	check_error(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!check_format(input[i]))
			return (false);
		if (!check_repeat(input[i], input + i + 1))
			return (false);
		i++;
	}
	return (true);
}
