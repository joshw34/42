/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:46 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:57:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		start_pos;

	a = NULL;
	b = NULL;
	start_pos = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		start_pos = 0;
	}
	create_stack_a(&a, argv, start_pos);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}
