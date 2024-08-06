/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:34:31 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/06 17:05:04 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	void	copy_map(int fd, t_data *data)
{
	char	*buffer;
	int		i;

	buffer = NULL;
	i = 0;
	data->map = malloc((data->m_data->rows + 1) * sizeof(char *));
	while (i < data->m_data->rows)
	{
		data->map[i] = sl_gnl(fd, &buffer);
		i++;
	}
	data->map[i] = NULL;
	free(buffer);
}

static	void	count_lines(int fd, t_data *data)
{
	char	*buffer;
	char	*line;

	buffer = NULL;
	data->m_data->rows = 0;
	while (1)
	{
		line = sl_gnl(fd, &buffer);
		if (line == NULL)
			break ;
		data->m_data->rows++;
		free(line);
	}
	free(buffer);
}

static	void	check_argc_ext(int argc, char *map, t_data *data)
{
	int	ext;

	if (argc != 2)
	{
		if (argc == 1)
			error_exit(data, "Error\nMap File Not Specified\n");
		else
			error_exit(data, "Error\nToo many arguments\n");
	}
	ext = ft_strlen(map) - 4;
	if (ft_strncmp(map + ext, ".ber", 4) != 0 || ft_strlen(map) < 5)
		error_exit(data, "Error\nWrong mapfile type\n");
}

void	parse_map(int argc, char *map, t_data *data)
{
	int	fd;

	check_argc_ext(argc, map, data);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMap file");
		error_exit(data, "");
	}
	count_lines(fd, data);
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMap file");
		error_exit(data, "");
	}
	copy_map(fd, data);
	close(fd);
}
