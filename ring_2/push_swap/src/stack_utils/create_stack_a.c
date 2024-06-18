/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:30 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

bool	create_stack_a(t_stack_node **stack, char **input, int start)
{
	int		i;

	i = start;
	if (!check_error(input + start))
		quit_error_free(stack, input, start);
	while (input[i])
	{
		if (!add_node(stack, ft_atoi(input[i])))
			quit_error_free(stack, input, start);
		i++;
	}
	if (start == 0)
		free_argv(input);
	return (true);
}
