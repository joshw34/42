/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:37 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/24 15:25:46 by jwhitley         ###   ########.fr       */
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
	else
		printf("%ld\n", data->sim_start);
}
