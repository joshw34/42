#include "../inc/push_swap.h"

t_stack_node	*last_node(t_stack_node *node)
{
	if (node->next == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_stack_node	*new_node(int nbr)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

bool	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node *temp;
	t_stack_node *new;

	new = new_node(nbr);
	if (new == NULL)
		return (false);
	if (*stack == NULL)
		*stack = new;
	else
	{
		temp = last_node(*stack);
		temp->next = new;
	}
	return (true);
}
