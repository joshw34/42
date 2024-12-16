/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_processing_handling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:07:24 by cngogang          #+#    #+#             */
/*   Updated: 2024/12/16 12:07:26 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	waiting_sons_processes(t_cmd *command_array, int *status)
{
	
	while(command_array)
	{
		waitpid(command_array->pid, status, 0);
		command_array = command_array->next;
	}
}
