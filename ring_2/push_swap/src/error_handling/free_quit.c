/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:02 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/22 15:50:37 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	quit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	quit_error_free(t_node **stack, char **argv, int start)
{
	if (start == 0)
		free_argv(argv);
	if (*stack != NULL)
		free_stack(stack);
	quit_error();
}
