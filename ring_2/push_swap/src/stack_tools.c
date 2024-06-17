#include "../inc/push_swap.h"

void	curr_index_top_half(t_stack_node *stack)
{
	int i;
	int	midpoint;
	t_stack_node	*temp;

	i = 1;
	temp = stack;
	while (temp != NULL)
	{
		temp->current_index = i;
		temp = temp->next;
		i++;
	}
	i--;
	if (i % 2 == 0)
		midpoint = i / 2;
	else
		midpoint = (i / 2) + 1;
	while (stack != NULL)
	{
		if (stack->current_index <= midpoint)
			stack->top_half = true;
		else
			stack->top_half = false;
		stack = stack->next;
	}
}

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

	new = ft_calloc(1, sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
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
		new->prev = temp;
	}
	return (true);
}
