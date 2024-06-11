#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char source[] = ", World";
	char destination[20] = "Hello";

	printf("%s\n", source);

	printf("%s\n", destination);
	
	ft_strcat(destination, source);
	
	printf("%s\n", destination);

	int i = 0;

	while (destination[i] != '\0')
	{
		i++;
	}

	printf("%d", i);
	
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
