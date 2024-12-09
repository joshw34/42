/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:43 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/09 13:03:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	expand_tilda(t_data *data, t_tokens *token)
{
	char	*temp;
	char	*new;

	temp = NULL;
	new = NULL;
	if (token->word[0] != '~')
		return ;
	else if (token->word[0] == '~' && token->word[1] == '\0')
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

static	void	build_real_path(t_tokens *token, char *path, char **new, int i)
{
	char	*temp;
	char	*temp_2;
	int		last;

	while (new[i])
	{
		temp = NULL;
		temp_2 = NULL;
		last = ft_strlen(path) - 1;
		if (path[last] != '/')
		{
			temp_2 = ft_strjoin(path, "/");
			temp = ft_strjoin(temp_2, new[i]);
			free(temp_2);
		}
		else
			temp = ft_strjoin(path, new[i]);
		free(path);
		path = ft_strdup(temp);
		free(temp);
		i++;
	}
	free(token->word);
	token->word = path;
}

static	void	go_to_parent(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '/')
		i--;
	while (i >= 0 && str[i] != '/')
		i--;
	str[i + 1] = '\0';
}

void	expand_path(t_tokens *token)
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
		if (ft_strncmp(split[i], "..", 3) != 0 && ft_strncmp(split[i], ".", 2)
			!= 0)
			break ;
		i++;
	}
	build_real_path(token, cwd, split, i);
	free_array(split);
}
