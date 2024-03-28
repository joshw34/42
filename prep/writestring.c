#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int arr[5];
	int size = 5;
	int n;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	/*in order stored as char */
	
	/*n = 0;
	while (n < size)
	{
		write(1, &arr[n], 1);
		n++;
	}*/

	/* reverse order stored as char */
	
	/*n = size - 1;
	while (n >= 0)
	{
		write(1, &arr[n], 1);
		n--;
	}*/

	/* in order stored as int
	   int must be converted to int.  this stores as an ASCII value
	   add 48 to ascii value to get character */
	
	/*n = 0;
	while (n < size)
	{
		char temp;
		temp = arr[n] + 48;
		write(1, &temp, 1);
		//printf("%c", temp);
		n++;
	}*/

	/* reverse order stored as int */
	
	n = size - 1;
	while (n >=0)
	{
		char temp;
		temp = arr[n] + 48;
		write(1, &temp, 1);
		n--;
	}
	




}
