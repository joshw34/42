#include "../../inc/pipex.h"

char	**get_paths(char **env)
{
	char	**result;
	char	*paths;
	char 	*temp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_strtrim(env[i], "PATH=");
		i++;
	}
	result = ft_split(paths, ':');
	i = 0;
	while (result[i])
	{
		temp = ft_strjoin(result[i], "/");
		free(result[i]);
		result[i] = temp;
		i++;
	}
	free(paths);
	return (result);
}
