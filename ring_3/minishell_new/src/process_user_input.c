/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:26:40 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 02:45:34 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	process_user_input(t_data *data)
{
	if (!data)
		return (NULL);
	data->user_input = ft_strdup(get_input(data));
	if (valid_input(data->user_input))
		return (false);
	if (get_tokens(data) == false)
		return (false);
	return (true);
}
