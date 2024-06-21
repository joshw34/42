/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:35:57 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:54:11 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

bool	check_nbr_repeat(t_node *stack)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = stack;
	while (temp1 != NULL)
	{
		if (temp1->nbr > INT_MAX || temp1->nbr < INT_MIN)
			return (false);
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->nbr == temp2->nbr)
				return (false);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (true);
}

bool	check_format_error(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (ft_isdigit(input[i][j]) == 0 && input[i][j] != '+'
			&& input[i][j] != '-')
			return (false);
		if (input[i][j] == '+' || input[i][j] == '-')
			j++;
		while (input[i][j])
		{
			if (ft_isdigit(input[i][j]) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
