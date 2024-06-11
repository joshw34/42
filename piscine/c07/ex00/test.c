#include <stdlib.h>
#include <stdio.h>

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	ft_strcpy(dest, src);
	return (dest);
}

int	main(void)
{
	char	source[] = {'H', 'e', 'l', 'l', 'o'};

	printf("%s", ft_strdup(source));
	return (0);
}
