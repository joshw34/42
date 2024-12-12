/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:06:26 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/12 15:51:51 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	cmdlist_add(t_cmd *cmds, t_tokens *tokens, int start, int end)
{
	t_cmd	*new;
	t_cmd	*temp_cmds;

	new = ft_calloc(1, sizeof(t_cmd));
	temp_cmds = cmds;
	while (temp_cmds->next != NULL)
		temp_cmds = temp_cmds->next;
	temp_cmds->next = new;
	new->in = get_input_redir(tokens, start, end);
	new->out = get_output_redir(tokens, start, end);
	new->cmd_n = temp_cmds->cmd_n + 1;
	new->cmd = parse_cmd(tokens, start, end);
	new->args = ft_split(new->cmd, ' ');
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->prev = temp_cmds;
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
	new->args = ft_split(new->cmd, ' ');
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
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
	printf("\nTotal Commands: %d\n\n", n_cmds);
	start = 0;
	while (i < n_cmds)
	{
		end = cmd_find_end(start, data->tokens);
		printf("START: %d\tEND: %d\n", start, end);
		if (cmds == NULL)
			cmds = cmdlist_new(data->tokens, start, end);
		else
			cmdlist_add(cmds, data->tokens, start, end);
		start = end;
		i++;
	}
	return (cmds);
}
