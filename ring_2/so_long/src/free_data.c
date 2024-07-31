/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:33:13 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/31 15:44:27 by jwhitley         ###   ########.fr       */
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
	if (data->init != NULL)
		free(data->init);
	if (data->win != NULL)
		free(data->win);
	if (data->map != NULL)
		free_array(data->map);
	free(data);
}

void	error_exit(t_data *data, char *message)
{
	if (message != NULL)
		ft_putstr_fd(message, 2);
	free_data(data);
	exit(EXIT_FAILURE);
}
