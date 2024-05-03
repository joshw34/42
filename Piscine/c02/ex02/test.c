int	ft_str_is_alpha(char *str);

int	main(void)
{
	char	string[] = {'a', 'b', 'c', 'Z', 'T'};
	ft_str_is_alpha(string);
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
