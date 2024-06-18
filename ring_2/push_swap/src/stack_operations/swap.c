/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:12:38 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:41:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa_sb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = second;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
}

void	ss(t_stack_node	**a, t_stack_node **b)
{
	sa_sb(a);
	sa_sb(b);
}
