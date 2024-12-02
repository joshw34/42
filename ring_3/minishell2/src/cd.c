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

static	void	go_full_path(t_data *data, char *new_dir)
{
	char	*temp_new_dir;
	char	*temp_PWD;
	char	*temp_OLDPWD;

	if (access(new_dir, F_OK) == 0)
	{
		chdir(new_dir);
		temp_new_dir = get_realpwd();
		temp_PWD = ft_strjoin("PWD=", temp_new_dir);
		temp_OLDPWD = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_PWD);
		export_env(data, temp_OLDPWD);
		free(temp_new_dir);
		free(temp_PWD);
		free(temp_OLDPWD);
	}
	else
		perror(new_dir);
}

static	void	go_home_expand(t_data *data, char *new_dir)
{
	char	*temp_new_dir;
	char	*temp_PWD;
	char	*temp_OLDPWD;

	if (find_var(data->env, "HOME") == NULL)
		return (ft_putstr_fd("Error: HOME is not set\n", 2));
	temp_new_dir = ft_strjoin(get_var(data->env, "HOME"), new_dir + 1);
	if (access(temp_new_dir, F_OK) == 0)
	{
		chdir(temp_new_dir);
		free(temp_new_dir);
		temp_new_dir = get_realpwd();
		temp_PWD = ft_strjoin("PWD=", temp_new_dir);
		temp_OLDPWD = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_PWD);
		export_env(data, temp_OLDPWD);
		free(temp_new_dir);
		free(temp_PWD);
		free(temp_OLDPWD);
	}
	else
	{
		perror(temp_new_dir);
		free(temp_new_dir);
	}
}

static	void	go_home(t_data *data)
{
	char	*temp_new_dir;
	char	*temp_PWD;
	char	*temp_OLDPWD;
	
	if (find_var(data->env, "HOME") == NULL)
		return (ft_putstr_fd("Error: HOME is not set\n", 2));
	if (access(get_var(data->env, "HOME"), F_OK) == 0)
	{
		temp_new_dir = ft_strdup(get_var(data->env, "HOME"));
		temp_PWD = ft_strjoin("PWD=", get_var(data->env, "HOME"));
		temp_OLDPWD = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_PWD);
		export_env(data, temp_OLDPWD);
		chdir(temp_new_dir);
		free(temp_new_dir);
		free(temp_PWD);
		free(temp_OLDPWD);
	}
	else
		return ;
}

static	void	go_back(t_data *data)
{
	char	*temp_new_dir;
	char	*temp_PWD;
	char	*temp_OLDPWD;

	if (find_var(data->env, "OLDPWD") == NULL)
		return (ft_putstr_fd("Error: OLDPWD is not set\n", 2));
	if (access(get_var(data->env, "OLDPWD"), F_OK) == 0)
	{
		temp_new_dir = ft_strdup(get_var(data->env, "OLDPWD"));
		temp_PWD = ft_strjoin("PWD=", get_var(data->env, "OLDPWD"));
		temp_OLDPWD = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_PWD);
		export_env(data, temp_OLDPWD);
		chdir(temp_new_dir);
		free(temp_new_dir);
		free(temp_PWD);
		free(temp_OLDPWD);
	}
	else
		return ;
}

void	change_dir(t_data *data, char *new_dir)
{
	if (ft_strncmp(new_dir, "-", 2) == 0)
		go_back(data);
	else if (ft_strncmp(new_dir, "~", 2) == 0)
		go_home(data);
	else if (new_dir[0] == '~' && new_dir[1] != '\0')
		go_home_expand(data, new_dir);
	else
		go_full_path(data, new_dir);
}
