/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cngogang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:38 by cngogang          #+#    #+#             */
/*   Updated: 2025/01/21 15:53:22 by cngogang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	standard_behavior(int sigint)
{
	if (sigint == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_last_signal = 130;
	}
}

void	here_doc_open_behavior(int sig)
{


	///std_in_save =  dup(STDOUT_FILENO);
	if (sig == SIGINT)
	{
    	//write(STDOUT_FILENO, "Heredoc input aborted.\n", 24);
		//rl_on_new_line("", 0);
		//close(0);
		//printf("\n");
		//rl_on_new_line();
		//g_last_signal = -99;
		unlink(HERE_DOC_PATH);
		(void)sig;
		exit (1);
		//close(STDOUT_FILENO);
		//dup2(std_in_save, STDOUT_FILENO);
	}
}
