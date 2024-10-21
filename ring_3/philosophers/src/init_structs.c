/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:29:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/21 14:32:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static	bool	init_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->philos = malloc(data->n_philos * sizeof(t_philo *));
	if (!data->philos)
		return (free_all(data, ERROR_3), false);
	while (i < data->n_philos)
	{
		data->philos[i] = malloc(sizeof(t_philo));
		if (!data->philos[i])
			return (free_all(data, ERROR_3), false);
		data->philos[i]->philo_id = i + 1;
		data->philos[i]->t_ate = 0;
		if (i == 0)
			data->philos[i]->forks[0] = data->n_philos - 1;
		else
			data->philos[i]->forks[0] = i - 1;
		data->philos[i]->forks[1] = i;
		data->philos[i]->t_last_meal = 0;
		data->philos[i]->data = data;
		i++;
	}
	return (true);
}

static	bool	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
	{
		data->print_lock_init = false;
		return (false);
	}
	data->print_lock_init = true;
	if (pthread_mutex_init(&data->time_lock, NULL) != 0)
	{
		data->time_lock_init = false;
		return (false);
	}
	data->time_lock_init = true;
	return (true);
}

static	bool	init_forks(t_data *data)
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

static	bool	init_data_struct(t_data *data, char **av)
{
	data->stop_sim = false;
	data->print_lock_init = false;
	data->sim_start = get_time();
	data->n_philos = ft_atoi(av[0]);
	data->t_die = ft_atoi(av[1]);
	data->t_eat = ft_atoi(av[2]);
	data->t_sleep = ft_atoi(av[3]);
	if (av[4])
		data->n_eat = ft_atoi(av[4]);
	else
		data->n_eat = -1;
	if (data->sim_start == 0 || data->n_philos == 0 || data->t_die == 0
		|| data->t_eat == 0 || data->t_sleep == 0 || data->n_eat == 0)
		return (false);
	return (true);
}

t_data	*init_structs(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (init_data_struct(data, av) == false)
		return (free_all(data, ERROR_1), NULL);
	if (init_forks(data) == false)
		return (free_all(data, ERROR_2), NULL);
	if (init_mutexes(data) == false)
		return (free_all(data, ERROR_4), NULL);
	if (init_philos(data) == false)
		return (NULL);
	return (data);
}
