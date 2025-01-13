/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:32:03 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 12:10:26 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	add_spaces_double(char **input, int *index, int new_spaces)
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
			|| ((new_spaces == 2 || new_spaces == 3) && j == (*index + 2)))
		{
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
	*index = new_index;
}

static	void	add_spaces_single(char **input, int *index, int new_spaces)
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
	*index = new_index;
}

void	add_spaces(char **input, int *index, int new_spaces)
{
	if ((*input)[*index] != (*input)[*index + 1])
		add_spaces_single(input, index, new_spaces);
	else
		add_spaces_double(input, index, new_spaces);
}
