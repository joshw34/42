/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:27:07 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/09 14:08:46 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	void	player_exit_loc(t_data *data, char c, int row, int col)
{
	if (c == 'P')
	{
		data->m_data->p_row = row;
		data->m_data->p_col = col;
	}
	if (c == 'E')
	{
		data->m_data->e_row = row;
		data->m_data->e_col = col;
	}
}

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
				data->m_data->c++;
			if (data->map[i][j] == 'E')
				data->m_data->e++;
			if (data->map[i][j] == 'P')
				data->m_data->p++;
			j++;
		}
		i++;
	}
	if (data->m_data->c < 1)
		error_exit(data, "Error\nAt least 1 collectible required\n");
	if (data->m_data->e != 1)
		error_exit(data, "Error\nOne exit must be specified\n");
	if (data->m_data->p != 1)
		error_exit(data, "Error\nOne player start position required\n");
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
				error_exit(data, "Error\nInvalid Character in Map File\n");
			if (c == 'P' || c == 'E')
				player_exit_loc(data, c, i, j);
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
	last_row = data->m_data->rows - 1;
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

void	check_map_data(t_data *data)
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
			error_exit(data, "Error\nLine empty or map not rectangular\n");
		i++;
	}
	data->m_data->cols = len;
	check_walls(data);
	check_content(data);
	check_game_elements(data);
}
