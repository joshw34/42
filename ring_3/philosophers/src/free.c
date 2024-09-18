/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:46:06 by jwhitley          #+#    #+#             */
/*   Updated: 2024/09/18 11:54:10 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	input_error_exit(t_philo *input, char *message)
{
	if (input)
		free(input);
	if (message)
		printf("%s\n", message);
}