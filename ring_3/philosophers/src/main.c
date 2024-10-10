/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:37 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/10 15:06:00 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (print_error(ERROR_1), EXIT_FAILURE);
	data = init_structs(av + 1);
	if (!data)
		return (EXIT_FAILURE);
	run_sim(data);
	
	/*unsigned int i = 0;
	while (i < data->n_philos)
	{
		printf("Philo ID: %d\n", data->philos[i]->philo_id);
		printf("Left Fork: %d\tRight Fork: %d\n\n", data->philos[i]->forks[0] + 1, data->philos[i]->forks[1] + 1);
		i++;
	}*/

	unsigned int i = 0;
	printf("\nEach philo must eat %d times\n\n", data->n_eat);
	while (i < data->n_philos)
	{
		printf("philo %d has eaten %d times\n", data->philos[i]->philo_id, data->philos[i]->t_ate);
		i++;
	}
	free_all(data, "Success\n");
	return (EXIT_SUCCESS);
}
