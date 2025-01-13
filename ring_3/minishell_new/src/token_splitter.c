/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:05:00 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/13 03:44:23 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	set_status(char c)
{
	if (c == 39)
		return (S_QUOTE);
	else if (c == 34)
		return (D_QUOTE);
	else
		return (NONE);
}

static	void	token_double_quote(char *input, int *i)
{
	int	j;

	j = *i;
	if (input[j + 1])
		j++;
	while (input[j] && input[j] != 34)
		j++;
	if (input[j + 1])
	{
		j++;
		while (input[j])
		{
			if (input[j] == ' ')
			{
				input[j] = 31;
				break ;
			}
			j++;
		}
	}
	if (input[j] == '\0')
		j--;
	*i = j;
}

static	void	token_single_quote(char *input, int *i)
{
	int	j;

	j = *i;
	if (input[j + 1])
		j++;
	while (input[j] && input[j] != 39)
		j++;
	if (input[j + 1])
	{
		j++;
		while (input[j])
		{
			if (input[j] == ' ')
			{
				input[j] = 31;
				break ;
			}
			j++;
		}
	}
	if (input[j] == '\0')
		j--;
	*i = j;
}

static	void	token_no_quote(char **input, int *i)
{
	int	j;
	int	spaces_to_add;

	j = *i;
	while ((*input)[j] && ((*input)[j] != 34 && (*input)[j] != 39))
	{
		spaces_to_add = separator_is_spaced(*input, j);
		//printf("%d\n", spaces_to_add);
		if (spaces_to_add != 0)
		{
			add_spaces(input, &j, (*input)[j], spaces_to_add);
			break ;
		}
		if ((*input)[j] == ' ')
		{
			(*input)[j] = 31;
			if ((*input)[j + 1] != ' ')
				break ;
		}
		j++;
	}
	if ((*input)[j] == '\0')
		j--;
	*i = j;
}

char	**split_tokens(char **input)
{
	int		i;
	int		q_status;

	i = 0;
	while ((*input)[i])
	{
		//printf("%d\n", i);
		q_status = set_status((*input)[i]);
		if (q_status == NONE)
			token_no_quote(input, &i);
		else if (q_status == S_QUOTE)
			token_single_quote(*input, &i);
		else if (q_status == D_QUOTE)
			token_double_quote(*input, &i);
		i++;
	}
	return (ft_split(*input, 31));
}
