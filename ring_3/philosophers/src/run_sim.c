/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:38:08 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/24 16:51:18 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static	void	eat(t_philo *philo);

static	void	*monitor(void *arg)
{	
	unsigned int	i;
	unsigned int	done;
	t_data	*data;

	data = (t_data *)arg;
	done = 0;
	if (data->n_philos == 1)
		return (NULL);
	i = 0;
	while (data->philos[i]->data->sim_start == 0)
		usleep(10);
	while (data->stop_sim == false)
	{
		while (i < data->n_philos)
		{
			pthread_mutex_lock(&data->philos[i]->last_meal_lock);
			if (data->philos[i]->t_last_meal < get_timestamp(data->philos[i]) - data->t_die)
			{
				pthread_mutex_unlock(&data->philos[i]->last_meal_lock);
				data->stop_sim = true;
				printf("[%ld] %d %s\n", get_timestamp(data->philos[i])
					, data->philos[i]->philo_id, DIED);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philos[i]->last_meal_lock);
			if (data->philos[i]->t_ate == (unsigned int)data->n_eat && data->philos[i]->finished == false)
			{
				data->philos[i]->finished = true;
				done++;
			}
			i++;
		}
		if (done == data->n_philos)
			data->stop_sim = true;
		usleep(10000);
		i = 0;
	}
	return (NULL);
}

static	void	think_sleep(t_philo *philo)
{
	unsigned int	think_time;
	
	//if (philo->data->stop_sim == true)
	//	return ;
	think_time = (philo->data->t_die - (get_timestamp(philo) - philo->t_last_meal)) / 2;
	//printf("philo %d (%d - (%ld - %ld)) / 2 = %d\n", philo->philo_id, philo->data->t_die, get_timestamp(philo), philo->t_last_meal, think_time);
	//printf("philo %d think time = %d\n", philo->philo_id, think_time);
	//print_status(philo, SLEEP);philo 1 has eaten 201 times

	//usleep(philo->data->t_sleep * 1000);
	//print_status(philo, SLEEP);
	//usleep(philo->data->t_sleep * 1000);
	print_status(philo, THINK);
	//printf("philo %d thinktime = %d\n", philo->philo_id, think_time);
	/*if (think_time <= 3)
	{
		printf("[%ld] philo %d finished thinking\n", get_timestamp(philo), philo->philo_id);
		return ;
	}*/
	//if (philo->data->n_philos % 2 != 0)
	//else
	stop_thread(think_time);
	//printf("[%ld] philo %d finished thinking\n", get_timestamp(philo), philo->philo_id);
	//else
	//	stop_thread(think_time);
	//	usleep(10);
		//usleep(10);
	//	stop_thread(1);
	//usleep(5000);
	//eat(philo);	
}

static	void	single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, FORK);
	stop_thread(philo->data->t_die);
	pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
	print_status(philo, DIED);
}

static	void	eat(t_philo *philo)
{
	while (philo->data->stop_sim == false /*&& philo->finished == false*/)
	{
		if (philo->data->stop_sim == true)
			return ;
		//while (ask_waiter(philo->data, philo->forks[0], philo->forks[1]) == false)
			//stop_thread(1);
		//	usleep(10);
		ask_waiter(philo->data, philo->forks[0], philo->forks[1]);
		pthread_mutex_lock(&philo->data->fork_lock[philo->forks[0]]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->data->fork_lock[philo->forks[1]]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->last_meal_lock);
		philo->t_last_meal = get_timestamp(philo);
		pthread_mutex_unlock(&philo->last_meal_lock);
		print_status(philo, EAT);
		//printf("[%ld] philo %d last meal at %ld\n", get_timestamp(philo), philo->philo_id, philo->t_last_meal);
		stop_thread(philo->data->t_eat);
		//printf("[%ld] %d fork0 down = %d\n", get_timestamp(philo), philo->philo_id, pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]));
		//printf("[%ld] %d fork1 down = %d\n", get_timestamp(philo), philo->philo_id, pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]));
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[0]]);
		pthread_mutex_unlock(&philo->data->fork_lock[philo->forks[1]]);
		tell_waiter(philo->data, philo->forks[0], philo->forks[1]);
	//	printf("[%ld] philo %d fork down\n", get_timestamp(philo), philo->philo_id);
		philo->t_ate++;
		if (philo->data->stop_sim == true)
			return ;
		print_status(philo, SLEEP);
		stop_thread(philo->data->t_sleep);
		if (philo->data->stop_sim == true)
			return ;
		think_sleep(philo);
	}
}

static	void	*start(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->sim_start == 0)
		usleep(10);
	if (philo->data->n_philos == 1)
		single_philo(philo);
	else if (philo->philo_id % 2 == 0)
		eat(philo);
	else
	{
		//usleep(philo->data->t_eat);
		stop_thread(philo->data->t_eat);
		//usleep(100);
		//think_sleep(philo);
		eat(philo);
		//think_sleep(philo);
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
