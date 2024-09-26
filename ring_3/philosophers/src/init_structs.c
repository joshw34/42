/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:29:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/26 11:16:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	t_philo	init_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->philos = malloc(data->n_philos * sizeof(t_philo));
	if (!data->philos)
		return (NULL);
	while (i < data->n_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->philo_id = i + 1;
		philos[i]->t_ate = 0;
		if (i == 0)
			philos[i]->forks[0] = data->n_philos - 1;
		else
			philos[i]->forks[0] = i - 1;
		philos[i]->forks[1] = i;
		philos[i]->t_last_meal = data->sim_start;
		pthread_mutex_init(&philos[i]->last_meal_lock, NULL);
		philos[i]->data = data;
		i++;
	}
	return (philos);
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
		|| data->t_eat == 0 || data -> t_sleep == 0 || data->n_eat == 0)
		return (false);
	return (true);
}

t_data	*init_structs(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (error_exit(data, ERROR_1), NULL);
		
	if (init_data_struct(data, av) == false)
		return (error_exit(data, ERROR_0), NULL);
		
	if (init_forks(data) == false)
		return (error_exit(data, ERROR_2), NULL);

	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (error_exit(data, ERROR_4), NULL);
	
	data->philos = init_philos(data);
	return (data);
}
