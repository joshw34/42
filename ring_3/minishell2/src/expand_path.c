#include "../inc/minishell.h"

void	expand_tilda(t_data *data, t_tokens *token)
{
	char	*temp;
	char	*new;

	temp = NULL;
	new = NULL;
	if (token->word[0] == '~' && token->word[1] == '\0')
		new = ft_strdup(get_var(data->env, "HOME"));
	else if (token->word[0] == '~')
	{
		temp = ft_strdup(token->word + 1);
		new = ft_strjoin(get_var(data->env, "HOME"), temp);
		free(temp);
	}
	free(token->word);
	token->word = new;
}

static	void	build_real_path(char *path, char *new)
{
	char	*temp;
	char	*temp_2;
	int		last;

	temp = NULL;
	temp_2 = NULL;
	last = ft_strlen(path) - 1;
	if ()
}

static	void	go_to_parent(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i] == '/')
		i--;
	while (i >= 0 && str[i] != '/')
		i--;
	str[i + 1] = '\0';
}

void	expand_path(t_data *data, t_tokens *token)
{
	char	**split;
	char	*cwd;
	int		i;
	
	split = NULL;
	cwd = NULL;
	i = 0;
	if (token->word[0] != '.')
		return ;
	split = ft_split(token->word, '/');
	cwd = get_realpwd();
	while (split[i])
	{
		if (ft_strncmp(split[i], "..", 3) == 0)
			go_to_parent(cwd);
		if (ft_strncmp(split[i], "..", 3) != 0 && ft_strncmp(split[i], ".", 2) != 0)
			break ;
		i++;
	}
	while (split[i])
	{
		build_real_path(cwd, split[i]);
		i++;
	}
}
