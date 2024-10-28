/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:28:00 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/28 11:32:57 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_status(t_philo *philo, char *status)
{
	//if (philo->data->stop_sim == true)
	//	return ;
	pthread_mutex_lock(&philo->data->print_lock);
	printf("[%ld] %d %s\n", get_time() - philo->data->sim_start, philo->philo_id, status);
	pthread_mutex_unlock(&philo->data->print_lock);
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

long	get_timestamp(t_philo *philo)
{
	struct timeval	current_time;
	long	now;

	gettimeofday(&current_time, NULL);
	now = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (now - philo->data->sim_start);
}

void	stop_thread(int	time_ms)
{
	long	now;

	now = get_time();
	while ((get_time() - now) < time_ms)
	{
		usleep(10);
	}
}
