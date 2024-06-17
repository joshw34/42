#include "../inc/push_swap.h"

void	target_a_to_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*temp_b;
	t_stack_node	*result;
	t_stack_node	*largest;

	temp_b = b;
	result = NULL;
	largest = NULL;
	while (a != NULL)
	{
		while (temp_b != NULL)
		{
			if ((temp_b->nbr < a->nbr) && (result == NULL
					|| temp_b->nbr > result->nbr))
				result = temp_b;
			if (largest == NULL || temp_b->nbr > largest->nbr)
				largest = temp_b;
			temp_b = temp_b->next;
		}
		a->target_node = result;
		if (result == NULL)
			a->target_node = largest;
		a = a->next;
		temp_b = b;
		result = NULL;
	}
}
