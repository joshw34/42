/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:09:51 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/22 15:40:31 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	smallest_to_top(t_node **stack)
{
	t_node	*temp;
	bool	top;
	int		smallest;
	int		index;

	temp = *stack;
	smallest = INT_MAX;
	while (temp != NULL)
	{
		if (temp->nbr < smallest)
		{
			smallest = temp->nbr;
			top = temp->top_half;
			index = temp->current_index;
		}
		temp = temp->next;
	}
	if (top == true)
		ra_rb(stack, 'a', index - 1);
	else
		rra_rrb(stack, 'a', (count_nodes(*stack) - index) + 1);
}

void	largest_to_top(t_node **stack)
{
	t_node	*temp;
	bool	top;
	int		largest;
	int		index;

	temp = *stack;
	largest = INT_MIN;
	while (temp != NULL)
	{
		if (temp->nbr > largest)
		{
			largest = temp->nbr;
			top = temp->top_half;
			index = temp->current_index;
		}
		temp = temp->next;
	}
	if (top == true)
		ra_rb(stack, 'b', index - 1);
	else
		rra_rrb(stack, 'b', (count_nodes(*stack) - index) + 1);
}

bool	check_stacks(t_node *a, t_node *b)
{
	if (b != NULL)
		return (false);
	else
	{
		while (a->next != NULL)
		{
			if (a->nbr > a->next->nbr)
				return (false);
			a = a->next;
		}
	}
	return (true);
}
