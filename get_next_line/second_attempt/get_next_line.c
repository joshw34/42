#include "get_next_line.h"
#include <stdio.h>

size_t	find_nl(char *total)
{
	size_t	i;

	i = 0;
	while (total[i])
	{
		if (total[i] == '\n')
			return (i);
		i++;
	}
	return (gnl_strlen(total) - 1);
}

char	*leftover(char *total, char *line, size_t index)
{
	char	*leftover;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen(total) - gnl_strlen(line);
	index++;
	if (total[index] == '\0')
	{
		free(total);
		return (NULL);
	}
	leftover = gnl_calloc(len + 1, sizeof(char));
	if (!leftover)
		return (NULL);
	while (i < len)
	{
		leftover[i] = total[index];
		i++;
		index++;
	}
	free(total);
	return (leftover);
}

char	*next_line(char *total, size_t index)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!total[0])
		return (NULL);
	result = gnl_calloc(index + 2, sizeof(char));
	if (!result)
		return (NULL);
	while (i <= index)
	{
		result[i] = total[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*read_file(int	fd, char *total)
{
	char	*temp;
	int		bytes_read;

	//if (total == NULL)
	//	total = gnl_calloc(1, 1);
	temp = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		if (total == NULL)
			total = gnl_calloc(1, 1);
		total = gnl_strjoin(total, temp);
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
	size_t		nl_index;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	nl_index = find_nl(buffer);
	line = next_line(buffer, nl_index);
	buffer = leftover(buffer, line, nl_index);
	return (line);
}
