/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:35 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:59:13 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*find_cheapest(t_node *stack)
{
	while (stack->cheapest == false)
		stack = stack->next;
	return (stack);
}

int	count_nodes(t_node *stack)
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

t_node	*last_node(t_node *node)
{
	if (node->next == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

static	t_node	*new_node(long nbr)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	return (new);
}

bool	add_node(t_node **stack, long nbr)
{
	t_node	*temp;
	t_node	*new;

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
