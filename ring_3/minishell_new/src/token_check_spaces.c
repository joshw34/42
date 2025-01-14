/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:13:21 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/14 15:49:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* separator_is_spaced works out whether | < << > >> in the input string need 
   to have spaces inserted around them. it returns 0 for none, 1 for a space
   before, 2 for a space after or 3 for both.
   31 (unit sep) before i is treated as a space*/

static	int	separator_is_spaced_input(char *input, int i)
{
	int	counter;
	
	counter = 0;	
	if (input[i + 1] == '<')
	{
		if (!(i == 0 || input[i - 1] == ' ') || input[i - 1] == 31)
			counter += 1;
		if(!(input[i + 2] == '\0' || input[i + 2] == ' '))
			counter += 2;
	}
	else
	{
		if (!(i == 0 || input[i - 1] == ' ') || input[i - 1] == 31)
			counter += 1;
		if (!(input[i + 1] == '\0' || input[i + 1] == ' '))
			counter += 2;
	}
	return (counter);
}

static	int	separator_is_spaced_output(char *input, int i)
{
	int	counter;
	
	counter = 0;
	if (input[i + 1] == '>')
	{
		if (!(i == 0 || input[i - 1] == ' ' || input[i - 1] == 31))
			counter += 1;
		if(!(input[i + 2] == '\0' || input[i + 2] == ' '))
			counter += 2;
	}
	else
	{
		if (!(i == 0 || input[i - 1] == ' ' || input[i - 1] == 31))
			counter += 1;
		if (!(input[i + 1] == '\0' || input[i + 1] == ' '))
			counter += 2;
	}
	return (counter);
}

int	separator_is_spaced(char *input, int i)
{
	int	counter;

	counter = 0;
	if (input[i] == '|')
	{
		if (!(i == 0 || input[i - 1] == ' ' || input[i - 1] == 31))
			counter += 1;
		if (!(input[i + 1] == '\0' || input[i + 1] == ' '))
			counter += 2;
	}
	else if (input[i] == '>')
		counter = separator_is_spaced_output(input, i);
	else if (input[i] == '<')
		counter = separator_is_spaced_input(input, i);
	return (counter);
}
