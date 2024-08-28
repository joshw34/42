/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:02 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/28 16:51:58 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	print_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->m_data->moves);
	put_image(data, 0, 0);
	mlx_string_put(data->init, data->win, 9, 16, 0x000000, "MOVES");
	mlx_string_put(data->init, data->win, 9, 28, 0x000000, moves);
	free(moves);
}

static	void	put_player(t_data *data, int a, int b)
{
	int		x;
	int		y;

	x = b * 48;
	y = a * 48;
	if ((a == data->m_data->p_row && b == data->m_data->p_col)
		|| a > data->m_data->p_row)
		mlx_put_image_to_window(data->init, data->win, data->player_d, x, y);
	if (a < data->m_data->p_row)
		mlx_put_image_to_window(data->init, data->win, data->player_u, x, y);
	if (b < data->m_data->p_col)
		mlx_put_image_to_window(data->init, data->win, data->player_l, x, y);
	if (b > data->m_data->p_col)
		mlx_put_image_to_window(data->init, data->win, data->player_r, x, y);
}

void	put_image(t_data *data, int a, int b)
{
	int		x;
	int		y;

	x = b * 48;
	y = a * 48;
	if (data->map[a][b] == '0')
		mlx_put_image_to_window(data->init, data->win, data->floor, x, y);
	if (data->map[a][b] == '1')
		mlx_put_image_to_window(data->init, data->win, data->wall, x, y);
	if (data->map[a][b] == 'P')
		put_player(data, a, b);
	if (data->map[a][b] == 'E' && data->m_data->c > 0)
		mlx_put_image_to_window(data->init, data->win, data->exit_c, x, y);
	if (data->map[a][b] == 'E' && data->m_data->c == 0)
		mlx_put_image_to_window(data->init, data->win, data->exit_o, x, y);
	if (data->map[a][b] == 'C')
		mlx_put_image_to_window(data->init, data->win, data->collect, x, y);
	if (data->map[a][b] == 'F')
		mlx_put_image_to_window(data->init, data->win, data->fire, x, y);
}

void	init_map(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->map[a])
	{
		b = 0;
		while (data->map[a][b] != '\0')
		{
			put_image(data, a, b);
			b++;
		}
		a++;
	}
	print_moves(data);
}
