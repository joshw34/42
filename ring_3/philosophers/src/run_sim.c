/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/22 13:32:45 by jwhitley         ###   ########.fr       */
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
	while (data->stop_sim == false)
	{
		while (i < data->n_philos && data->stop_sim == false)
		{
			if (data->philos[i]->t_last_meal < get_timestamp(data->philos[i]) - data->t_die && data->philos[i]->finished == false)
			{
				print_status(data->philos[i], DIED);
				data->stop_sim = true;
				return (NULL);
			}
			else if (data->philos[i]->t_ate == (unsigned int)data->n_eat && data->philos[i]->finished == false)
			{
				data->philos[i]->finished = true;
				printf("%d\t finished = %d\n", data->philos[i]->philo_id, data->philos[i]->finished);
			}
			i++;
		}
		usleep(10000);
		i = 0;
	}
	return (NULL);
}*/

/*static	void	think_sleep(t_philo *philo)
{
	//unsigned int	think_time;
	
	//if (philo->data->stop_sim == true)
	//	return ;
	//think_time = (philo->data->t_die - philo->data->t_sleep - philo->data->t_eat) / 2;
	//print_status(philo, SLEEP);philo 1 has eaten 201 times

	//usleep(philo->data->t_sleep * 1000);
	print_status(philo, SLEEP);
	usleep(philo->data->t_sleep * 1000);
	print_status(philo, THINK);
	usleep(5000);
	eat(philo);	
}*/

static	void	eat(t_philo *philo)
{
	if (philo->data->stop_sim == true || philo->finished == true)
		return ;
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, FORK);
	philo->t_last_meal = get_timestamp(philo);
	usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
	philo->t_ate++;
	print_status(philo, SLEEP);
	usleep(philo->data->t_sleep * 1000);
	print_status(philo, THINK);
	usleep(10000);
	eat(philo);
	//think_sleep(philo);
}

static	void	*start(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->sim_start == 0)
	{
		
	}
	if (philo->philo_id % 2 != 0)
		eat(philo);
	else
	{
		usleep(philo->data->t_eat);
		eat(philo);
		//think_sleep(philo);
	}
	return (NULL);
}

void	run_sim(t_data *data)
{
	unsigned int	i;

	i = 0;
	//pthread_create(&data->monitor, NULL, monitor, data);
	data->sim_start = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i]->t_id, NULL, start, data->philos[i]);
		//pthread_detach(data->philos[i]->t_id);
		i++;
	}
	data->sim_start = get_time();
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i]->t_id, NULL);
		i++;
	}
	//pthread_join(data->monitor, NULL);
}