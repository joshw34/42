#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	// Full page
	
	/*int	fd;
	int	i;

	fd = open("testfile.txt", O_RDONLY);
	i = 0;
	while (i < 32)
	{
		printf("%s", get_next_line(fd));
		i++;
		sleep(1);
	}*/

	// First Line

	/*int fd;
	fd = open("testfile.txt", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);*/


	// From stdin

	/*int fd;
	fd = 0;
	printf("%s", get_next_line(fd));*/

	int fd = open("testfile.txt", O_RDONLY);
	char *line;
	int i = 0;

	while (i < 32)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		//sleep(1);
		i++;
	}
	close(fd);

	return (0);
}