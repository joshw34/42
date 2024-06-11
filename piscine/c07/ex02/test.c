#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;
	
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = malloc((sizeof(int) * (max - min)));
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
	{
		array[i] = min;
	//	printf("%d", array[i]);
		i++;
		min++;
	}
	*range = array;
	return (i);
}

int	main(void)
{
	int *range = NULL;

	printf("\n%d", ft_ultimate_range(&range, -5, 10));
	return (0);
}
