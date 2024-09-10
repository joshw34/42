/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshw <joshw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:34:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/10 17:13:50 by joshw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data_struct();
	parse_map(argc, argv[1], data);
	check_map_data(data);
	validate_map(data);
	run_game(data);
	return (0);
}
