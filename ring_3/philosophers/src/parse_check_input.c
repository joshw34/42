/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:05:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/19 11:05:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - 48);
		else
			return (0);
		i++;
	}
	return (result);
}

t_input	*parse_input(char **argv)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if(!input)
		return (NULL);
	input->n_philo = ft_atoi(argv[0]);
	input->t_die = ft_atoi(argv[1]);
	input->t_eat = ft_atoi(argv[2]);
	input->t_sleep = ft_atoi(argv[3]);
	if (argv[4])
		input->n_eat = ft_atoi(argv[4]);
	else
		input->n_eat = -1;
	if (input->n_philo == 0 || input->t_die == 0 || input->t_eat == 0
		|| input->t_sleep == 0 || input->n_eat == 0)
	{
		input_error_exit(input, "Error: Invalid Arguments\n");
		return (NULL);
	}
	return (input);
}
