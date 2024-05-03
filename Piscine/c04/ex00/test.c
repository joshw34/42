#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char *string = "This string has 29 characters";
	printf("%s", string);
	printf("\n%d", ft_strlen(string));
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
