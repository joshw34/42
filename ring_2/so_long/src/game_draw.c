/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:02 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/08 14:12:02 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_image(t_data *data, int a, int b)
{
	int		x;
	int		y;
	char	*moves;

	x = b * 48;
	y = a * 48;
	moves = ft_itoa(data->m_data->moves);
	if (data->map[a][b] == '0')
		mlx_put_image_to_window(data->init, data->win, data->floor, x, y);
	if (data->map[a][b] == '1')
		mlx_put_image_to_window(data->init, data->win, data->wall, x, y);
	if (data->map[a][b] == 'P')
		mlx_put_image_to_window(data->init, data->win, data->player, x, y);
	if (data->map[a][b] == 'E' && data->m_data->c > 0)
		mlx_put_image_to_window(data->init, data->win, data->exit1, x, y);
	if (data->map[a][b] == 'E' && data->m_data->c == 0)
		mlx_put_image_to_window(data->init, data->win, data->exit2, x, y);
	if (data->map[a][b] == 'C')
		mlx_put_image_to_window(data->init, data->win, data->collect, x, y);
	mlx_string_put(data->init, data->win, 0, 16, 0xFFFFFF, moves);
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
}
