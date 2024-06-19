/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:29 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/19 15:59:27 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (sign * result);
}

void	create_stack_b(t_node **a, t_node **b)
{
	pa_pb(a, b, 'b');
	if (count_nodes(*a) > 3)
		pa_pb(a, b, 'b');
}

bool	create_stack_a(t_node **stack, char **input, int start)
{
	int		i;

	i = start;
	if (!check_format_error(input + start))
		quit_error_free(stack, input, start);
	while (input[i])
	{
		if (!add_node(stack, ft_atol(input[i])))
			quit_error_free(stack, input, start);
		i++;
	}
	if (!check_nbr_repeat(*stack))
		quit_error_free(stack, input, start);
	if (start == 0)
		free_argv(input);
	return (true);
}
