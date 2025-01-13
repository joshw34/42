/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:29:04 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 13:43:15 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	is_a_separator(char c)
{
	ft_printf("SEP CHECK\n");
	if (c == '<' || c == '>' || c == '|')
		return (true);
	ft_printf("FALSE\n");
	return (false);
}