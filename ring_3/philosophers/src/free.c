/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:46:06 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/31 13:37:18 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

static	void	free_waiter(t_data *data)
{
	if (data->waiter->fork_check_lock_init == true)
		pthread_mutex_destroy(&data->waiter->fork_check_lock);
	free(data->waiter);
}

static	void	free_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->fork_lock[i]);
		i++;
	}
	free(data->fork_lock);
}

static	void	free_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (data->philos[i]->last_meal_lock_init == true)
			pthread_mutex_destroy(&data->philos[i]->last_meal_lock);
		if (data->philos[i]->t_ate_lock_init == true)
			pthread_mutex_destroy(&data->philos[i]->t_ate_lock);
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
}

void	free_all(t_data *data, char *error_message)
{
	if (data)
	{
		if (data->philos)
			free_philos(data);
		if (data->fork_lock)
			free_forks(data);
		if (data->print_lock_init == true)
			pthread_mutex_destroy(&data->print_lock);
		if (data->waiter)
			free_waiter(data);
		free(data);
	}
	if (error_message)
		print_error(error_message);
}
