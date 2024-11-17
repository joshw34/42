#include "../inc/minishell.h"
#include <stdlib.h>

static	void	env_variables(char **args)
{
	int		i;
	char	*temp;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			temp = getenv(args[i] + 1);
			if (temp)
			{
				free(args[i]);
				args[i] = ft_strdup(temp);
			}
		}
		i++;
	}
}

bool	check_args(char **args)
{
	env_variables(args);	
	if (ft_strncmp(args[0], "cd", 3) == 0)
	{	
		chdir(args[1]);
		return (false);
	}
	return (true);
}
