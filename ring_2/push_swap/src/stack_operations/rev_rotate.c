/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:14 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:42:25 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra_rrb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra_rrb(a);
	rra_rrb(b);
}
