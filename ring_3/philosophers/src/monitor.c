/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:12:20 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/05 21:46:29 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static	void	check_if_sim_done(t_data *data, unsigned int done)
{
	if (done == data->n_philos)
	{
		pthread_mutex_lock(&data->stop_sim_lock);
		data->stop_sim = true;
		pthread_mutex_unlock(&data->stop_sim_lock);
	}
}

static	bool	check_eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->t_ate_lock);
	if (philo->t_ate == (unsigned int)philo->data->n_eat && philo->finished
		== false)
	{
		pthread_mutex_unlock(&philo->t_ate_lock);
		philo->finished = true;
		return (true);
	}
	pthread_mutex_unlock(&philo->t_ate_lock);
	return (false);
}

static	bool	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	if (philo->t_last_meal < get_time() - philo->data->sim_start
		- philo->data->t_die)
	{
		pthread_mutex_unlock(&philo->last_meal_lock);
		pthread_mutex_lock(&philo->data->stop_sim_lock);
		philo->data->stop_sim = true;
		pthread_mutex_unlock(&philo->data->stop_sim_lock);
		pthread_mutex_lock(&philo->data->print_lock);
		printf("[%ld] %d %s\n", get_time() - philo->data->sim_start,
			philo->philo_id, DIED);
		pthread_mutex_unlock(&philo->data->print_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->last_meal_lock);
	return (false);
}

void	*monitor(void *arg)
{
	t_data			*data;
	unsigned int	i;
	unsigned int	done;

	data = (t_data *)arg;
	done = 0;
	i = 0;
	while (get_time() < data->philos[i]->data->sim_start)
		usleep(10);
	while (check_stop(data) == false)
	{
		while (i < data->n_philos)
		{
			if (check_if_dead(data->philos[i]) == true)
				return (NULL);
			if (check_eaten_enough(data->philos[i]) == true)
				done++;
			i++;
		}
		check_if_sim_done(data, done);
		stop_thread(5);
		i = 0;
	}
	return (NULL);
}
