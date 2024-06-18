/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:41:47 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra_rb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = first->next;
	first->next->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra_rb(a);
	ra_rb(b);
}
