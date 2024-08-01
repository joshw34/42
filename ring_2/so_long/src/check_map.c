/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:27:07 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/01 14:21:27 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	void	check_game_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c++;
			if (data->map[i][j] == 'E')
				data->e++;
			if (data->map[i][j] == 'P')
				data->p++;
			j++;
		}
		i++;
	}
	if (data->c < 1)
		error_exit(data, "Error\nAt least 1 collectible required\n");
	if (data->e != 1)
		error_exit(data, "Error\nOne exit must be specified\n");
	if (data->p != 1)
		error_exit(data, "Error\nOne player start position must be specified\n");
}

static	void	check_content(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
			{
				error_exit(data, "Error\nInvalid Character in Map File\n");
			}
			if (c == 'P')
			{
				data->p_row = i;
				data->p_col = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static	void	check_walls(t_data *data)
{
	int	i;
	int	j;
	int	last_row;
	int	last_col;

	i = 0;
	last_row = data->rows - 1;
	last_col = ft_strlen(data->map[0]) - 1;
	while (data->map[i])
	{
		j = 0;
		if (i == 0 || i == last_row)
		{
			while (data->map[i][j])
			{
				if (data->map[i][j] != '1')
					error_exit(data, "Error\nMap Not Enclosed by Walls\n");
				j++;
			}
		}
		else
			if (data->map[i][0] != '1' || data->map[i][last_col] != '1')
				error_exit(data, "Error\nMap Not Enclosed by Walls\n");
		i++;
	}
}

static	void	check_shape(t_data *data)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		tmp = ft_strlen(data->map[i]);
		if (len != tmp)
			error_exit(data, "Error\nMap is not Rectangular\n");
		i++;
	}
	data->cols = len;
}

void	check_map_data(t_data *data)
{
	check_shape(data);
	check_walls(data);
	check_content(data);
	check_game_elements(data);
}
