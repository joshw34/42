#include "../inc/minishell.h"

char	*get_var(char **env, char *var)
{
	char	*ret;

	ret = find_var(env, var);
	if (!ret)
		return (NULL);
	return (strchr(ret, '=') + 1);
}
