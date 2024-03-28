#include <unistd.h>

int	main(void)
{
	/* write() can only print ASCII characters or char
	   to print an int: convert to char and +48 to get ASCII value */

	int a = 7;
	char b = a+48;
		
	write(1, &b, 1);
	return (0);
}
