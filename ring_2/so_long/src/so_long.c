/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:34:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/01 12:11:57 by jwhitley         ###   ########.fr       */
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
	return (0);
}

/*void	*init = mlx_init();
	void	*window = mlx_new_window(init, 500, 500, "Test Window");
	int x = 500;
	int y = 500;
	void	*background = mlx_xpm_file_to_image(init, "./assets/bg.xpm", &x, &y);
	if (background == NULL)
		return (ft_printf("FUCKED IT"), 1);
	mlx_put_image_to_window(init, window, background, 0, 0);
	mlx_string_put(init, window, 250, 250, 150210055, "FUCK");
	sleep(5);*/