/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:13:21 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 03:36:30 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* separator_is_spaced works out whether | < << > >> in the input string need 
   to have spaces inserted around them. it returns 0 for none, 1 for a space
   before, 2 for a space after or 3 for both */

void	add_spaces(char **input, int *index, char c, int new_spaces)
{
	char	*temp;
	int		i;
	int		j;
	int		new_index;

	i = 0;
	j = 0;
	temp = ft_calloc(1, ft_strlen(*input) + new_spaces + 1);
	while ((*input)[j])
	{
		if (((new_spaces == 1 || new_spaces == 3) && j == (*index))
			|| ((new_spaces == 2 || new_spaces == 3) && j == (*index + 1)))
		{
			printf("SPACE ADDED AT %d\n", i);
			temp[i] = 31;
			new_index = i;
			i++;
		}
		temp[i] = (*input)[j];
		i++;
		j++;
	}
	free(*input);
	*input = ft_strdup(temp);
	free(temp);
	printf("NEW INDEX %d\n", new_index);
	*index = new_index;
	(void)c;
}

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

static	bool	separator_is_spaced_2(char *input, int i)
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
	if (input[i] == '>')
		counter = separator_is_spaced_2(input, i);
	if (input[i] == '<')
		counter = separator_is_spaced_3(input, i);
	return (counter);
}
