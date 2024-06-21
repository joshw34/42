/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_half.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:32 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:58:10 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	curr_index_top_half(t_node *stack)
{
	int		i;
	int		midpoint;
	t_node	*temp;

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
