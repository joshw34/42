/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:37 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/28 14:12:00 by jwhitley         ###   ########.fr       */
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
	free_all(data, NULL);
	return (EXIT_SUCCESS);
}
