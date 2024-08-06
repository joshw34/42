/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:23 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/06 17:27:33 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		error_exit(data, "Game Over: User pressed ESC");
	ft_printf("Collects Left: %d\n", data->m_data->c);
	return (0);
}
