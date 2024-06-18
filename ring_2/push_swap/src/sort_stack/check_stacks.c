#include "../../inc/push_swap.h"

bool	check_stacks(t_stack_node *a, t_stack_node *b)
{
	if (b != NULL)
		return (false);
	else
		while (a->next != NULL)
		{
			if (a->nbr > a->next->nbr)
				return (false);
			a = a->next;
		}
	return (true);
}