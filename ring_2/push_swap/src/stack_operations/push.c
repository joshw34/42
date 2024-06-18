/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:11 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:12 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa_pb(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = temp;
		(*dest)->next = NULL;
	}
	else
	{
		temp->next = *dest;
		(*dest)->prev = temp;
		*dest = temp;
	}
}
