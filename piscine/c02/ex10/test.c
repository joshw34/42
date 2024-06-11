#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size < 1)
		return (0);
	while (i < (size - 1) && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	main(void)
{
	char	source[10] = "Hello";
	char	dest[10];
	unsigned int	size = 4;
	printf("Source = %s", source);
	printf("\nDest before = %s", dest);
	ft_strlcpy(dest, source, size);
	printf("\nDest After = %s", dest);
	printf("\nn = %d", ft_strlcpy(dest, source, size));
	return (0);
}