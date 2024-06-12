#include "../inc/push_swap.h"

bool	check_repeat(char *str, char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_strlen(str) == ft_strlen(input[i]))
		{
			if (ft_strncmp(str, input[i], ft_strlen(str)) == 0)
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_format(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) == 0 && str[i] != '+' && str[i] != '-')
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	check_error(char **input)
{
	int	i;
	
	i = 0;
	while (input[i])
	{
		if (!check_format(input[i]))
			return (false);
		if (!check_repeat(input[i], input + i + 1))
			return (false);
		i++;
	}
	return (true);
}

