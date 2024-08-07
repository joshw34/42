/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:33:13 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/07 12:10:07 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	free_data(t_data *data)
{
	if (data->floor != NULL)
		mlx_destroy_image(data->init, (data->floor));
	if (data->wall != NULL)
		mlx_destroy_image(data->init, data->wall);
	if (data->player != NULL)
		mlx_destroy_image(data->init, data->player);
	if (data->exit1 != NULL)
		mlx_destroy_image(data->init, data->exit1);
	if (data->exit2 != NULL)
		mlx_destroy_image(data->init, data->exit2);
	if (data->collect != NULL)
		mlx_destroy_image(data->init, data->collect);
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
