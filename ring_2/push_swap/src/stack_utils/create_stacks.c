/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 17:56:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	create_stack_b(t_stack_node **a, t_stack_node **b)
{
	pa_pb(a, b);
	pa_pb(a, b);
}

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
