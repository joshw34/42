#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;

	//fd = open("testfile.txt", O_RDONLY);
	fd = 0;
	i = 0;
	while (i < 32)
	{
		printf("%s", get_next_line(fd));
		i++;
		sleep(1);
	}
	return (0);
}