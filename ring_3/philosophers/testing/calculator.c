#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int	i = 1;
	int	result = 0;

	while (argv[i])
	{
		result += atoi(argv[i]);
		i++;
	}
	printf("TOTAL: %d\n", result);
}