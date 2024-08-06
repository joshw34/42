/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/06 15:57:36 by jwhitley         ###   ########.fr       */
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
	data->rows = 0;
	data->cols = 0;
	data->p_row = 0;
	data->p_col = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	return (data);
}
