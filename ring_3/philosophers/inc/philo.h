/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:52:09 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/25 13:52:28 by jwhitley         ###   ########.fr       */
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
# define ERROR_1 "ERROR: Malloc Failure: Data Struct\n"
# define ERROR_2 "ERROR: Malloc Failure: Forks\n"
# define ERROR_3 "ERROR\nMalloc Failure: Philo Struct\n"

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
	t_philo			**philos;
}	t_data;

/* FUNCTION PROTOTYPES */
/* init_structs.c */
t_data	*init_structs(char **av);

/* free.c */
void	free_philos(t_philo **philos);
void	data_error_exit(t_data *input, char *message);

/* utils.c */
void	write_error(char *str);
int		ft_atoi(char *str);
time_t	get_time(void);

#endif