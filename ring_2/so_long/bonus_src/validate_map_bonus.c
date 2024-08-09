/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:57:51 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/09 12:46:39 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static	void	reset_game_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'C')
				data->m_data->c++;
			j++;
		}
		i++;
	}
	data->m_data->e = 1;
}

static	void	check_possible(t_data *data, char **temp, int r, int c)
{
	if (r < 0 || r >= data->m_data->rows || c < 0 || c >= data->m_data->cols)
		return ;
	if (temp[r][c] == '1' || temp[r][c] == 'X' || temp[r][c] == 'F')
		return ;
	else if (temp[r][c] == 'C')
		data->m_data->c--;
	else if (temp[r][c] == 'E')
	{
		data->m_data->e = 0;
		return ;
	}
	temp[r][c] = 'X';
	check_possible(data, temp, r, c + 1);
	check_possible(data, temp, r, c - 1);
	check_possible(data, temp, r + 1, c);
	check_possible(data, temp, r - 1, c);
}

static	char	**init_temp_map_array(t_data *data)
{
	char	**temp;
	int		i;

	temp = (char **)malloc((data->m_data->rows +1) * sizeof(char *));
	if (!temp)
	{
		perror("Error\nMalloc failed\n");
		error_exit(data, "");
	}
	i = 0;
	while (i < data->m_data->rows)
	{
		temp[i] = ft_strdup(data->map[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	validate_map(t_data *data)
{
	int		r;
	int		c;
	char	**temp;

	r = data->m_data->p_row;
	c = data->m_data->p_col;
	temp = init_temp_map_array(data);
	check_possible(data, temp, r, c);
	free_array(temp);
	if (data->m_data->c > 0)
		error_exit(data, "Error\nCollectible not reachable\n");
	if (data->m_data->e > 0)
		error_exit(data, "Error\nExit not reachable\n");
	reset_game_elements(data);
}
