#include "../inc/minishell.h"

char	*get_prompt(char **env)
{
	char	*user;
	char	*dir;
	char	*prompt;

	user = ft_strjoin(get_var(env, "USER"), "@");
	dir = ft_strjoin(get_var(env, "PWD"), " $ ");
	prompt = ft_strjoin(user, ft_strrchr(dir, '/') + 1);
	free(user);
	free(dir);
	return (prompt);
}

char	*get_input(t_data *data)
{
	char	*ret;
	char	*prompt;

	prompt = get_prompt(data->env);
	ret = readline(prompt);
	free(prompt);
	add_history(ret);
	return (ret);
}
