#include <unistd.h>

int	main(void)
{
	/* this will print 'r' if the last number is 1
	   it will print 'r' and '\n' if it is 2 */	
	write(1, "r\n" , 1);
	return (0);
}
