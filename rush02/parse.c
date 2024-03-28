/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tovetouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:52 by tovetouc          #+#    #+#             */
/*   Updated: 2024/03/03 18:23:00 by tovetouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	get_dict_str(char *buffer, int buffer_size)
{
	int	dict;
	int	bytes_read;

	dict = open("numbers.dict", O_RDONLY);
	if (dict == -1)
		return (0);
	bytes_read = read(dict, buffer, buffer_size);
	if (bytes_read != buffer_size - 1)
		return (-1);
	close(dict);
	buffer[buffer_size - 1] = '\0';
	return (0);
}

int	get_dict_buffer_size(void)
{
	int		dict;
	int		bytes_read;
	int		buffer_size;
	char	buffer[10];

	buffer_size = 0;
	dict = open("numbers.dict", O_RDONLY);
	if (dict == -1)
		return (0);
	bytes_read = read(dict, buffer, sizeof(buffer));
	while (bytes_read != 0 && bytes_read != -1)
	{
		buffer_size += bytes_read;
		bytes_read = read(dict, buffer, sizeof(buffer));
	}
	if (bytes_read == -1)
		return (-1);
	close(dict);
	return (buffer_size);
}

char	*parse(void)
{
	int		buffer_size;
	char	*buffer;

	buffer_size = get_dict_buffer_size();
	buffer_size += 1;
	buffer = malloc(buffer_size);
	if (buffer == 0)
		return (0);
	get_dict_str(buffer, buffer_size);
	return (buffer);
}
