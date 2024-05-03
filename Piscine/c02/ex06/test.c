int ft_str_is_printable(char *str);                                                                     
 
int main(void)
{
    char    string[] = {'a', 'b', 'c', 'Z', 'T'};
    ft_str_is_printable(string);
    return (0);
}

int	ft_str_is_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] > 31 && str[i] < 127))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
