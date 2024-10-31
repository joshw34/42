/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:28:00 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/31 14:35:21 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_sim_lock);
	if (data->stop_sim == true)
	{
		pthread_mutex_unlock(&data->stop_sim_lock);
		return (true);
	}
	pthread_mutex_unlock(&data->stop_sim_lock);
	return (false);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->stop_sim_lock);
	if (philo->data->stop_sim == true)
	{
		pthread_mutex_unlock(&philo->data->stop_sim_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_sim_lock);
	pthread_mutex_lock(&philo->data->print_lock);
	printf("[%ld] %d %s\n", get_time() - philo->data->sim_start,
		philo->philo_id, status);
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

void	stop_thread(int time_ms)
{
	long	now;

	now = get_time();
	while ((get_time() - now) < time_ms)
	{
		usleep(10);
	}
}
