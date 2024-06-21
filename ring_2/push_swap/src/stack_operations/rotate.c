/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:18 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:56:42 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra_rb(t_node **stack, char op, int reps)
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
		*stack = first->next;
		first->next->prev = NULL;
		last->next = first;
		first->next = NULL;
		first->prev = last;
		if (op == 'a' || op == 'b')
			ft_printf("r%c\n", op);
		i++;
	}
}

void	rr(t_node **a, t_node **b, int reps)
{
	int	i;

	i = 0;
	while (i < reps)
	{
		ra_rb(a, 'x', 1);
		ra_rb(b, 'x', 1);
		ft_printf("rr\n");
		i++;
	}
}
