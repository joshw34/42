/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:52:39 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/09 19:43:05 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	go_full_path(t_data *data, char *new_dir)
{
	char	*temp_new_dir;
	char	*temp_pwd;
	char	*temp_oldpwd;

	if (access(new_dir, F_OK) == 0)
	{
		chdir(new_dir);
		temp_new_dir = get_realpwd();
		temp_pwd = ft_strjoin("PWD=", temp_new_dir);
		temp_oldpwd = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_pwd);
		export_env(data, temp_oldpwd);
		free(temp_new_dir);
		free(temp_pwd);
		free(temp_oldpwd);
	}
	else
	{
		perror(new_dir);
		last_signal = 1;
	}
}

static	void	go_home_expand(t_data *data, char *new_dir)
{
	char	*temp_new_dir;
	char	*temp_pwd;
	char	*temp_oldpwd;

	if (find_var(data->env, "HOME") == NULL)
		return (last_signal = 1, ft_putstr_fd("Error: HOME is not set\n", 2));
	temp_new_dir = ft_strjoin(get_var(data->env, "HOME"), new_dir + 1);
	if (access(temp_new_dir, F_OK) == 0)
	{
		chdir(temp_new_dir);
		free(temp_new_dir);
		temp_new_dir = get_realpwd();
		temp_pwd = ft_strjoin("PWD=", temp_new_dir);
		temp_oldpwd = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_pwd);
		export_env(data, temp_oldpwd);
		multi_free(3, temp_new_dir, temp_pwd, temp_oldpwd);
		return ;
	}
	perror(temp_new_dir);
	free(temp_new_dir);
	last_signal = 1;
	return ;
}

static	void	go_home(t_data *data)
{
	char	*temp_new_dir;
	char	*temp_pwd;
	char	*temp_oldpwd;

	if (find_var(data->env, "HOME") == NULL)
		return (last_signal = 1, ft_putstr_fd("Error: HOME is not set\n", 2));
	if (access(get_var(data->env, "HOME"), F_OK) == 0)
	{
		temp_new_dir = ft_strdup(get_var(data->env, "HOME"));
		temp_pwd = ft_strjoin("PWD=", get_var(data->env, "HOME"));
		temp_oldpwd = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_pwd);
		export_env(data, temp_oldpwd);
		chdir(temp_new_dir);
		multi_free(3, temp_new_dir, temp_pwd, temp_oldpwd);
		return ;
	}
	else
		last_signal = 1;
}

static	void	go_back(t_data *data)
{
	char	*temp_new_dir;
	char	*temp_pwd;
	char	*temp_oldpwd;

	if (get_var(data->env, "OLDPWD") == NULL)
		return (last_signal = 1, ft_putstr_fd("Error: OLDPWD is not set\n", 2));
	if (access(get_var(data->env, "OLDPWD"), F_OK) == 0)
	{
		temp_new_dir = ft_strdup(get_var(data->env, "OLDPWD"));
		temp_pwd = ft_strjoin("PWD=", get_var(data->env, "OLDPWD"));
		temp_oldpwd = ft_strjoin("OLDPWD=", get_var(data->env, "PWD"));
		export_env(data, temp_pwd);
		export_env(data, temp_oldpwd);
		chdir(temp_new_dir);
		multi_free(3, temp_new_dir, temp_pwd, temp_oldpwd);
		printf("%s\n", get_var(data->env, "PWD"));
		return ;
	}
	else
		last_signal = 1;
}

void	change_dir(t_cmd *cmd)
{
	char *new_dir;

	new_dir = cmd->args[1];
	last_signal = 0;
	if (!new_dir || ft_strncmp(new_dir, "~", 2) == 0)
		go_home(cmd->data);
	else if (ft_strncmp(new_dir, "-", 2) == 0)
		go_back(cmd->data);
	else if (new_dir[0] == '~' && new_dir[1] != '\0')
		go_home_expand(cmd->data, new_dir);
	else
		go_full_path(cmd->data, new_dir);
}
