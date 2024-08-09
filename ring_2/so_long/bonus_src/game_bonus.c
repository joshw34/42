/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:19:58 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/09 12:47:34 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	data->player_u = mlx_xpm_file_to_image(data->init, PLAYER_U, &x, &y);
	data->player_d = mlx_xpm_file_to_image(data->init, PLAYER_D, &x, &y);
	data->player_r = mlx_xpm_file_to_image(data->init, PLAYER_R, &x, &y);
	data->player_l = mlx_xpm_file_to_image(data->init, PLAYER_L, &x, &y);
	data->exit_c = mlx_xpm_file_to_image(data->init, EXIT_C, &x, &y);
	data->exit_o = mlx_xpm_file_to_image(data->init, EXIT_O, &x, &y);
	data->collect = mlx_xpm_file_to_image(data->init, COLLECT, &x, &y);
	data->fire = mlx_xpm_file_to_image(data->init, FIRE, &x, &y);
}

void	run_game(t_data *data)
{
	init_mlx(data);
	init_map(data);
	mlx_hook(data->win, DestroyNotify, 0, &win_close, data);
	mlx_expose_hook(data->win, &expose_win, data);
	mlx_key_hook(data->win, &key, data);
	mlx_loop(data->init);
}
