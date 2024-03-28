#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char    source[10] = {'S', 'o', 'u', 'r', 'c', 'e'};
    char    destination[10];
	unsigned int	n = 5;
 
    printf("%s\n", destination);
    ft_strncpy(destination, source, n);
    printf("%s\n", destination);
    return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
