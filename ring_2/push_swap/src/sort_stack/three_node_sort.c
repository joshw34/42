#include "../../inc/push_swap.h"

void	three_node_sort(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa_sb(stack, 'a');
		ra_rb(stack, 'a', 1);
	}
	else if (a > b && a < c)
		sa_sb(stack, 'a');
	else if (a < b && a > c)
		rra_rrb(stack, 'a', 1);
	else if (a > c && b < c)
		ra_rb(stack, 'a', 1);
	else if (a > b && b > c)
	{
		ra_rb(stack, 'a', 1);
		sa_sb(stack, 'a');
	}
}
