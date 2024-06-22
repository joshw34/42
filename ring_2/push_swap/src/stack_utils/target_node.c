/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:42 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/22 13:34:47 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	target_b_to_a(t_node *a, t_node *b)
{
	t_node	*temp_a;
	t_node	*result;
	t_node	*smallest;

	temp_a = a;
	result = NULL;
	smallest = NULL;
	while (temp_a != NULL)
	{
		if (temp_a->nbr > b->nbr && (result == NULL || temp_a->nbr < result->nbr))
			result = temp_a;
		if (smallest == NULL || temp_a->nbr < smallest->nbr)
			smallest = temp_a;
		temp_a = temp_a->next;
	}
	if (result == NULL)
		b->target_node = smallest;
	else
		b->target_node = result;
}

void	target_a_to_b(t_node *a, t_node *b)
{
	t_node	*temp_b;
	t_node	*result;
	t_node	*largest;

	temp_b = b;
	result = NULL;
	largest = NULL;
	while (a != NULL)
	{
		while (temp_b != NULL)
		{
			if ((temp_b->nbr < a->nbr) && (result == NULL
					|| temp_b->nbr > result->nbr))
				result = temp_b;
			if (largest == NULL || temp_b->nbr > largest->nbr)
				largest = temp_b;
			temp_b = temp_b->next;
		}
		a->target_node = result;
		if (result == NULL)
			a->target_node = largest;
		a = a->next;
		temp_b = b;
		result = NULL;
	}
}
