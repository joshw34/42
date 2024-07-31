#include "../inc/so_long.h"

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
	//ft_printf("%s\n", line);
	return (line);
}
