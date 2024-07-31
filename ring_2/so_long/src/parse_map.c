#include "../inc/so_long.h"

void	copy_map(int fd, t_data *data)
{
	char	*buffer;
	char	*line;
	int		len;

	data->rows = 0;
	data->cols = -1;
	buffer = NULL;
	while (1)
	{
		line = sl_gnl(fd, &buffer);
		if (line == NULL)
			break ;
		ft_printf("TEST 2");
		ft_printf("%s", line);
		data->rows++;
		len = ft_strlen(line);
		if (data->cols != -1 && data->cols != len)
		{
			ft_putstr_fd("Error\nMap is Not Rectangular\n", 2);
			close(fd);
			error_exit(data);
		}
		data->cols = len;
		free(line);
	}
	free(buffer);
}

void	count_lines(int fd, t_data *data)
{
	char	*buffer;
	char	*line;
	int		len;

	data->rows = 0;
	data->cols = -1;
	buffer = NULL;
	ft_printf("TEST 1\n");
	while (1)
	{
		line = sl_gnl(fd, &buffer);
		if (line == NULL)
			break ;
		ft_printf("%s", line);
		data->rows++;
		len = ft_strlen(line);
		if (data->cols != -1 && data->cols != len)
		{
			ft_putstr_fd("Error\nMap is Not Rectangular\n", 2);
			close(fd);
			error_exit(data);
		}
		data->cols = len;
		free(line);
	}
	free(buffer);
}

void	check_argc_ext(int argc, char *map, t_data *data)
{
	int	ext;
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr_fd("Error\nMap File Not Specified\n", 2);
		else
			ft_putstr_fd("Error\nToo many arguments\n", 2);
		error_exit(data);
	}
	ext = ft_strlen(map) - 4;
	if (ft_strncmp(map + ext, ".ber", 4) != 0 || ft_strlen(map) < 5)
	{
		ft_putstr_fd("Error\nWrong mapfile type\n", 2);
		error_exit(data);
	}
}

void	parse_map(int argc, char *map, t_data *data)
{
	int	fd;
	check_argc_ext(argc, map, data);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMap file");
		error_exit(data);
	}
	count_lines(fd, data);
	copy_map(fd, data);
	close(fd);
}
