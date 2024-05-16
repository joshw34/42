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

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen(s);
	if (c > 127)
		return ((char *) s);
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	new_len;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_len = gnl_strlen(s1) + gnl_strlen(s2);
	result = malloc(sizeof(char) * (new_len + 1));
	
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[new_len] = '\0';
	return (result);
}

void	gnl_bzero(void *s, size_t n)
{
	char			*str;
	unsigned long	i;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (size > (INT_MAX / nmemb))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	gnl_bzero(ptr, total_size);
	return (ptr);
}
