/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:09:51 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/19 14:54:29 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

bool	check_stacks(t_node *a, t_node *b)
{
	if (b != NULL)
		return (false);
	else
	{
		while (a->next != NULL)
		{
			if (a->nbr > a->next->nbr)
				return (false);
			a = a->next;
		}
	}
	return (true);
}
