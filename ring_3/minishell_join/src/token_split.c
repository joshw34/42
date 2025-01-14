/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:40:21 by jwhitley          #+#    #+#             */
/*   Updated: 2025/01/10 15:16:08 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	void	trim_strings(char **arr)
{
	int	i;
	int	cut;

	i = 0;
	while (arr[i])
	{
		cut = find_next_string(arr[i], arr[i][0]);
		arr[i][cut] = '\0';
		i++;
	}
}

static	void	create_strings(char const *str, char **arr, int word_count)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (str[j] == ' ')
			j++;
		arr[i] = ft_strdup(str + j);
		j = j + find_next_string(str + j, str[j]);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		temp = ft_strtrim(arr[i], " ");
		free(arr[i]);
		arr[i] = temp;
		i++;
	}
}

static	size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	word_count;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (in_quotes(str, i) == false)
		{
			if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
				word_count++;
		}
		else
		{
			i = find_end_quote(str, i);
			word_count++;
		}
		i++;
	}
	return (word_count);
}

char	**token_split(char const *s, char c)
{
	size_t	words;
	char	**new;

	words = count_words(s, c);
	new = ft_calloc(words + 1, sizeof(char *));
	if (new == NULL)
		return (NULL);
	create_strings(s, new, words);
	trim_strings(new);
	return (new);
}
