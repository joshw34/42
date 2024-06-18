/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:35 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:36 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	count_nodes(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack_node	*last_node(t_stack_node *node)
{
	if (node->next == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

static	t_stack_node	*new_node(int nbr)
{
	t_stack_node	*new;

	new = ft_calloc(1, sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	return (new);
}

bool	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*temp;
	t_stack_node	*new;

	new = new_node(nbr);
	if (new == NULL)
		return (false);
	if (*stack == NULL)
		*stack = new;
	else
	{
		temp = last_node(*stack);
		temp->next = new;
		new->prev = temp;
	}
	return (true);
}
