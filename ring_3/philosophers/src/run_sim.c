/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/10 11:48:28 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*eat(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	//printf("philo %d starting\n", philo->philo_id);
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, FORK);
	usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
	print_status(philo, "put down fork");
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, "put down fork");
	return (NULL);
}

void	run_sim(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philos)
	{
		//pthread_create(&data->philos[i]->t_id, NULL, eat, data->philos[i]);
		if (i % 2 == 0)
			pthread_create(&data->philos[i]->t_id, NULL, eat, data->philos[i]);
			//eat(data->philos[i]);
		/*else
			print_status(data->philos[i], "chilling");*/
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i]->t_id, NULL);
		i++;
	}
}