/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshw <joshw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:05:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/24 13:34:41 by joshw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - 48);
		else
			return (0);
		i++;
	}
	return (result);
}

t_data	*parse_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if(!data)
		return (NULL);
	data->n_philos = ft_atoi(argv[0]);
	data->t_die = ft_atoi(argv[1]);
	data->t_eat = ft_atoi(argv[2]);
	data->t_sleep = ft_atoi(argv[3]);
	if (argv[4])
		data->n_eat = ft_atoi(argv[4]);
	else
		data->n_eat = -1;
	if (data->n_philos == 0 || data->t_die == 0 || data->t_eat == 0
		|| data->t_sleep == 0 || data->n_eat == 0)
	{
		data_error_exit(data, "Error: Invalid Arguments\n");
		return (NULL);
	}
	return (data);
}
