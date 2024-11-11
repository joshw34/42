/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:29:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/11 15:50:39 by jwhitley         ###   ########.fr       */
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
		data->philos[i]->data = data;
		set_philo_data(data->philos[i], i);
		if (init_philo_mutexes(data->philos[i]) == false)
			return (free_all(data, ERROR_4), false);
		i++;
	}
	return (true);
}

static	bool	init_data_struct(t_data *data, char **av)
{
	data->stop_sim = false;
	data->print_lock_init = false;
	data->sim_start = 0;
	data->n_philos = ft_atoi(av[0]);
	data->t_die = ft_atoi(av[1]);
	data->t_eat = ft_atoi(av[2]);
	data->t_sleep = ft_atoi(av[3]);
	if (av[4])
		data->n_eat = ft_atoi(av[4]);
	else
		data->n_eat = -1;
	if (data->n_philos < 1 || data->t_die < 1
		|| data->t_eat < 1 || data->t_sleep < 1 || data->n_eat == 0)
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
	if (init_data_mutexes(data) == false)
		return (free_all(data, ERROR_4), NULL);
	if (init_philos(data) == false)
		return (NULL);
	return (data);
}
