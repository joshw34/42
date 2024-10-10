/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:28:00 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/10 11:53:38 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_status(t_philo *philo, char *status)
{
	printf("[%ld] %d %s\n", get_time(), philo->philo_id, status);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - 48);
		else
			return (0);
		i++;
	}
	return (result);
}

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
