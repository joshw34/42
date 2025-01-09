/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:38 by cngogang          #+#    #+#             */
/*   Updated: 2025/01/09 17:37:50 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	action(int sigint)
{
	if (sigint == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	action_2(int sigint)
{
	if (sigint != SIGQUIT)
		printf("\n");	
}

void	action_rl(int sig)
{
	int	signal;

	signal = sig;
	exit (1);
}
