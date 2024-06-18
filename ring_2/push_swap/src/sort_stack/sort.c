#include "../../inc/push_swap.h"

static	void	create_stack_b(t_stack_node **a, t_stack_node **b)
{
	pa_pb(a, b);
	pa_pb(a, b);
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	if (check_stacks(*a, *b) == true)
		return ;
	else
		create_stack_b(a, b);
}
