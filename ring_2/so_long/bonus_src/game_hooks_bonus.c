/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:23 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/08 15:44:16 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	win_close(t_data *data)
{
	success_exit(data, "Game Over: User Closed Window\n");
	return (0);
}

int	expose_win(t_data *data)
{
	init_map(data);
	return (0);
}

int	key(int keysym, t_data *data)
{
	int	row;
	int	col;

	row = data->m_data->p_row;
	col = data->m_data->p_col;
	if (keysym == W || keysym == UP || keysym == S || keysym == DN)
		up_down(data, row, col, keysym);
	if (keysym == A || keysym == LT || keysym == D || keysym == RT)
		left_right(data, row, col, keysym);
	if (keysym == ESC)
		success_exit(data, "Game Over: User pressed ESC\n");
	if (data->map[data->m_data->e_row][data->m_data->e_col] == 'P')
		success_exit(data, "Game Over: You Win\n");
	return (0);
}
