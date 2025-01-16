/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:26:40 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/16 18:31:53 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	bool	get_tokens(t_data *data)
{
	char	**split;

	split = split_tokens(&data->user_input);
	if (!split)
		return (ft_putstr_fd("Error: failed to split input", 2), false);
	if (token_list(data, split) == false)
		return(ft_putstr_fd("Error: failed to create token list", 2), false);
	if (expand_tokens(data->tokens) == false)
		return (false);
	db_print_tokens(data);
	return (true);
}

bool	process_user_input(t_data *data)
{
	if (!data)
		return (NULL);
	data->user_input = get_input(data);//ft_strdup(get_input(data));
	if (valid_input(data->user_input) == false)
		return (false);
	if (get_tokens(data) == false)
		return (false);
	return (true);
}
