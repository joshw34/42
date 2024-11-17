#include "../inc/minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	main(int ac, char **av)
{
	char	*result;
	char	*temp;
	char	*path;
	char	**split;
	int i;

	(void)ac;
	i = 0;
	path = getenv("PATH");
	split = ft_split(path, ':');
	while (split[i])
	{
		temp = ft_strjoin(split[i], "/");
		result = ft_strjoin(temp, av[1]);
		free(temp);
		if (access(result, X_OK) == 0)
		{	
			free_array(split);
			printf("%s\n", result);
			return (0);
		}
		else
			free(result);
		i++;
	}
	return (0);
}
