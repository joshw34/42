/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:23 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/06 16:34:05 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key(int keysym, t_data *data)
{
	int	row;
	int	col;

	row = data->p_row;
	col = data->p_col;
	if (keysym == W || keysym == UP || keysym == S || keysym == DN)
		up_down(data, row, col, keysym);
	if (keysym == A || keysym == LT || keysym == D || keysym == RT)
		left_right(data, row, col, keysym);
	if (keysym == ESC)
		error_exit(data, "Game Over: User pressed ESC");
	return (0);
}
