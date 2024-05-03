#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int	a;
	
	a = 12;
	int* ptr1 = &a;
	int** ptr2 = &ptr1;
	int*** ptr3 = &ptr2;
	int**** ptr4 = &ptr3;
	int***** ptr5 = &ptr4;
	int****** ptr6 = &ptr5;
	int******* ptr7 = &ptr6;
	int******** ptr8 = &ptr7;
	int********* ptr9 = &ptr8;
	printf("Value before: %d", a);
	ft_ultimate_ft(ptr9);
	printf("Value before: %d", a);
	return (0);
}

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
