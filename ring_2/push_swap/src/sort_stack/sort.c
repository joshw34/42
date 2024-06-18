/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:09:43 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 18:57:15 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	if (check_stacks(*a, *b) == true)
		return ;
	else
		create_stack_b(a, b);
	curr_index_top_half(*a);
	curr_index_top_half(*b);
	target_a_to_b(*a, *b);
	set_cost(*a, *b);
	print_stack(*a);
	ft_printf("\n\n");
	print_stack(*b);
}
