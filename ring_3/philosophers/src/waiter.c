/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:38:33 by jwhitley          #+#    #+#             */
/*   Updated: 2024/10/28 13:43:59 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	ask_waiter(t_data *data, int fork_1, int fork_2)
{
	bool	answer;

	pthread_mutex_lock(&data->waiter->fork_check_lock);
	if (data->waiter->fork_available[fork_1] == true
		&& data->waiter->fork_available[fork_2] == true)
	{
		answer = true;
		data->waiter->fork_available[fork_1] = false;
		data->waiter->fork_available[fork_2] = false;
	}
	else
		answer = false;
	pthread_mutex_unlock(&data->waiter->fork_check_lock);
	return (answer);
}

bool	tell_waiter(t_data *data, int fork_1, int fork_2)
{
	pthread_mutex_lock(&data->waiter->fork_check_lock);
	data->waiter->fork_available[fork_1] = true;
	data->waiter->fork_available[fork_2] = true;
	pthread_mutex_unlock(&data->waiter->fork_check_lock);
	return (true);
}
