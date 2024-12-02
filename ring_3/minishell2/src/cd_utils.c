#include "../inc/minishell.h"

char	*get_realpwd(void)
{
	char	*ret;

	ret = ft_calloc(1024, sizeof(char));
	getcwd(ret, 1024);
	return (ret);
}
