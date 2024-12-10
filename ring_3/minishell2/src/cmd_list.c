/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:06:26 by jwhitley          #+#    #+#             */
/*   Updated: 2024/12/10 13:08:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd	*get_cmds(t_data *data)
{
	t_cmd	*cmds;
	int		n_cmds;
	int		start;
	int		end;

	n_cmds = cmd_count(data->tokens);
	start = 0;
	end = cmd_find_end(start, data->tokens);
	cmds = cmdlist_new(data->tokens, start, end);
	return (cmds);
}
