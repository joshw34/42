/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/07 15:25:21 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	data->player = NULL;
	data->exit1 = NULL;
	data->exit2 = NULL;
	data->collect = NULL;
	data->map = NULL;
	data->m_data = init_m_data_struct();
	return (data);
}
