/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:34:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/06 17:03:47 by jwhitley         ###   ########.fr       */
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
	free_data(data);
	(void)argc;
	(void)argv;
	return (0);
}
