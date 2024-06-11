#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	int	result = (ft_strcmp("abcde", "abcdef"));

	printf("%d", result);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		else
			i++;
	} 
	return (0);
}
