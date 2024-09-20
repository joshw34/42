/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:37 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/19 10:16:28 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_input	*input;

	input = parse_input(argv + 1);
	if (!input)
		return (1);
	else
		printf("n_philo: %d\nt_die: %d\nt_eat: %d\nt_sleep: %d\nn_eat: %d\n", input->n_philo, input->t_die, input->t_eat, input->t_sleep, input->n_eat);
	(void)argc;
}
