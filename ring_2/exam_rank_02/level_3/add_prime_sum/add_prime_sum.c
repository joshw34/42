/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:40:10 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/31 15:32:27 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static	void	print_n(int n)
{
	char	result[11];
	int		i;
	
	i = 0;
	while (n > 0)
	{
		result[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &result[i], 1);
		i--;
	}
}

static	int	is_prime_n(int n)
{
	int	i;
	
	if (n <= 1)
		return (1);
	if (n <= 3)
		return (0);
	if (n % 2 == 0 || n % 3 == 0)
		return (1);
	i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (1);
		i = i + 6;
	}
	return (0);
}

static	void	add_prime_sum(int n)
{
	int	result;
	
	result = 0;
	while (n > 0)
	{
		if (is_prime_n(n) == 0)
			result = result + n;
		n--;
	}
	print_n(result);
}

static	int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - 48);
		else
			return (-1);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	n;
	
	n = ft_atoi(argv[1]);
	if (argc == 2 && n > 0)
		add_prime_sum(n);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
