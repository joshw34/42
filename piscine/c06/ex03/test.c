#include <stdio.h>
#include <unistd.h>

void	print_args(int argc, char **argv)
{
	int i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (i < argc)
	{
		while (j < argc && argv[j][k] != '\0')
		{
			write(1, &argv[j][k], 1);
			k++;
		}
		j++;
		k = 0;
		if (i < (argc -1))
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	//printf("Before:");
	//printf("\n%s", argv[1]);
	//printf("\n%s", argv[2]);
	//printf("\n%s", argv[3]);
	while (i < argc)
	{
		j = 1;
		while (j < (argc - 1))
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				arg = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = arg;
			}
			j++;
		}
		i++;
	}
	//printf("\nAfter:");
	//printf("\n%s", argv[1]);
	//printf("\n%s", argv[2]);
	//printf("\n%s", argv[3]);
	print_args(argc, argv);
	return (0);
}
