/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshw <joshw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:52:09 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/24 13:30:52 by joshw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		t_id;
	unsigned int	philo_id;
	unsigned int	t_ate;
	time_t			t_last_meal;
	pthread_mutex_t	forks[2];
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	time_t			sim_start;
	unsigned int	n_philos;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				n_eat;
	pthread_mutex_t	*forks;
	pthread_t		print_lock;
	t_philo			**philos;
}	t_data;

/* parse_check_input.c */
t_data	*parse_input(char **argv);

/* free.c */
void	input_error_exit(t_data *input, char *message);

#endif