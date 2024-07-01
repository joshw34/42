/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:11:43 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/01 13:43:51 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	bring_to_top(t_node **a, t_node **b)
{
	t_node	*target;
	int		cost;
	int		a_len;

	target = (*b)->target_node;
	a_len = count_nodes(*a);
	if (target->current_index == 1)
		return ;
	else if (target->current_index == a_len)
		rra_rrb(a, 'a', 1);
	else if (target->top_half == true)
	{
		cost = target->current_index - 1;
		ra_rb(a, 'a', cost);
	}
	else
	{
		cost = (a_len - target->current_index) + 1;
		rra_rrb(a, 'a', cost);
	}
}

static	void	set_node_data(t_node *a, t_node *b)
{
	curr_index_top_half(a);
	curr_index_top_half(b);
	target_b_to_a(a, b);
}

void	push_b_to_a(t_node	**a, t_node **b)
{
	while (*b != NULL)
	{
		set_node_data(*a, *b);
		bring_to_top(a, b);
		pa_pb(b, a, 'a');
	}
}
