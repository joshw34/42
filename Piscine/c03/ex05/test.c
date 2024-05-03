#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	
	i = ft_strlen(dest);
	j = 0;
	if (size == 0)
		return (ft_strlen(src) + ft_strlen(dest));
	if (size < i)
		return (ft_strlen(src) + ft_strlen(dest));
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}

int	main(void)
{
	char	src[] = "T est ";
	char	dest[10] = "T est";
	unsigned int	size = 10;
	printf("Before: %s", dest);
	printf("\n%d", ft_strlcat(dest, src, size));
	printf("\nAfter : %s", dest);
	return (0);
}
