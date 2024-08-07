/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:19:58 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/07 12:07:36 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	void	init_mlx(t_data *data)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = 48;
	y = 48;
	width = data->m_data->cols * x;
	height = data->m_data->rows * y;
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, width, height, "so_long");
	data->floor = mlx_xpm_file_to_image(data->init, FLOOR, &x, &y);
	data->wall = mlx_xpm_file_to_image(data->init, WALL, &x, &y);
	data->player = mlx_xpm_file_to_image(data->init, PLAYER, &x, &y);
	data->exit1 = mlx_xpm_file_to_image(data->init, EXIT1, &x, &y);
	data->exit2 = mlx_xpm_file_to_image(data->init, EXIT2, &x, &y);
	data->collect = mlx_xpm_file_to_image(data->init, COLLECT, &x, &y);
}

void	run_game(t_data *data)
{
	init_mlx(data);
	init_map(data);
	mlx_key_hook(data->win, &key, data);
	mlx_loop(data->init);
}
