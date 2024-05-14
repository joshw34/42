/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:20:40 by jwhitley          #+#    #+#             */
/*   Updated: 2024/05/14 16:20:42 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (gnl_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (gnl_strlen(src));
}

char	*gnl_strdup(const char *s)
{
	char	*new;
	size_t	len;

	len = gnl_strlen(s);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	else
		gnl_strlcpy(new, s, len + 1);
	return (new);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = gnl_strlen(dst);
	j = 0;
	len = (gnl_strlen(dst) + gnl_strlen(src));
	if ((size == 0) || (size < i))
		return (gnl_strlen(src) + size);
	while (i < (size - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	new_len;
	char	*result;

	len_1 = gnl_strlen(s1);
	len_2 = gnl_strlen(s2);
	new_len = len_1 + len_2;
	result = malloc(sizeof(char) * (new_len + 1));
	if (result == NULL)
		return (NULL);
	gnl_strlcpy(result, s1, new_len + 1);
	gnl_strlcat(result, s2, new_len + 1);
	return (result);
}
