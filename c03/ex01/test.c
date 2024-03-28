#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	unsigned int	n = 3;
	int	result = (ft_strncmp("abcde", "abcd", n));

	printf("%d", result);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;

	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
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
