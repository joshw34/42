/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/09 12:42:21 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static	void	null_terminate(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line[i] = '\0';
}

char	*sl_gnl(int fd, char **buffer)
{
	char	*line;

	if (fd < 0)
		return (0);
	*buffer = read_file(fd, *buffer);
	if (!*buffer)
		return (NULL);
	line = next_line(*buffer);
	*buffer = leftover(*buffer);
	null_terminate(line);
	return (line);
}

static	t_m_data	*init_m_data_struct(void)
{
	t_m_data	*m_data;

	m_data = malloc(sizeof(t_m_data));
	if (!m_data)
	{
		perror("Struct malloc");
		exit(EXIT_FAILURE);
	}
	m_data->rows = 0;
	m_data->cols = 0;
	m_data->p_row = 0;
	m_data->p_col = 0;
	m_data->e_row = 0;
	m_data->e_col = 0;
	m_data->c = 0;
	m_data->e = 0;
	m_data->p = 0;
	m_data->moves = 0;
	return (m_data);
}

t_data	*init_data_struct(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Struct malloc");
		exit(EXIT_FAILURE);
	}
	data->init = NULL;
	data->win = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->player_u = NULL;
	data->player_d = NULL;
	data->player_r = NULL;
	data->player_l = NULL;
	data->exit_c = NULL;
	data->exit_o = NULL;
	data->collect = NULL;
	data->fire = NULL;
	data->map = NULL;
	data->m_data = init_m_data_struct();
	return (data);
}
