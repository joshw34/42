/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:03:06 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/22 19:32:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	both_btm_half(t_node **a, t_node **b, t_node *nd, t_node *tgt)
{
	if (nd->push_cost == tgt->push_cost)
		rrr(a, b, nd->total_cost);
	else if (nd->push_cost > tgt->push_cost)
	{
		rrr(a, b, tgt->push_cost);
		rra_rrb(a, 'a', nd->total_cost - tgt->push_cost);
	}
	else if (tgt->push_cost > nd->push_cost)
	{
		rrr(a, b, nd->push_cost);
		rra_rrb(b, 'b', nd->total_cost - nd->push_cost);
	}
}

static	void	both_top_half(t_node **a, t_node **b, t_node *nd, t_node *tgt)
{
	if (nd->push_cost == 0)
		ra_rb(b, 'b', nd->total_cost);
	else if (tgt->push_cost == 0)
		ra_rb(a, 'a', nd->total_cost);
	else if (nd->push_cost == tgt->push_cost)
		rr(a, b, nd->total_cost);
	else if (nd->push_cost > tgt->push_cost)
	{
		rr(a, b, tgt->push_cost);
		ra_rb(a, 'a', nd->total_cost - tgt->push_cost);
	}
	else if (tgt->push_cost > nd->push_cost)
	{
		rr(a, b, nd->push_cost);
		ra_rb(b, 'b', nd->total_cost - nd->push_cost);
	}
}

static	void	bring_to_top(t_node **a, t_node **b)
{
	t_node	*nd;
	t_node	*tgt;

	nd = find_cheapest(*a);
	tgt = nd->target_node;
	if (nd->total_cost == 0)
		return ;
	else if (nd->top_half == true && tgt->top_half == true)
		both_top_half(a, b, nd, tgt);
	else if (nd->top_half == false && tgt->top_half == false)
		both_btm_half(a, b, nd, tgt);
	else
	{
		if (nd->top_half == true)
		{
			ra_rb(a, 'a', nd->push_cost);
			rra_rrb(b, 'b', tgt->push_cost);
		}
		else
		{
			rra_rrb(a, 'a', nd->push_cost);
			ra_rb(b, 'b', tgt->push_cost);
		}
	}
}

static	void	set_node_data(t_node *a, t_node *b)
{
	curr_index_top_half(a);
	curr_index_top_half(b);
	target_a_to_b(a, b);
	a_to_b_cost(a, b);
}

void	push_a_to_b(t_node **a, t_node **b)
{
	int		a_nodes;
	t_node	**temp_a;
	t_node	**temp_b;

	a_nodes = count_nodes(*a);
	temp_a = a;
	temp_b = b;
	while (a_nodes > 3)
	{
		set_node_data(*temp_a, *temp_b);
		bring_to_top(temp_a, temp_b);
		pa_pb(a, b, 'b');
		a_nodes--;
	}
	set_node_data(*a, *b);
}
