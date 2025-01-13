/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:13:21 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 12:23:15 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* separator_is_spaced works out whether | < << > >> in the input string need 
   to have spaces inserted around them. it returns 0 for none, 1 for a space
   before, 2 for a space after or 3 for both */

static	int	separator_is_spaced_3(char *input, int i)
{
	int	counter;
	
	counter = 0;	
	if (input[i + 1] == '<')
	{
		if (!(i == 0 || input[i - 1] == ' '))
			counter += 1;
		if(!(input[i + 2] == '\0' || input[i + 2] == ' '))
			counter += 2;
	}
	else
	{
		if (!(i == 0 || input[i - 1] == ' '))
			counter += 1;
		if (!(input[i + 1] == '\0' || input[i + 1] == ' '))
			counter += 2;
	}
	return (counter);
}

static	int	separator_is_spaced_2(char *input, int i)
{
	int	counter;
	
	counter = 0;
	if (input[i + 1] == '>')
	{
		if (!(i == 0 || input[i - 1] == ' '))
			counter += 1;
		if(!(input[i + 2] == '\0' || input[i + 2] == ' '))
			counter += 2;
	}
	else
	{
		if (!(i == 0 || input[i - 1] == ' '))
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
		if (!(i == 0 || input[i - 1] == ' '))
			counter += 1;
		if (!(input[i + 1] == '\0' || input[i + 1] == ' '))
			counter += 2;
	}
	else if (input[i] == '>')
		counter = separator_is_spaced_2(input, i);
	else if (input[i] == '<')
		counter = separator_is_spaced_3(input, i);
	return (counter);
}
