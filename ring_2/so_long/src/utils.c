/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:35:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/31 18:57:29 by jwhitley         ###   ########.fr       */
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
	data->map = NULL;
	data->rows = 0;
	data->cols = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	return (data);
}
