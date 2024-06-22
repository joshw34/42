/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:09:43 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/22 19:54:56 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	full_sort(t_node **a, t_node **b)
{
	create_stack_b(a, b);
	push_a_to_b(a, b);
	largest_to_top(b);
	three_node_sort(a);
	push_b_to_a(a, b);
	smallest_to_top(a);
}

void	three_node_sort(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa_sb(stack, 'a');
		ra_rb(stack, 'a', 1);
	}
	else if (a > b && a < c)
		sa_sb(stack, 'a');
	else if (a < b && a > c)
		rra_rrb(stack, 'a', 1);
	else if (a > c && b < c)
		ra_rb(stack, 'a', 1);
	else if (a > b && b > c)
	{
		ra_rb(stack, 'a', 1);
		sa_sb(stack, 'a');
	}
}

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
