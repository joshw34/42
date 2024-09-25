/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:29:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/25 13:33:03 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static	t_philo	**init_philos(t_data *data)
{
	unsigned int	i;
	t_philo			**philos;

	i = 0;
	philos = malloc(data->n_philos * sizeof(t_philo));
	if (!philos)
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

static	pthread_mutex_t	*init_forks(unsigned int n)
{
	unsigned int	i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(n * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (i < n)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_data	*init_structs(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->sim_start = get_time();
	data->n_philos = ft_atoi(av[0]);
	data->t_die = ft_atoi(av[1]);
	data->t_eat = ft_atoi(av[2]);
	data->t_sleep = ft_atoi(av[3]);
	if (av[4])
		data->n_eat = ft_atoi(av[4]);
	else
		data->n_eat = -1;
	data->fork_lock = init_forks(data->n_philos);
	pthread_mutex_init(&data->print_lock, NULL);
	data->philos = init_philos(data);
	return (data);
}
