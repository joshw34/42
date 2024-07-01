/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:11 by jwhitley          #+#    #+#             */
/*   Updated: 2024/07/01 13:41:58 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa_pb(t_node **src, t_node **dest, char to)
{
	t_node	*temp;

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
	ft_printf("p%c\n", to);
}
