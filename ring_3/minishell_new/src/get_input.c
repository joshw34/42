/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:57:19 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 14:13:34 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	valid_input(char *input)
{
	if (!input || input[0] == '\0' || is_whitespace(input) == true)
		return (false);
	return (true);
}

static	char	*get_prompt(char **env)
{
	char	*user;
	char	*dir;
	char	*prompt;
	char	*fallback_pwd;

	if (get_var(env, "USER") != NULL)
		user = ft_strjoin(get_var(env, "USER"), "@");
	else
		user = ft_strjoin(getenv("USER"), "@");
	if (get_var(env, "PWD") == NULL)
	{
		fallback_pwd = get_realpwd();
		dir = ft_strjoin(fallback_pwd, " $ ");
		free(fallback_pwd);
	}
	else
		dir = ft_strjoin(get_var(env, "PWD"), " $ ");
	if (dir[0] == '/' && dir[1] == ' ')
		prompt = ft_strjoin(user, dir);
	else
		prompt = ft_strjoin(user, ft_strrchr(dir, '/') + 1);
	multi_free(2, user, dir);
	return (prompt);
}

char	*get_input(t_data *data)
{
	char	*ret;
	char	*prompt;

	prompt = get_prompt(data->env);
	ret = readline(prompt);
	if (!ret)
	{
		printf("\nexit\n");
		free(prompt);
		free_data_struct(data, true);
		g_last_signal = 127;
		exit(0);
	}
	free(prompt);
	add_history(ret);
	return (ret);
}
