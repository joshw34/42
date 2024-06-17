/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:12:38 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/17 11:53:20 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack_node *stack)
{
		t_stack_node	*temp;

		if (stack == NULL || stack->next == NULL)
			return;
		temp = stack->next;
		
}
