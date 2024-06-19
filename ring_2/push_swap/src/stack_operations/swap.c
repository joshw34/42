/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:12:38 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/19 15:21:18 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa_sb(t_node **stack, char op)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = second;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (op == 'a' || op == 'b')
		ft_printf("s%c\n", op);
}

void	ss(t_node	**a, t_node **b)
{
	sa_sb(a, 'x');
	sa_sb(b, 'x');
	ft_printf("ss\n");
}
