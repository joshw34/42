#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	source[10] = {'S', 'o', 'u', 'r', 'c', 'e'};
	char	destination[10];

	printf("%s\n", destination);
	ft_strcpy(destination, source);
	printf("%s\n", destination);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
