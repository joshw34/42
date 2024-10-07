/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/07 13:58:17 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, FORK);
}

void	run_sim(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (i % 2 == 0)
			eat(data->philos[i]);
		else
			print_status(data->philos[i], "chilling");
		usleep(50000);
		i++;
	}
}