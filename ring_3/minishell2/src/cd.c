/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:52:39 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/24 23:17:29 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*expand_new_dir(char *str)
{
	char	**split;

	split = ft_split(str, '/');
	return (split[0]);
}

void	change_dir(t_data *data, char *new_dir)
{
	char	*temp_pwd;
	char	*temp_oldpwd;
	char	*temp_new_dir;

	temp_new_dir = expand_new_dir(new_dir);

	temp_pwd = ft_strjoin("PWD=", new_dir);
	int i = 0;
	while (temp_pwd[i])
		i++;
	if (temp_pwd[i - 1] == '/' && temp_pwd[i - 2] != '=')
		temp_pwd[i - 1] = '\0';
	temp_oldpwd = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
	chdir(new_dir);
	export_env(data, temp_pwd);
	export_env(data, temp_oldpwd);
	free(temp_pwd);
	free(temp_oldpwd);
}
