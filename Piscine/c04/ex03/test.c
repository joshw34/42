#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int result;
	
	i = 0;
	sign = 1;
	result = 0;

	/*cycle through whitespace*/
	
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	
	/*cycle through + and - and count '-'*/
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	
	/*find numerical characters to convert*/
	while (str[i] > 47 && str[i] < 58)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			result = (result * 10) + (str[i] - 48);
		}
		i++;
	}
	
//	printf("\nchar: %c", str[i]);
//	printf("\ni = %d", i);
//	printf("\nsign = %d", sign);
//	printf("\nresult = %d", result);
	
	return (result * sign);	
}

int main(void)
{
	char	string[] = {' ', '\t', '-', '-', '+', '-', '-', '1', '2', '3', '4', 'a', 'b', '5', '6', '7'};
	printf("%d", ft_atoi(string));
	return (0);
}
