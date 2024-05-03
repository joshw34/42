#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	string[120] = {'s', 'a', 'l', 'u', 't', ',', ' ', 'c', 'o', 'm', 'm', 'e', 'n', 't', ' ', 't', 'u', ' ', 'v', 'a', 's', ' ', '?', ' ', '4', '2', 'm', 'o', 't', 's', ' ', 'q', 'u', 'a', 'r', 'a', 'n', 't', 'e', '-', 'd', 'e', 'u', 'x', ';', ' ', 'c', 'i', 'n', 'q', 'u', 'a', 'n', 't', 'e', '+', 'e', 't', '+', 'u', 'n'};
	
	printf("%s", string);
	ft_strcapitalize(string);
	printf("\n%s", string);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	
	i = 0;
	
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		if (str[i] > 96 && str[i] < 123)
		{
			if (!(str[i - 1] > 47 && str[i-1] < 58))
			{
				if (!(str[i - 1] > 96) && str[i - 1] < 123)
				{
					if	(!(str[i - 1] > 64 && str[i - 1] < 91))
					{
						str[i] = str[i] - 32;
					}
				}
			}
		}
		i++;
	}
	return (str);
}