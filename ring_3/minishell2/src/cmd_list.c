/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:06:26 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/11 15:31:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	cmdlist_add(t_cmd *cmds, t_tokens *tokens, int start, int end)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	while (cmds->next != NULL)
		cmds = cmds->next;
	cmds->next = new;
	new->in = get_input_redir(tokens, start, end);
	new->out = get_output_redir(tokens, start, end);
	new->cmd_n = cmds->cmd_n + 1;
	new->cmd = parse_cmd(tokens, start, end);
	new->prev = cmds;
	new->next = NULL;
}

static	t_cmd	*cmdlist_new(t_tokens *tokens, int start, int end)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	new->in = get_input_redir(tokens, start, end);
	new->out = get_output_redir(tokens, start, end);
	new->cmd_n = 1;
	new->cmd = parse_cmd(tokens, start, end);
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
	i = 0;
	n_cmds = cmd_count(data->tokens);
	start = 0;
	while (i < n_cmds)
	{
		end = cmd_find_end(start, data->tokens);
		if (cmds == NULL)
			cmds = cmdlist_new(data->tokens, start, end);
		else
			cmdlist_add(cmds, data->tokens, start, end);
		start = end;
		i++;
	}
	return (cmds);
}
