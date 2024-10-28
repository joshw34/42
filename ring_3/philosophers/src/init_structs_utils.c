/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:20 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/28 14:55:07 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_philo_data(t_philo *philo, unsigned int i)
{
	philo->philo_id = i + 1;
	philo->t_ate = 0;
	philo->finished = false;
	philo->t_last_meal = 0;
	if (i % 2 == 0)
	{
		philo->forks[0] = i;
		philo->forks[1] = (i + 1) % philo->data->n_philos;
	}
	else
	{
		philo->forks[0] = (i + 1) % philo->data->n_philos;
		philo->forks[1] = i;
	}
}

bool	init_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->fork_lock = malloc(data->n_philos * sizeof(pthread_mutex_t));
	if (!data->fork_lock)
		return (false);
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->fork_lock[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}
