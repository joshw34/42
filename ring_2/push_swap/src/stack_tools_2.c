#include "../inc/push_swap.h"

static	void	cheapest(t_stack_node *stack)
{
	t_stack_node	*temp;
	int				lowest;
	int				result_ind;

	temp = stack;
	lowest = INT_MAX;
	while (temp != NULL)
	{
		if (temp->push_cost < lowest)
		{
			lowest = temp->push_cost;
			result_ind = temp->current_index;
		}
		temp = temp->next;
	}
	while (stack != NULL)
	{
		if (stack->current_index == result_ind)
			stack->cheapest = true;
		else
			stack->cheapest = false;
		stack = stack->next;
	}
}

static	int	calc_cost(t_stack_node *node, int len)
{
	int	result;

	if (node->current_index == 1)
		result = 0;
	else if (node->current_index == 2)
		result = 1;
	else if (node->current_index > 2 && node->top_half == true)
		result = node->current_index - 1;
	else if (node->current_index == len)
		result = 1;
	else if (node->current_index < len && node->top_half == false)
		result = len - node->current_index + 1;
	return (result);
}

void	set_cost(t_stack_node *src, t_stack_node *dest)
{
	int				src_len;
	int				dest_len;
	int				s_cost;
	int				d_cost;
	t_stack_node	*temp;

	src_len = count_nodes(src);
	dest_len = count_nodes(dest);
	temp = src;
	while (src != NULL)
	{
		s_cost = calc_cost(src, src_len);
		d_cost = calc_cost(src->target_node, dest_len);
		if (s_cost == d_cost && src->top_half == src->target_node->top_half)
			src->push_cost = s_cost;
		else
			src->push_cost = s_cost + d_cost;
		src = src->next;
	}
	cheapest(temp);
}

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
