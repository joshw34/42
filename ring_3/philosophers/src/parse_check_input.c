/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:05:48 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/18 14:40:43 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_input	*parse_input(char **argv)
{
	t_input	*input;
	(void)argv;

	input = malloc(sizeof(t_input));
	if(!input)
		return (NULL);
	return (input);		
}
