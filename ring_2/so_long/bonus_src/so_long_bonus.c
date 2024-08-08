/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:34:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/08 15:42:15 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
