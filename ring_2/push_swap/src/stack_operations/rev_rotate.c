/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:14 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:56:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra_rrb(t_node **stack, char op, int reps)
{
	t_node	*first;
	t_node	*last;
	int		i;

	i = 0;
	while (i < reps)
	{
		if (*stack == NULL || (*stack)->next == NULL)
			return ;
		first = *stack;
		last = last_node(*stack);
		*stack = last;
		last->prev->next = NULL;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		if (op == 'a' || op == 'b')
			ft_printf("rr%c\n", op);
		i++;
	}
}

void	rrr(t_node **a, t_node **b, int reps)
{
	int	i;

	i = 0;
	while (i < reps)
	{
		rra_rrb(a, 'x', 1);
		rra_rrb(b, 'x', 1);
		ft_printf("rrr\n");
		i++;
	}
}
