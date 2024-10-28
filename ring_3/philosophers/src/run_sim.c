/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/28 15:17:59 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static	void	eat_sleep(t_philo *philo);

static	void	single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, FORK);
	stop_thread(philo->data->t_die);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, DIED);
}

static	void	think(t_philo *philo)
{
	unsigned int	think_time;

	think_time = (philo->data->t_die - (get_time() - philo->data->sim_start
				- philo->t_last_meal)) / 2;
	if (think_time <= 3)
		return ;
	print_status(philo, THINK);
	stop_thread(think_time);
}

static	void	eat_sleep(t_philo *philo)
{
	while (philo->data->stop_sim == false)
	{
		ask_waiter(philo->data, philo->forks[0], philo->forks[1]);
		pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->last_meal_lock);
		philo->t_last_meal = get_time() - philo->data->sim_start;
		pthread_mutex_unlock(&philo->last_meal_lock);
		print_status(philo, EAT);
		stop_thread(philo->data->t_eat);
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
		tell_waiter(philo->data, philo->forks[0], philo->forks[1]);
		philo->t_ate++;
		print_status(philo, SLEEP);
		stop_thread(philo->data->t_sleep);
		think(philo);
	}
}

static	void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->sim_start == 0)
		usleep(10);
	if (philo->data->n_philos == 1)
		single_philo(philo);
	else if (philo->philo_id % 2 == 0)
		eat_sleep(philo);
	else
	{
		stop_thread(philo->data->t_eat);
		eat_sleep(philo);
	}
	return (NULL);
}

void	run_sim(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->sim_start = 0;
	if (data->n_philos > 1)
		pthread_create(&data->monitor, NULL, monitor, data);
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i]->t_id, NULL, start, data->philos[i]);
		i++;
	}
	data->sim_start = get_time();
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i]->t_id, NULL);
		i++;
	}
	if (data->n_philos > 1)
		pthread_join(data->monitor, NULL);
}
