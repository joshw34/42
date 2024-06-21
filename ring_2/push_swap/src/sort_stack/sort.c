/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:09:43 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 19:03:44 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort(t_node **a, t_node **b)
{
	int	stack_len;

	if (check_stacks(*a, *b) == true)
		return ;
	stack_len = count_nodes(*a);
	if (stack_len == 2)
		sa_sb(a, 'a');
	else if (stack_len == 3)
		three_node_sort(a);
	else
		full_sort(a, b);
}
