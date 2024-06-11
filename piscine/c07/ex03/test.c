#include <stdlib.h>
#include <stdio.h>

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

int	ft_find_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	total;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
		}
		total = total + j;
		i++;
	}
	while (sep[k] != '\0')
		k++;
	total = total + (k * (size - 1));
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*result;
	int		i;

	i = 0;
	length = (ft_find_length(size, strs, sep));
	if (size <= 0)
	{
		result = malloc(1 * sizeof(char));
		result[0] = 0;
	}
	else
		result = malloc((length * sizeof(char)) + 1);
	while (i < size)
	{
		if (strs[i][0] != '\0')
			ft_strcat(result, strs[i]);
		if (i < (size - 1))
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

int	main(void)
{
	char	*strs[] = {"hello", "w", "hello", "n"};
	char	*sep = {"***"};
	int	size = 4;
	char	*new;

	new = ft_strjoin(size, strs, sep);
	printf("%s", new);
	return (0);
}
