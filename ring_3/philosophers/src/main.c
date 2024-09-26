/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:37 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/26 10:17:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (EXIT_FAILURE);
	data = init_structs(av + 1);
	if (!data)
		return (EXIT_FAILURE);
	/*unsigned int i = 0;
	while (i < data->n_philos)
	{
		printf("Philo ID: %d\n", data->philos[i]->philo_id);
		printf("Left Fork: %d\tRight Fork: %d\n\n", data->philos[i]->forks[0], data->philos[i]->forks[1]);
		i++;
	}*/
	return (0);
}
