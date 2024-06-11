#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char source[] = ", World";
	char destination[20] = "Hello";
	unsigned int nb = 4;

	printf("%s\n", source);
	printf("%s\n", destination);
	
	ft_strncat(destination, source, nb);
	
	printf("%s", destination);

	int i = 0;

	while (destination[i] != '\0')
	{
		i++;
	}

	printf("\n%d", i);
	
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
