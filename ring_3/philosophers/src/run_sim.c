/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/10 15:01:10 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static	void	eat(t_philo *philo);

/*static	void	*monitor(void *arg)
{
	unsigned int	i;
	t_data	*data;

	data = (t_data *)arg;
	i = 0;
	while (0)
	{
		while (data->philos[i])
		{
			if (data->philos[i]->t_ate == data->n_eat)
				pthread_kill()
			i++;
		}
		i = 0;
	}
	return (NULL);
}*/

static	void	think_sleep(t_philo *philo)
{
	unsigned int	think_time;
	
	think_time = (philo->data->t_die - philo->data->t_sleep) / 2;
	print_status(philo, SLEEP);
	usleep(philo->data->t_sleep * 1000);
	print_status(philo, THINK);
	usleep(think_time * 1000);
	eat(philo);	
}

static	void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, FORK);
	philo->t_last_meal = get_time();
	usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
	philo->t_ate++;
	if ((int)philo->t_ate == philo->data->n_eat)
		return ;
	think_sleep(philo);
}

static	void	*start(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		eat(philo);
	else
		think_sleep(philo);
	return (NULL);
}

void	run_sim(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i]->t_id, NULL, start, data->philos[i]);
		i++;
	}
	//pthread_create(&data->monitor, NULL, monitor, data);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i]->t_id, NULL);
		i++;
	}
}