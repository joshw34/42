/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:06:26 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/13 13:10:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	cmd_list_clear(t_cmd *cmds)
{
	t_cmd	*current;
	t_cmd	*next;

	current = cmds;
	while (current != NULL)
	{
		next = current->next;
		if (current->cmd)
			free(current->cmd);
		if (current->args)
			free_array(current->args);
		if (current->in)
			redir_list_clear(current->in);
		if (current->out)
			redir_list_clear(current->out);
		free(current);
		current = next;
	}
}

static	void	cmdlist_add(t_cmd *cmds, t_data *data, int start, int end)
{
	t_cmd	*new;
	t_cmd	*temp_cmds;

	new = ft_calloc(1, sizeof(t_cmd));
	temp_cmds = cmds;
	while (temp_cmds->next != NULL)
		temp_cmds = temp_cmds->next;
	temp_cmds->next = new;
	new->in = get_input_redir(data->tokens, start, end);
	new->out = get_output_redir(data->tokens, start, end);
	new->cmd_n = temp_cmds->cmd_n;
	new->cmd = parse_cmd(data->tokens, start, end);
	new->args = ft_split(new->cmd, ' ');
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->data = data;
	new->env = data->env;
	new->prev = temp_cmds;
	new->next = NULL;
}

static	t_cmd	*cmdlist_new(t_data *data, int start, int end, int n_cmds)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	new->in = get_input_redir(data->tokens, start, end);
	new->out = get_output_redir(data->tokens, start, end);
	new->cmd_n = n_cmds;
	new->cmd = parse_cmd(data->tokens, start, end);
	//printf("CMD= %s", new->cmd);
	if (new->cmd)
		new->args = ft_split(new->cmd, ' ');
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->data = data;
	new->env = data->env;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_cmd	*get_cmds(t_data *data)
{
	t_cmd	*cmds;
	int		n_cmds;
	int		start;
	int		end;
	int		i;

	cmds = NULL;
	if (data->tokens == NULL)
		return (cmds);
	i = 0;
	n_cmds = cmd_count(data->tokens);
	start = 0;
	while (i < n_cmds)
	{
		end = cmd_find_end(start, data->tokens);
		if (cmds == NULL)
			cmds = cmdlist_new(data, start, end, n_cmds);
		else
			cmdlist_add(cmds, data, start, end);
		start = end;
		i++;
	}
	return (cmds);
}
