/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/06 14:59:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	if (think_time < 1)
	{
		print_status(philo, THINK);
		return ;
	}
	print_status(philo, THINK);
	stop_thread(think_time);
}

/*static	bool	take_forks(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]) != 0)
		return (false);
	print_status(philo, FORK);
	if (pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]) != 0)
	{
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
		print_status(philo, ERROR_0);
		return (false);
	}
	print_status(philo, FORK);
	return (true);
}*/

static	void	eat_sleep(t_philo *philo)
{
	while (check_stop(philo->data) == false)
	{
		pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
		print_status(philo, FORK);
		//while (take_forks(philo) == false)
		//	stop_thread(1);
		pthread_mutex_lock(&philo->last_meal_lock);
		philo->t_last_meal = get_time() - philo->data->sim_start;
		pthread_mutex_unlock(&philo->last_meal_lock);
		print_status(philo, EAT);
		stop_thread(philo->data->t_eat);
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
		pthread_mutex_lock(&philo->t_ate_lock);
		philo->t_ate++;
		pthread_mutex_unlock(&philo->t_ate_lock);
		print_status(philo, SLEEP);
		stop_thread(philo->data->t_sleep);
		think(philo);
	}
}

static	void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_time() < philo->data->sim_start)
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
	data->sim_start = get_time() + data->n_philos;
	if (data->n_philos > 1)
		pthread_create(&data->monitor, NULL, monitor, data);
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i]->t_id, NULL, start, data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i]->t_id, NULL);
		i++;
	}
	if (data->n_philos > 1)
		pthread_join(data->monitor, NULL);
}
