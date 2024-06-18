#include "../../inc/push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	if (check_stacks(*a, *b) == true)
		return ;
	else
		create_stack_b(a, b);
}
