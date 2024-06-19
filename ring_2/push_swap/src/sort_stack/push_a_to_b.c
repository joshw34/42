#include "../../inc/push_swap.h"

static	void	diff_half(t_node **a, t_node **b, t_node *nd, t_node *tgt)
{
	if (nd->current_index == 2)
		sa_sb(a, 'a');
	else if (nd->top_half == true)
		ra_rb(a, 'a', nd->push_cost);
	else
		rra_rrb(a, 'a', nd->push_cost);
	if (tgt->current_index == 2)
		sa_sb(b, 'b');
	else if (tgt->top_half == true)
		ra_rb(b, 'b', tgt->push_cost);
	else
		rra_rrb(b, 'b', tgt->push_cost);
}

static	void	same_half(t_node **a, t_node **b, t_node *nd, t_node *tgt)
{
	if (nd->top_half == true && nd->push_cost < tgt->push_cost)
	{
		rr(a,b, nd->push_cost);
		ra_rb(b, 'b', (tgt->push_cost - nd->push_cost));
	}
	else if (nd->top_half == true && nd->push_cost > tgt->push_cost)
	{
		rr(a, b, tgt->push_cost);
		ra_rb(a, 'a', (nd->push_cost - tgt->push_cost));
	}
	else if (nd->top_half == false && nd->push_cost < tgt->push_cost)
	{
		rrr(a,b, nd->push_cost);
		rra_rrb(b, 'b', (tgt->push_cost - nd->push_cost));
	}
	else if (nd->top_half == false && nd->push_cost > tgt->push_cost)
	{
		rrr(a, b, tgt->push_cost);
		rra_rrb(a, 'a', (nd->push_cost - tgt->push_cost));
	}
}

static	void	bring_to_top(t_node **a, t_node **b)
{
	t_node	*nd;
	t_node	*tgt;
	
	nd = find_cheapest(*a);
	tgt = nd->target_node;
	if (nd->current_index == 2 && tgt->current_index ==2)
		ss(a, b);
	if (nd->push_cost == tgt->push_cost && nd->top_half == tgt->top_half)
	{
		if (nd->top_half == true)
			rr(a, b, nd->push_cost);
		else
			rrr(a, b, nd->push_cost);
	}
	else if (nd->top_half == tgt->top_half && nd->push_cost != tgt->push_cost)
		same_half(a,b, nd, tgt);
	else
		diff_half(a, b, nd, tgt);
}

static	void	set_node_data(t_node *a, t_node *b)
{
	curr_index_top_half(a);
	curr_index_top_half(b);
	target_a_to_b(a, b);
	set_cost(a, b);
}

void	push_a_to_b(t_node **a, t_node **b)
{
	int	a_nodes;

	a_nodes = count_nodes(*a);
	set_node_data(*a, *b);
	while (a_nodes > 3)
	{
		bring_to_top(a, b);
		pa_pb(a, b, 'b');
		set_node_data(*a, *b);
		a_nodes--;
	}
	set_node_data(*a, *b);
	
}