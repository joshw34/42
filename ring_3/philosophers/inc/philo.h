/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:52:09 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/10 11:53:49 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

/* ERROR MESSAGES */
# define ERROR_0 "ERROR:\nMalloc Failure: Data Struct\n"
# define ERROR_1 "ERROR:\nInvalid Input\n"
# define ERROR_2 "ERROR:\nFailed to initialise Forks\n"
# define ERROR_3 "ERROR:\nMalloc Failure: Philo Struct\n"
# define ERROR_4 "ERROR:\nFailed to initialise mutex\n"

/* STATUS MESSAGES */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

/* STRUCTS */
typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t		t_id;
	unsigned int	philo_id;
	unsigned int	t_ate;
	unsigned int	forks[2];
	time_t			t_last_meal;
	pthread_mutex_t	last_meal_lock;
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
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	print_lock;
	bool			print_lock_init;
	t_philo			**philos;
}	t_data;

/* FUNCTION PROTOTYPES */
/* init_structs.c */
t_data	*init_structs(char **av);

/* free.c */
void	print_error(char *str);
void	free_all(t_data *data, char *error_message);

/* utils.c */
void	print_status(t_philo *philo, char *status);
int		ft_atoi(char *str);
long	get_time(void);

/* run_sim.c */
void	*eat(void *arg);
void	run_sim(t_data *data);

#endif