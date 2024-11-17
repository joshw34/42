/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:58 by jwhitley          #+#    #+#             */
/*   Updated: 2024/11/17 22:52:33 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	*prompt;

	(void)ac;
	(void)av;
	while (1)
	{
		prompt = get_prompt();
		input = readline(prompt);
		free(prompt);
		read_input(input, env);
		add_history(input);
		free(input);
	}
	return (0);
}
