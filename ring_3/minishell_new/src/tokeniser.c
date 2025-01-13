/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:03:17 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 03:23:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	get_tokens(t_data *data)
{
	char	**split;

	split = split_tokens(&data->user_input);
	if (!split)
		return (ft_putstr_fd("Error: failed to split input", 2), false);
	if (token_list(data, split) == false)
		return(ft_putstr_fd("Error: failed to create token list", 2), false);
	//if (handle_quotes(data))
	db_print_tokens(data);
	return (true);
}
