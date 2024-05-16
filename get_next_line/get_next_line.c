#include "get_next_line.h"
#include <stdio.h>

char	*join_free(char *total, char *buffer)
{
	char	*joined;

	joined = gnl_strjoin(total, buffer);
	free(total);
	return (joined);
}

char	*leftover(char *total)
{
	char	*leftover;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (total[i] && total[i] != '\n')
		i++;
	if (total[i] == '\0')
	{
		free(total);
		return (NULL);
	}
	leftover = gnl_calloc(gnl_strlen(total) - i + 1, sizeof(char));
	if (!leftover)
		return (NULL);
	i++;
	while (total[i])
	{
		leftover[j] = total[i];
		i++;
		j++;
	}
	free(total);
	return (leftover);
}

char	*next_line(char *total)
{
	char	*result;
	size_t	i;

	i = 0;
	if (total[i] == '\0')
		return (NULL);
	while (total[i] && total[i] != '\n')
		i++;
	result = gnl_calloc(i + 2, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (total[i] && total[i] != '\n')
	{
		result[i] = total[i];
		i++;
	}
	if (total[i] && total[i] =='\n')
		result[i++] = '\n';
	return (result);
}

char	*read_file(int	fd, char *total)
{
	char	*temp;
	int		bytes_read;

	if (!total)
		total = gnl_calloc(1, 1);
	temp = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		total = join_free(total, temp);
		if (gnl_strchr(temp, '\n') != 0)
			break ;
	}
	free(temp);
	return (total);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = next_line(buffer);
	buffer = leftover(buffer);
	return (line);
}
