#include "../inc/minishell.h"

char	*find_var(char **env, char *var)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	temp = ft_strjoin(var, "=");
	len = ft_strlen(temp);
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], len) == 0)
		{
			free(temp);
			return (env[i]);
		}
		i++;
	}
	free(temp);
	return(NULL);
}
