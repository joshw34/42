#include "../../inc/push_swap.h"

void	full_sort(t_node **a, t_node **b)
{
	create_stack_b(a, b);
	push_a_to_b(a, b);
}