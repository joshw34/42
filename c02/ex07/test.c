#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char string[10] = {'J', 'o', 'S', 'h', 'U', 'a'};

	printf("%s", string);
	ft_strupcase(string);
	printf("\n%s", string);
	return (0);
}

char	*ft_strupcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
		{
			str[i] = str[i] - 32;
		}
	i++;
	}
	return (str);
}
