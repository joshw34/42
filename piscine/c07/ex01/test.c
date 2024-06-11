#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int *result;
	int	i;

	i = 0;

	if (min >= max)
		return (NULL);
	else
		result = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		result[i] = min;
		i++;
		min++;
	}
	return (result);
}

int	main(void)
{
	int	min = -10;
	int	max = 10;

	int	i = 0;
	int	*array = ft_range(min, max);
	printf("\nmin = %d   max = %d\n", min, max);
	while (i < (max - min))
	{
		printf("%d\n", array[i]);
		i++;
	}
}
