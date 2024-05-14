/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:18:47 by jwhitley          #+#    #+#             */
/*   Updated: 2024/05/14 17:16:38 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*trim(char *result)
{
	char	*temp;
	size_t	i;

	i = gnl_check_nl(result);
	if (result[i] == '\0')
		return (NULL);
	temp = gnl_strdup(result + i + 1);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	if (i > 0)
		result[i + 1] = '\0';
	return (temp);
}

char	*read_file(char	*buffer, char *leftover, int fd)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!leftover)
			leftover = gnl_strdup("");
		temp = leftover;
		leftover = gnl_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (gnl_check_nl(leftover) > 0)
			break ;
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	result = read_file(buffer, leftover, fd);
	free(buffer);
	if (!result)
		return (NULL);
	leftover = trim(result);
	return (result);
}
