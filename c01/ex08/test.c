#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	while (i < (size -1))
	{
		j = 0;
		while (j < (size - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	tab[] = {6, 1, 4, 3, 2, 5};
	int	size = 6;
	printf("Before: %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	ft_sort_int_tab(tab, size);
	printf("After : %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
}
