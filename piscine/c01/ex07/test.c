#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	arr[6] = {1, 2, 3, 4, 5, 6};
	int	size;

	size = 6;
	printf("Before: %d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	ft_rev_int_tab(arr, size);
	printf("\nAfter:  %d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;  
    int	b;  
    int	temp;            
    
	a = 0;  
    b = size - 1;       
            
    while (a < b)        
    {
		temp = tab[a];
		tab[a] = tab[b];
		tab[b] = temp;
		a++;
		b--;
		printf("\n%d %d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
    }
}
