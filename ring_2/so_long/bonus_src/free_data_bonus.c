/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:33:13 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/28 17:32:37 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static	void	free_data_2(t_data *data)
{
	if (data->win != NULL)
		mlx_destroy_window(data->init, data->win);
	if (data->init != NULL)
	{
		mlx_destroy_display(data->init);
		free(data->init);
	}
	if (data->map != NULL)
		free_array(data->map);
	if (data->m_data != NULL)
		free(data->m_data);
	free(data);
}

void	free_data(t_data *data)
{
	if (data->floor != NULL)
		mlx_destroy_image(data->init, (data->floor));
	if (data->wall != NULL)
		mlx_destroy_image(data->init, data->wall);
	if (data->player_u != NULL)
		mlx_destroy_image(data->init, data->player_u);
	if (data->player_d != NULL)
		mlx_destroy_image(data->init, data->player_d);
	if (data->player_r != NULL)
		mlx_destroy_image(data->init, data->player_r);
	if (data->player_l != NULL)
		mlx_destroy_image(data->init, data->player_l);
	if (data->exit_c != NULL)
		mlx_destroy_image(data->init, data->exit_c);
	if (data->exit_o != NULL)
		mlx_destroy_image(data->init, data->exit_o);
	if (data->collect != NULL)
		mlx_destroy_image(data->init, data->collect);
	if (data->fire != NULL)
		mlx_destroy_image(data->init, data->fire);
	free_data_2(data);
}

void	success_exit(t_data *data, char *message)
{
	if (message != NULL)
		ft_putstr_fd(message, 1);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	error_exit(t_data *data, char *message)
{
	if (message != NULL)
		ft_putstr_fd(message, 2);
	free_data(data);
	exit(EXIT_FAILURE);
}
