/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tovetouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:33:47 by tovetouc          #+#    #+#             */
/*   Updated: 2024/03/03 18:33:57 by tovetouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_lines(char *str);

char	**fill_name_array(char *dict_str, char **name_arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dict_str[i] != '\0')
	{
		while (dict_str[i] >= 'a' && dict_str[i] <= 'z')
		{
			name_arr[j][k] = dict_str[i];
			k++;
			i++;
			if (dict_str[i] == '\n')
			{
				name_arr[j][k] = '\0';
				j++;
				k = 0;
			}
		}
		i++;
	}
	return (name_arr);
}

char	**fill_num_array(char *dict_str, char **num_arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dict_str[i] != '\0')
	{
		while (dict_str[i] >= '0' && dict_str[i] <= '9')
		{
			num_arr[j][k] = dict_str[i];
			k++;
			i++;
			if (dict_str[i] == ':')
			{
				num_arr[j][k] = '\0';
				j++;
				i++;
				k = 0;
			}
		}
		i++;
	}
	return (num_arr);
}

int	count_lines(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

char	**create_name_array(char *dict_str)
{
	int		lines;
	int		i;
	char	**name_arr;

	i = 0;
	lines = count_lines(dict_str);
	name_arr = malloc((lines * 100) * sizeof(char));
	while (i < lines)
	{
		name_arr[i] = (char *)malloc(50 * sizeof(char));
		i++;
	}
	fill_name_array(dict_str, name_arr);
	return (name_arr);
}

char	**create_num_array(char *dict_str)
{
	int		lines;
	int		i;
	char	**num_arr;

	i = 0;
	lines = count_lines(dict_str);
	num_arr = malloc((lines * 100) * sizeof(char));
	while (i < lines)
	{
		num_arr[i] = (char *)malloc(50 * sizeof(char));
		i++;
	}
	fill_num_array(dict_str, num_arr);
	return (num_arr);
}
